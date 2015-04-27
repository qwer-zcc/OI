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
#define INF 1000000000
#define LL long long
#define uLL unsigned long long
#define uint unsigned int
#define D double
#define LD long double
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define dep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define Chen(a,b,c) int((LL)(a)*(LL)(b)%(LL)(c))
#define pb push_back
#define mp make_pair
#define ins insert
#define ps push
#define Pi M_PI
using namespace std;
//template<class T> inline T abs(T &a) {return a>0?a:-a;}
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
const int N=210000;
struct lj{int l,r;LL val,c,flag,lazy;}t[N<<2];
void build(int w,int l,int r)
{
	t[w].l=l;t[w].r=r;t[w].c=l;t[w].val=0;
	if (l==r) return;
	int mid=l+r>>1;
	build(w<<1,l,mid);build(w<<1|1,mid+1,r);
	if (t[w<<1].c==-1||t[w<<1|1].c==-1||t[w<<1].c!=t[w<<1|1].c) t[w].c=-1;
	else t[w].c=t[w<<1].c;
}
void push(int w)
{
	if (t[w].flag)
	{
		int l=w<<1;
		t[l].val+=t[w].flag*(LL)(t[l].r-t[l].l+1);
		t[l].flag+=t[w].flag;
		t[l].c=t[l].lazy=t[w].lazy;
		l|=1;
		t[l].val+=t[w].flag*(LL)(t[l].r-t[l].l+1);
		t[l].flag+=t[w].flag;
		t[l].c=t[l].lazy=t[w].lazy;
		t[w].flag=0;
		t[w].lazy=0;
	}
}
void change(int w,int l,int r,LL c)
{
	
	//printf("%d %d  %d  %d    %d %d\n",l,r,t[w].c,t[w].flag,t[w].l,t[w].r);
	push(w);
	if (l==t[w].l && r==t[w].r && t[w].c!=-1)
	{
		t[w].val+=(LL)abs(t[w].c-c)*(LL)(t[w].r-t[w].l+1);
		t[w].flag+=(LL)abs(t[w].c-c);
		t[w].lazy=c;
		t[w].c=c;
		return;
	}
	int mid=t[w].l+t[w].r>>1;
	if (r<=mid) change(w<<1,l,r,c);
	else if (l>mid) change(w<<1|1,l,r,c);
	else change(w<<1,l,mid,c),change(w<<1|1,mid+1,r,c);
	if (t[w<<1].c==-1||t[w<<1|1].c==-1||t[w<<1].c!=t[w<<1|1].c) t[w].c=-1;
	else t[w].c=t[w<<1].c;
	t[w].val=t[w<<1].val+t[w<<1|1].val;
	}
LL ask(int w,int l,int r)
{
	push(w);
	if (t[w].l==l && t[w].r==r) return t[w].val;
	int mid=t[w].l+t[w].r>>1;
	if (r<=mid) return ask(w<<1,l,r);
	else if (l>mid) return ask(w<<1|1,l,r);
	else return ask(w<<1,l,mid)+ask(w<<1|1,mid+1,r);
}
int main()
{
	freopen("C.in","r",stdin);
	int n,m,ty,l,r;
	scanf("%d%d",&n,&m);
	build(1,1,n);LL c;
	rep(i,1,m)
	{
		scanf("%d",&ty);
		if (ty==1)
		{
			scanf("%d%d%I64d",&l,&r,&c);
			change(1,l,r,c);
		}
		else
		{
			scanf("%d%d",&l,&r);
			printf("%I64d\n",ask(1,l,r));
		}
	}
}
