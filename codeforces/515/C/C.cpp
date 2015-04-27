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
#include <string>
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define INF int(1e8)
#define LL long long
#define D double
#define LD long double
#define pb push_back
#define mp make_pair
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
const int N=210000;
struct lj
{
	int l,r,best,best2;
	LL c;
}t[N<<2];
LL d[N],h[N],pre[N];
int n,m,vis[N];
LL calc(int i,int j)
{
	if (i>j) swap(i,j);
	return (h[i]+h[j])*2LL+pre[j]-pre[i];
}
void build(int w,int l,int r)
{
	t[w].l=l;t[w].r=r;
	if (l==r)
	{
		t[w].best=t[w].best2=l;
		t[w].c=0;
		return;
	}
	int mid=(l+r)>>1;
	build(w<<1,l,mid);build(w<<1|1,mid+1,r);
	//pair<int,LL> a=mp(t[w<<1].best,t[w<<1].c),b=mp(t[w<<1|1].best,t[w<<1|1].c);
	pair<pair<int,int>,LL> a=mp(mp(t[w<<1].best,t[w<<1].best2),t[w<<1].c),
		b=mp(mp(t[w<<1|1].best,t[w<<1|1].best2),t[w<<1|1].c);
		int best=b.first.first;LL c;
			if (h[a.first.first]*2LL+pre[b.first.first]-pre[a.first.first]>h[b.first.first]*2LL) best=a.first.first;
			int best2=a.first.second;
			if (h[b.first.second]*2LL+pre[b.first.second]-pre[a.first.second]>h[a.first.second]*2LL) best2=b.first.second;
		c=max(a.second,b.second);
		c=max(c,max(calc(a.first.first,b.first.first),calc(a.first.first,b.first.second)));
		c=max(c,max(calc(a.first.second,b.first.first),calc(a.first.second,b.first.second)));
	t[w].best=best;
	t[w].best2=best2;
	t[w].c=c;
		//return mp(mp(best,best2),c);
}
pair<pair<int,int>,LL> solve(int w,int l,int r,int ty)
{
	//printf("%d %d %d     %d %d    %d %d %lld    %d\n",w,t[w].l,t[w].r,l,r,t[w].best,t[w].best2,t[w].c,ty);
	if (t[w].l==l && t[w].r==r)
	{
		return mp(mp(t[w].best,t[w].best2),t[w].c);
		//if (ty==0) return mp(t[w].best,t[w].c);
		//else return mp(t[w].best2,t[w].c);
	}
	int mid=(t[w].l+t[w].r)>>1;
	if (r<=mid) return solve(w<<1,l,r,ty);
	else if (l>mid) return solve(w<<1|1,l,r,ty);
	else
	{
		pair<pair<int,int>,LL> a=solve(w<<1,l,mid,0),b=solve(w<<1|1,mid+1,r,1);
		int best=b.first.first;LL c;
			if (h[a.first.first]*2LL+pre[b.first.first]-pre[a.first.first]>h[b.first.first]*2LL) best=a.first.first;
			int best2=a.first.second;
			if (h[b.first.second]*2LL+pre[b.first.second]-pre[a.first.second]>h[a.first.second]*2LL) best2=b.first.second;
		c=max(a.second,b.second);
		c=max(c,max(calc(a.first.first,b.first.first),calc(a.first.first,b.first.second)));
		c=max(c,max(calc(a.first.second,b.first.first),calc(a.first.second,b.first.second)));
		return mp(mp(best,best2),c);
	}
}
void work(int l,int r)
{
	LL ans=0;
	//rep(i,l,r) vis[i]=1;
	rep(i,l,r) rep(j,l,r)
		if (i!=j && !vis[i] && !vis[j] && abs(i-j)<n/2)
		{
			ans=max(ans,calc(i,j));
			//printf("%d %d %lld\n",i,j,calc(i,j));
		}
	printf("      %lld\n",ans);
	//rep(i,l,r) vis[i]=0;
}
int main()
{
	//freopen("C.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%lld",&d[i]);
	rep(i,1,n) scanf("%lld",&h[i]);
	rep(i,n+1,n<<1) d[i]=d[i-n],h[i]=h[i-n];
	n<<=1;
	rep(i,1,n) pre[i]=pre[i-1]+d[i-1];
	build(1,1,n);
	int x,y;
	rep(i,1,m)
	{
		scanf("%d%d",&x,&y);
		if (x<=y)
		{
			//work(y+1,x-1+n/2);
			printf("%lld\n",solve(1,y+1,x-1+n/2,0).second);
		}
		else
		{
			//work(y+1,x-1);
			printf("%lld\n",solve(1,y+1,x-1,0).second);
		}
	}
}
