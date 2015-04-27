//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 14/08/2014                 |
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
const int NN=10000000;
stack<int> Sta;
vector<int> F[N],E[N],T;
int pl,P[N],rt,n,dep[N],vis[N],head[NN],next[NN],f[N][20],to[NN],val[N],Val[N],pri[N][10],TIM,num[N][10],L[N],R[N],cnt,ti;
int S[N],sl;
void dfs(int x,int Fa)
{
	L[x]=++ti;f[x][0]=Fa;dep[x]=dep[Fa]+1;
	for (int i=0;i<E[x].size();i++)
	if (E[x][i]!=Fa) dfs(E[x][i],x);
	R[x]=ti;
}
void dp() {rep(j,1,18) rep(i,1,n) f[i][j]=f[f[i][j-1]][j-1];}
int lca(int x,int y)
{
    if (dep[x]<dep[y]) swap(x,y);
    drep(i,18,0)
    if (dep[f[x][i]]>=dep[y]) x=f[x][i];
    if (x==y) return x;
    drep(i,18,0)
    if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
void add(int x,int y)
{
	if (vis[x]!=TIM) head[x]=0;
	vis[x]=TIM;
	to[++cnt]=y;next[cnt]=head[x];head[x]=cnt;
}
void solve(vector<int> T)
{
	sl=0;
	for (int i=0;i<T.size();i++)
	{
		if (!sl) {S[++sl]=T[i];continue;}
		int x=S[sl];
		if (L[T[i]]>=L[x] && L[T[i]]<=R[x]) S[++sl]=T[i];
		else
		{
			int ok=0;
			while (sl>=1)
			{
				int p=lca(S[sl],T[i]);
				if (dep[p]<dep[S[sl-1]])
					add(S[sl-1],S[sl]),sl--;
				else if (dep[p]==dep[S[sl-1]])
					{add(S[sl-1],S[sl]);sl--;S[++sl]=T[i];ok=1;break;}
				else if (dep[p]>dep[S[sl-1]])
					{add(p,S[sl]);sl--;S[++sl]=p;S[++sl]=T[i];ok=1;break;}
			}
		}
	}
	while (sl>=2)
	{
		add(S[sl-1],S[sl]);
		sl--;
	}
	rt=S[1];
}
void Dfs(int x,int c)
{
	rep(i,0,pri[x][0])
	if (pri[x][i]==c)
	{
		if (Sta.size())
		{
			num[x][i]=Val[Sta.top()];
			if (Val[x]>Val[Sta.top()]) Sta.push(x);
		}
		else Sta.push(x);
	}
	for (int p=head[x];p;p=next[p]) Dfs(to[p],c);
	if (Sta.size()) if (Sta.top()==x) Sta.pop();
}
int main()
{
	freopen("E.in","r",stdin);
	int m,x,y;
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&val[i]),Val[i]=val[i];
	rep(i,1,n-1) scanf("%d%d",&x,&y),E[x].pb(y),E[y].pb(x);
	dfs(1,0);dp();
	P[++pl]=2;
	rep(i,3,2000)
	{
		int flag=0;
		rep(j,2,int(sqrt(i)))
		if (i%j==0) flag=1;
		if (!flag) P[++pl]=i;
	}
	rep(i,1,n)
	{
		rep(j,1,pl)
		if (val[i]%P[j]==0)
		{
			F[j].pb(i);
			pri[i][++pri[i][0]]=j;
			while (val[i]%P[j]==0) val[i]/=P[j];
		}
		if (val[i])
		{
			P[++pl]=val[i];
			F[pl].pb(i);
			pri[i][++pri[i][0]]=pl;
		}
	}
	rep(i,1,pl)
	if (F[i].size()>=2)
	{
		T.clear();
		for (int j=0;j<F[i].size();j++) T.pb(F[i][j]);
		++TIM;
		solve(T);
		Dfs(rt,i);
	}
	int ty;
	rep(i,1,m)
	{
		scanf("%d",&ty);
		if (ty==1)
		{
			scanf("%d",&x);int ans=0;
			rep(j,1,pri[x][0]) ans=max(ans,num[x][j]);
			if (ans==0) puts("-1");else printf("%d\n",ans);
		}
		else
		{
			scanf("%d%d",&x,&y);
			val[x]=y;pri[x][0]=0;Val[x]=y;
			rep(j,1,pl)
			if (y%P[j]==0)
			{
				F[j].pb(x);
				pri[x][++pri[x][0]]=j;
				while (val[x]%P[j]==0) val[x]/=P[j];
			}
			if (val[x])
			{
				P[++pl]=val[x];
				F[pl].pb(x);
				pri[x][++pri[x][0]]=pl;
			}
			rep(j,1,pri[x][0])
			{
				T.clear();
				for (int k=0;k<F[pri[x][j]].size();k++) T.pb(F[pri[x][j]][k]);
				++TIM;
				solve(T);
				Dfs(rt,pri[x][j]);
			}
		}
	}
}

