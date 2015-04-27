#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define INF int(1e9)
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define Pi M_PI
#define clr(a) memset(a,0,sizeof(a));
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
const int N=120000;
struct lj{int l,r,c;}t[N<<2];
int ans,n,p[N],d[N],L[N],R[N];
void build(int w,int l,int r)
{
	t[w].l=l;t[w].r=r;
	if (l==r) {t[w].c=L[l]>0?(p[l]-L[l]):(int)2e9;return;}
	int mid=(l+r)>>1;
	build(w<<1,l,mid);build(w<<1|1,mid+1,r);
	t[w].c=min(t[w<<1].c,t[w<<1|1].c);
}
int find(int w,int c)
{
	if (t[w].l==t[w].r) return t[w].l;
	if (t[w<<1].c<=c) return find(w<<1,c);
	return find(w<<1|1,c);
}
void add(int w,int l,int c)
{
	if (t[w].l==t[w].r) {t[w].c=c;return;}
	int mid=(t[w].l+t[w].r)>>1;
	if (l<=mid) add(w<<1,l,c);
	else add(w<<1|1,l,c);
	t[w].c=min(t[w<<1].c,t[w<<1|1].c);
}
int ask(int w,int l,int r,int c)
{
	if (l==t[w].l && r==t[w].r)
	{
		if (t[w].c>c) return -1;
		return find(w,c);
	}
	int mid=(t[w].l+t[w].r)>>1;
	if (r<=mid) return ask(w<<1,l,r,c);
	else if (l>mid) return ask(w<<1|1,l,r,c);
	else
	{
		int t=ask(w<<1,l,mid,c);
		if (t!=-1) return t;
		return ask(w<<1|1,mid+1,r,c);
	}
}
void build2(int w,int l,int r)
{
	t[w].l=l;t[w].r=r;
	if (l==r) {t[w].c=L[l]>0?(p[l]+R[l]):(int)2e9;return;}
	int mid=(l+r)>>1;
	build2(w<<1,l,mid);build2(w<<1|1,mid+1,r);
	t[w].c=max(t[w<<1].c,t[w<<1|1].c);
}
int find2(int w,int c)
{
	if (t[w].l==t[w].r) return t[w].l;
	if (t[w<<1|1].c>=c) return find2(w<<1|1,c);
	return find2(w<<1,c);
}
void add2(int w,int l,int c)
{
	if (t[w].l==t[w].r) {t[w].c=c;return;}
	int mid=(t[w].l+t[w].r)>>1;
	if (l<=mid) add2(w<<1,l,c);
	else add2(w<<1|1,l,c);
	t[w].c=max(t[w<<1].c,t[w<<1|1].c);
}
int ask2(int w,int l,int r,int c)
{
	if (l==t[w].l && r==t[w].r)
	{
		if (t[w].c<c) return -1;
		return find2(w,c);
	}
	int mid=(t[w].l+t[w].r)>>1;
	if (r<=mid) return ask2(w<<1,l,r,c);
	else if (l>mid) return ask2(w<<1|1,l,r,c);
	else
	{
		int t=ask2(w<<1|1,mid+1,r,c);
		if (t!=-1) return t;
		return ask2(w<<1,l,mid,c);
	}
}
int main()
{
	scanf("%d",&n);
	rep(i,0,n+1) scanf("%d",&p[i]);
	rep(i,1,n) scanf("%d",&d[i]),d[i]<<=1;
	R[0]=INF;
	build2(1,0,n);
	rep(i,1,n+1)
	{
		R[i]=-INF;
		int c=ask2(1,0,i-1,p[i]);
		if (c!=-1 && p[i]-d[i]<=p[c]) R[i]=d[i]-p[i]+p[c];
		add2(1,i,p[i]+R[i]);
	}
	L[n+1]=INF;
	build(1,1,n+1);
	drep(i,n,0)
	{
		L[i]=-INF;
		int c=ask(1,i+1,n+1,p[i]);
		if (c!=-1 && p[c]-p[i]<=d[i]) L[i]=d[i]-(p[c]-p[i]);
		add(1,i,p[i]-L[i]);
	}
	ans=p[n+1];
	rep(i,1,n)
		if (L[i]!=-INF && R[i]!=-INF)
		{
			int c=(d[i]<<1)-L[i]-R[i];
			if (c<=d[i]) ans=0;
			else ans=min(ans,c);
		}
	build(1,1,n+1);
	rep(i,0,n)
		if (R[i]>0)
		{
			int c=ask(1,i+1,n+1,p[i]+R[i]);
			if (c==-1) continue;
			ans=min(ans,p[c]-p[i]);
		}
	printf("%.1lf\n",ans/2.);
}
