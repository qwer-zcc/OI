//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 30/09/2014                 |
//+-------------------------------------+
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
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
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define Chen(a,b,c) int((LL)(a)*(LL)(b)%(LL)(c))
#define pb push_back
#define mp make_pair
#define ps push
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
vector<int> E[N];
int dfn[N],low[N],n,m,val[N],dep[N],ti,F[N],f[N][23],ok[N];
void dfs(int x)
{
	dfn[x]=low[x]=++ti;F[x]=1;
	for (int i=0;i<E[x].size();i++)
	if (!dfn[E[x][i]])
	{
		f[E[x][i]][0]=x;
		dfs(E[x][i]);
		low[x]=min(low[x],low[E[x][i]]);
		if (dfn[x]<low[E[x][i]]) ok[E[x][i]]=1;
	}
	else if (E[x][i]!=f[x][0]) low[x]=min(low[x],dfn[E[x][i]]);
}
void Dfs(int x,int c)
{
	dfn[x]=++ti;val[x]=c+ok[x];
	for (int i=0;i<E[x].size();i++)
	if (!dfn[E[x][i]]) dep[E[x][i]]=dep[x]+1,Dfs(E[x][i],val[x]);
}
void dp(){rep(j,1,20) rep(i,1,n) f[i][j]=f[f[i][j-1]][j-1];}
int lca(int x,int y)
{
    if (dep[x]<dep[y]) swap(x,y);
    drep(i,20,0) if (dep[f[x][i]]>=dep[y]) x=f[x][i];
    if (x==y) return x;
    drep(i,20,0) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
int main()
{
	//freopen("B.in","r",stdin);
	scanf("%d%d",&n,&m);int x,y;
	rep(i,1,m) scanf("%d%d",&x,&y),E[x].pb(y),E[y].pb(x);
	dfs(1);M(dfn);dep[1]=1;Dfs(1,0);dp();
	scanf("%d",&m);
	rep(i,1,m)
	{
		scanf("%d%d",&x,&y);int z=lca(x,y);
		printf("%d\n",val[x]+val[y]-val[z]*2);
	}
}

