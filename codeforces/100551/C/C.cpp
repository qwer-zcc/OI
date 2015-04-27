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
#include <ctime>
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
struct lj{int x,y;}P[N];
vector<int> E[N];
stack<int> St;
vector<int> all;
int dep[N],fa[N][22],L[N],R[N],par[N],vis[N],n,m,ti;
struct dsu
{
	int fa[N];
	int g_f(int x) {return fa[x]==x?x:fa[x]=g_f(fa[x]);}
	void link(int x,int y) {fa[g_f(x)]=g_f(y);}
}d;
int lca(int x,int y)
{
	if (dep[x]>dep[y]) swap(x,y);
	drep(i,20,0)
		if (dep[fa[y][i]]>=dep[x]) y=fa[y][i];
	if (x==y) return x;
	drep(i,20,0)
		if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void dfs(int w,int Fa)
{
	L[w]=++ti;
	fa[w][0]=Fa;dep[w]=dep[Fa]+1;
	for (int i=0;i<E[w].size();i++)
		if (E[w][i]!=Fa) dfs(E[w][i],w);
	R[w]=ti;
}
inline int cmp(const int &a,const int &b) {return L[a]<L[b];}
void work()
{
	all.clear();int c;
	scanf("%d",&c);
	rep(i,1,c)
	{
		scanf("%d%d",&P[i].x,&P[i].y);
		if (!vis[P[i].x]) all.pb(P[i].x);
		vis[P[i].x]=1;
		if (!vis[P[i].y]) all.pb(P[i].y);
		vis[P[i].y]=1;
	}
	for (int i=0;i<all.size();i++) vis[all[i]]=0,par[all[i]]=0;
	sort(all.begin(),all.end(),cmp);
	while (St.size()) St.pop();
	for (int i=0;i<all.size();i++)
	{
		d.fa[all[i]]=all[i];
		if (!St.size()) {St.push(all[i]);continue;}
		int u=St.top(),v=all[i];
		if (!(L[v]>=L[u] && L[v]<=R[u]))
		{
			int p=lca(u,v);d.fa[p]=p;
			while (L[u]>=L[p] && L[u]<=R[p])
			{
				St.pop();
				if (!St.size()) {par[u]=p;break;}
				int q=St.top();
				if (L[q]>=L[p] && L[q]<=R[p]) par[u]=q,u=q;
				else {par[u]=p,par[p]=q;break;}
			}
			St.push(p);St.push(v);par[v]=p;
		}
		else
		{
			par[v]=u;St.push(v);
		}
	}
	int ans=n-1;
	rep(i,1,c)
	{
		int x=d.g_f(P[i].x),y=d.g_f(P[i].y);
		while (x!=y)
		{
			if (dep[x]<dep[y]) swap(x,y);
			ans-=dep[x]-dep[par[x]];
			d.link(x,d.g_f(par[x]));
			x=d.g_f(x);
		}
	}
	printf("%d\n",ans);
}
int main()
{
	//freopen("C.in","r",stdin);
	freopen("bridges2.in","r",stdin);
	freopen("bridges2.out","w",stdout);
	scanf("%d%d",&n,&m);int x;
	rep(i,2,n) scanf("%d",&x),E[x].pb(i);
	dfs(1,0);
	rep(j,1,20) rep(i,1,n) fa[i][j]=fa[fa[i][j-1]][j-1];
	rep(i,1,m) work();
}
