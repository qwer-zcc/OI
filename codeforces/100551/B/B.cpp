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
const int N=220000;
struct dsu
{
	int n,fa[N];
	dsu(){}
	dsu(int _n) : n(_n) {rep(i,1,n) fa[i]=i;}
	int g_f(int x) {return fa[x]==x?x:fa[x]=g_f(fa[x]);}
	void link(int x,int y) {fa[g_f(x)]=g_f(y);}
}d1,d2;
struct lj{int x,y;}P[N];
vector<int> E[N];
int n,m,k,fa[N],dep[N],ans;
void link(int x,int y)
{
	int p=d1.g_f(x),q=d1.g_f(y);
	if (p==q) return;
	d1.link(p,q);
	E[x].pb(y);E[y].pb(x);
}
void dfs(int w,int Fa)
{
	fa[w]=Fa;dep[w]=dep[Fa]+1;
	for (int i=0;i<E[w].size();i++)
		if (E[w][i]!=Fa) dfs(E[w][i],w);
}
int main()
{
	//freopen("B.in","r",stdin);
	freopen("bridges.in","r",stdin);
	freopen("bridges.out","w",stdout);
	scanf("%d%d",&n,&m);d1=dsu(n);d2=dsu(n);
	rep(i,1,m) scanf("%d%d",&P[i].x,&P[i].y),link(P[i].x,P[i].y);
	scanf("%d",&k);
	rep(i,m+1,m+k) scanf("%d%d",&P[i].x,&P[i].y),link(P[i].x,P[i].y);
	rep(i,1,n) if (!dep[i]) dfs(i,0);d1=dsu(n);
	rep(i,1,m+k)
	{
		if (d1.g_f(P[i].x)!=d1.g_f(P[i].y)) d1.link(P[i].x,P[i].y),ans++;
		else
		{
			int x=d2.g_f(P[i].x),y=d2.g_f(P[i].y);
			while (x!=y)
			{
				if (dep[x]<dep[y]) swap(x,y);
				d2.link(x,d2.g_f(fa[x]));
				x=d2.g_f(x);
				ans--;
			}
		}
		if (i>m) printf("%d\n",ans);
	}
}
