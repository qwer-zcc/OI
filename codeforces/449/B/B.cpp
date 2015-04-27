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
#define Chen(a,b,c) int((LL)(a)*(LL)(b)%(LL)(c))
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
const int N=310000;
vector<int> E[N],G[N];
LL dis[N];
int n,m,k,v[N],VIS[N],cnt[N],X[N],Y[N],Z[N],s[N],d[N];
queue<int> Q;
void spfa()
{
	dis[1]=0;
	rep(i,2,n) dis[i]=INF;
	Q.push(1);
	while (Q.size())
	{
		int x=Q.front();Q.pop();v[x]=0;
		for (int i=0;i<E[x].size();i++)
		if (dis[x]+G[x][i]<dis[E[x][i]])
		{
			dis[E[x][i]]=dis[x]+G[x][i];
			if (!v[E[x][i]]) v[E[x][i]]=1,Q.push(E[x][i]);
		}
	}
}
int main()
{
	freopen("B.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m)
	{
		scanf("%d%d%d",&X[i],&Y[i],&Z[i]);
		E[X[i]].pb(Y[i]);E[Y[i]].pb(X[i]);
		G[X[i]].pb(Z[i]);G[Y[i]].pb(Z[i]);
	}
	rep(i,1,k)
	{
		scanf("%d%d",&s[i],&d[i]);
		E[1].pb(s[i]),G[1].pb(d[i]);
		E[s[i]].pb(1),G[s[i]].pb(d[i]);
		cnt[s[i]]++;
	}
	spfa();
	rep(i,1,m)
	{
		if (dis[X[i]]+Z[i]==dis[Y[i]]) VIS[Y[i]]=1;
		if (dis[Y[i]]+Z[i]==dis[X[i]]) VIS[X[i]]=1;
	}
	int ans=0;
	rep(i,1,n) if (VIS[i]) ans+=cnt[i]; else ans+=max(cnt[i]-1,0);
	printf("%d\n",ans);
}

