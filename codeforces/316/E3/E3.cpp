//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 14/08/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF ~0U>>1
#define LLINF ~0ULL>>1
#define LL long long
#define uLL unsigned long long
#define uint unsigned int
#define D double
#define LD long double
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define pb push_back
#define mp make_pair
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
template<class T> void read(T &x)
{
    char ch;
    while ((ch=getchar()) && !isdigit(ch));x=ch-'0';
    while ((ch=getchar()) && isdigit(ch)) x=x*10+ch-'0';
}
struct point
{
    int x,y;
    point() {}
    point(int _x,int _y) : x(_x),y(_y) {}
} ;
const int N=310000,Mod=1000000000;
struct lj{int l,r,c1,c2,flag;}t[N<<2];
pair<int,int> sum[N],val[N];
int Val[N],n,m;
int ADD(int a,int b){return int(((LL)a+(LL)b+(LL)Mod)%(LL)Mod);}
int Chen(int a,int b){return int((LL)a*(LL)b%(LL)Mod);}
void Add(int w,int c)
{
	t[w].flag=ADD(t[w].flag,c);
	pair<int,int> d=sum[t[w].r-t[w].l+1];
	t[w].c1=ADD(t[w].c1,Chen(ADD(d.first,d.second),c));
	t[w].c2=ADD(t[w].c2,Chen(ADD(d.first,d.second*2),c));
}
void push(int w)
{
	if (t[w].flag)
	{
		if (t[w<<1].l) Add(w<<1,t[w].flag);
		if (t[w<<1|1].l) Add(w<<1|1,t[w].flag);
		t[w].flag=0;
	}
}
int Calc(int w,int k)
{
	pair<int,int> d=val[k];
	return ADD(Chen(t[w].c1,d.first),Chen(t[w].c2,d.second));
}
void update(int w)
{
	t[w].c1=ADD(t[w<<1].c1  ,  Calc(w<<1|1,t[w<<1|1].l-t[w<<1].l+1) );
	t[w].c2=ADD(t[w<<1].c2  ,  Calc(w<<1|1,t[w<<1|1].l-t[w<<1].l+2) );
}
void build(int w,int l,int r)
{
	t[w].l=l;t[w].r=r;
	if (l==r){t[w].c1=t[w].c2=Val[l];return;}
	int mid=l+r>>1;
	build(w<<1,l,mid);build(w<<1|1,mid+1,r); 
	update(w);
}
void change(int w,int l,int c)
{
	push(w);
	if (t[w].l==t[w].r)
	{
		t[w].c1=t[w].c2=c;
		return;
	}
	int mid=t[w].l+t[w].r>>1;
	if (l<=mid) change(w<<1,l,c);
	else if (l>mid) change(w<<1|1,l,c);
	update(w);
}
void add(int w,int l,int r,int c)
{
	push(w);
	if (t[w].l==l && t[w].r==r) {Add(w,c);return;}
	int mid=t[w].l+t[w].r>>1;
	if (r<=mid) add(w<<1,l,r,c);
	else if (l>mid) add(w<<1|1,l,r,c);
	else add(w<<1,l,mid,c),add(w<<1|1,mid+1,r,c);
	update(w);
}
int ask(int w,int l,int r,int k)
{
	push(w);
	if (t[w].l==l && t[w].r==r) return Calc(w,k);
	int mid=t[w].l+t[w].r>>1;
	if (r<=mid) return ask(w<<1,l,r,k);
	else if (l>mid) return ask(w<<1|1,l,r,k);
	else return ADD(ask(w<<1,l,mid,k),ask(w<<1|1,mid+1,r,k+t[w<<1|1].l-l));
}
pair<int,int> operator+(pair<int,int> a,pair<int,int> b)
{
	return mp(ADD(a.first,b.first),ADD(a.second,b.second));
}
int main()
{
	//freopen("E3.in","r",stdin);
	scanf("%d%d",&n,&m);int ty,x,y,z;
	rep(i,1,n) scanf("%d",&Val[i]);
	val[1]=mp(1,0);val[2]=mp(0,1);
	sum[1]=mp(1,0);sum[2]=mp(1,1);
	rep(i,3,300000) val[i]=val[i-1]+val[i-2],sum[i]=sum[i-1]+val[i];
	build(1,1,n);
	rep(i,1,m)
	{
		scanf("%d",&ty);
		if (ty==1)
		{
			scanf("%d%d",&x,&y);
			change(1,x,y);
		}
		else if (ty==2)
		{
			scanf("%d%d",&x,&y);
			printf("%d\n",ask(1,x,y,1));
		}
		else
		{
			scanf("%d%d%d",&x,&y,&z);
			add(1,x,y,z);
		}
	}
}

