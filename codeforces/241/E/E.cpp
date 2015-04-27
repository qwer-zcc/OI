//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 12/10/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF ((~0U>>1)-3)
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
const int N=10000;
vector<int> E[N],EE[N],F[N];
int vis1[N],vis2[N],vis[N],dis[N],n,m,X[N],Y[N],cnt[N];
void dfs1(int w)
{
	vis1[w]=1;
	for (int i=0;i<E[w].size();i++)
	if (!vis1[E[w][i]]) dfs1(E[w][i]);
}
void dfs2(int w)
{
	vis2[w]=1;
	for (int i=0;i<EE[w].size();i++)
	if (!vis2[EE[w][i]]) dfs2(EE[w][i]);
}
queue<int> Q;
int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,m) scanf("%d%d",&X[i],&Y[i]),E[X[i]].pb(Y[i]),EE[Y[i]].pb(X[i]);
	dfs1(1);dfs2(n);
	rep(i,1,n) E[i].clear();
	rep(i,1,m)
	if (vis1[X[i]] && vis2[Y[i]])
	{
		E[X[i]].pb(Y[i]);
		F[X[i]].pb(2);
		E[Y[i]].pb(X[i]);
		F[Y[i]].pb(-1);
	}
	Q.push(1);dis[1]=0;
	rep(i,2,n) dis[i]=INF;
	while (Q.size())
	{
		int x=Q.front();Q.pop();vis[x]=0;cnt[x]++;
		if (cnt[x]>1000) {puts("No");return 0;}
		for (int i=0;i<E[x].size();i++)
		if (dis[x]+F[x][i]<dis[E[x][i]])
		{
			dis[E[x][i]]=dis[x]+F[x][i];
			if (!vis[E[x][i]]) Q.push(E[x][i]),vis[E[x][i]]=1;
		}
	}
	puts("Yes");
	rep(i,1,m) if (vis1[X[i]] && vis2[Y[i]]) printf("%d\n",dis[Y[i]]-dis[X[i]]);
	else puts("1");
}

