//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 05/07/2014                 |
//+-------------------------------------+
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#define INF ~0U>>1
#define LLINF ~0ULL>>1
#define LL long long
#define uLL unsigned long long
#define uint unsigned int
#define D double
#define LD long double
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define dep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define pb push_back
#define mp make_pair
#define ins insert
#define ps push
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
inline void read(int &x)
{
	char ch;
	while ((ch=getchar()) && !(ch>='0' && ch<='9'));x=ch-'0';
	while ((ch=getchar()) && (ch>='0' && ch<='9')) x=x*10+ch-'0';
}
struct point
{
	int x,y;
	point() {}
	point(int _x,int _y) : x(_x),y(_y) {}
} ;
const int Mod=1000000009;
const int N=500000;
int n,m,W[N];
pair<int,int> val[N],sum[N];
struct lj{int l,r,f1,f2,c;}t[N<<2];
int Chen(int x,int y){return int((LL)x*(LL)y%(LL)Mod);}
int ADD(int x,int y) {return (x+y)%Mod;}
void build(int w,int l,int r)
{
	t[w].l=l;t[w].r=r;
	if (l==r) {t[w].c=W[l];return;}
	int mid=l+r>>1;
	build(w<<1,l,mid);build(w<<1|1,mid+1,r);
	t[w].c=ADD(t[w<<1].c,t[w<<1|1].c);
}
void push(int w)
{
	if (t[w].f1 || t[w].f2)
	{
		int l=w<<1;
		t[l].f1=ADD(t[l].f1,t[w].f1);
		t[l].f2=ADD(t[l].f2,t[w].f2);
		pair<int,int> c=sum[t[l].r-t[l].l+1];
		t[l].c=ADD(ADD(Chen(c.first,t[w].f1),Chen(c.second,t[w].f2)),t[l].c);
		int mid=t[w].l+t[w].r>>1;
		l|=1;
		int d,e;
		d=ADD(Chen(val[mid-t[w].l+2].first,t[w].f1),Chen(val[mid-t[w].l+2].second,t[w].f2));
		e=ADD(Chen(val[mid-t[w].l+3].first,t[w].f1),Chen(val[mid-t[w].l+3].second,t[w].f2));
		t[l].f1=ADD(t[l].f1,d);
		t[l].f2=ADD(t[l].f2,e);
		c=sum[t[l].r-t[l].l+1];
		t[l].c=ADD(ADD(Chen(c.first,d),Chen(c.second,e)),t[l].c);
		t[w].f1=t[w].f2=0;
	}
}
void change(int w,int l,int r,int p,int q)
{
	if (t[w].l==l && t[w].r==r)
	{
		pair<int,int> c=sum[r-l+1];
		t[w].c=ADD(t[w].c,ADD(Chen(c.first,p),Chen(c.second,q)));
		t[w].f1=ADD(t[w].f1,p);
		t[w].f2=ADD(t[w].f2,q);
		return;
	}
	push(w);
	int mid=t[w].l+t[w].r>>1;
	if (r<=mid) change(w<<1,l,r,p,q);
	else if (l>mid) change(w<<1|1,l,r,p,q);
	else
	{
		change(w<<1,l,mid,p,q);
		int d,e;
		d=ADD(Chen(val[mid-l+2].first,p),Chen(val[mid-l+2].second,q));
		e=ADD(Chen(val[mid-l+3].first,p),Chen(val[mid-l+3].second,q));
		change(w<<1|1,mid+1,r,d,e);
	}
	t[w].c=ADD(t[w<<1].c,t[w<<1|1].c);
}
int ask(int w,int l,int r)
{
	if (t[w].l==l && t[w].r==r) return t[w].c;
	push(w);
	int mid=t[w].l+t[w].r>>1;
	if (r<=mid) return ask(w<<1,l,r);
	else if (l>mid) return ask(w<<1|1,l,r);
	else return ADD(ask(w<<1,l,mid),ask(w<<1|1,mid+1,r));
}
int main()
{
	freopen("E.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&W[i]);
	sum[1]=mp(1,0);
	sum[2]=mp(1,1);
	val[1]=mp(1,0);
	val[2]=mp(0,1);
	rep(i,3,n) val[i]=mp(ADD(val[i-1].first,val[i-2].first),ADD(val[i-1].second,val[i-2].second)),
	           sum[i]=mp(ADD(val[i].first,sum[i-1].first),ADD(val[i].second,sum[i-1].second));
	build(1,1,n);
	int ty,x,y;
	rep(i,1,m)
	{
		scanf("%d",&ty);
		if (ty==1)
		{
			scanf("%d%d",&x,&y);
			change(1,x,y,1,1);
		}
		if (ty==2)
		{
			scanf("%d%d",&x,&y);
			printf("%d\n",ask(1,x,y));
		}
	}
}

