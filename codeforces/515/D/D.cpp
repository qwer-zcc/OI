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
vector<int> E[N];
vector<LL> F[N];
LL dis[N],s1[N],s2[N],len[N],f[N][24];
int cnt,n,m,g[N][24],ans,rd[N],can[N],Del[N];
void dfs(int w,int Fa)
{
	//printf("%d %d\n",w,Fa);
	for (int i=0;i<E[w].size();i++)
	if (E[w][i]!=Fa)
	{
		dfs(E[w][i],w);
		dis[w]=max(dis[w],dis[E[w][i]]+F[w][i]);
	}
}
void dfs2(int w,int Fa,LL pre)
{
	dis[w]=max(dis[w],pre);
	
	if (!E[w].size()) return;
	if (E[w].size()==1) {if (E[w][0]!=Fa) dfs2(E[w][0],w,pre+F[w][0]);return;}
	int l=cnt+1,r;
	for (int i=0;i<E[w].size();i++)
		if (E[w][i]!=Fa) len[++cnt]=dis[E[w][i]]+F[w][i];
		else len[++cnt]=0;
	r=cnt;
	s1[l]=len[l];
	rep(i,l+1,r) s1[i]=max(s1[i-1],len[i]);
	s2[r]=len[r];
	drep(i,r-1,l) s2[i]=max(s2[i+1],len[i]);
	
	for (int i=0;i<E[w].size();i++)
		if (E[w][i]!=Fa)
		{
			if (i==0) dfs2(E[w][i],w,max(s2[l+1],pre)+F[w][i]);
			else if (i==E[w].size()-1) dfs2(E[w][i],w,max(s1[r-1],pre)+F[w][i]);
			else dfs2(E[w][i],w,max(max(s1[l+i-1],s2[l+i+1]),pre)+F[w][i]);
		}
}
void dfs3(int w,int Fa)
{
	for (int i=0;i<E[w].size();i++)
		if (E[w][i]!=Fa)
		{
			f[E[w][i]][0]=dis[E[w][i]]-dis[w];
			g[E[w][i]][0]=w;
			dfs3(E[w][i],w);
		}
}
void dp()
{
	rep(j,1,22) rep(i,1,n) f[i][j]=f[i][j-1]+f[g[i][j-1]][j-1],g[i][j]=g[g[i][j-1]][j-1];
}
void solve(LL L)
{
	rep(i,1,n) Del[i]=0;
	rep(i,1,n)
	{
		int x=i;LL re=L;
		drep(j,22,0)
			if (re>=f[x][j]) re-=f[x][j],x=g[x][j];
		x=g[x][0];
		Del[x]++;
	}
}
void dfs4(int w,int Fa)
{
	can[w]=1;
	for (int i=0;i<E[w].size();i++)
		if (E[w][i]!=Fa)
		{
			dfs4(E[w][i],w);
			can[w]+=can[E[w][i]];
		}
	can[w]-=Del[w];
	ans=max(ans,can[w]);
}
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d",&n);int x,y;LL L,z;
	rep(i,1,n-1) scanf("%d%d%lld",&x,&y,&z),E[x].pb(y),E[y].pb(x),F[x].pb(z),F[y].pb(z),rd[x]++,rd[y]++;
	rep(i,1,n)
		if (rd[i]==1)
		{
			dfs(i,0);
			dfs2(i,0,0);
			break;
		}
	LL Min=(LL)(1e18);int il=0;
	rep(i,1,n)
		if (dis[i]<Min) Min=dis[i],il=i;
	dfs3(il,0);dp();
	scanf("%d",&m);
	rep(i,1,m)
	{
		scanf("%lld",&L);ans=0;
		solve(L);
		dfs4(il,0);
		printf("%d\n",ans);
	}
}
