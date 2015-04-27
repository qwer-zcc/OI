//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 12/10/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF (~0U>>1)-3
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
const int N=120000;
struct lj{LL x;int c;}P[N];
LL h,p,dis[N];
int n,m,k,vis[N],ty,x,y,v[N];
const LL inf=(LL)(1e18)+1000LL;
struct Cmp
{
	bool operator ()(pair<int,int> a,pair<int,int> b)
	{
		return a.first>b.first || (a.first==b.first && a.second<b.second);
	}
};
set<pair<int,int>,Cmp > S;
int cmp(const lj &a,const lj &b){return a.x<b.x;}
queue<int> Q;
void work(LL p)
{
	rep(i,0,k-1) Q.push(i),v[i]=1;
	while (Q.size())
	{
		int x=Q.front();Q.pop();v[x]=0;
		int y=int(((LL)p+(LL)x)%(LL)k);
		if (dis[x]!=inf && dis[y]>dis[x]+p)
		{
			dis[y]=dis[x]+p;
			if (!v[y]) v[y]=1,Q.push(y);
		}
	}
	rep(i,1,n)
	if (dis[int(P[i].x%(LL)k)]<=P[i].x && !vis[i]) vis[i]=1,S.insert(mp(P[i].c,i));
}
int main()
{
	//freopen("C.in","r",stdin);
	scanf("%I64d%d%d%d",&h,&n,&m,&k);
	rep(i,1,n) scanf("%I64d%d",&P[i].x,&P[i].c);
	rep(i,0,k-1) dis[i]=inf;
	dis[1]=1;work(k);
	rep(i,1,m)
	{
		scanf("%d",&ty);
		if (ty==3)
		{
			if (S.size()) printf("%d\n",S.begin()->first),S.erase(S.begin());
			else puts("0");
		}
		else if (ty==2)
		{
			scanf("%d%d",&x,&y);
			if (vis[x]) S.erase(mp(P[x].c,x));
			P[x].c-=y;
			if (vis[x]) S.insert(mp(P[x].c,x));
		}
		else if (ty==1) scanf("%I64d",&p),work(p);
	}
}

