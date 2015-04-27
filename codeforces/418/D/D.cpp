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
void dfs(int x,int c)
{
	dep[x]=dep[c]+1;
	for (int i=0;i<E[x].size();i++)
	if (E[x][i]!=c) dfs(E[x][i],x);
}
void find(int x)
{
	for (int i=0;i<E[x].size();i++)
	if (E[x][i]!=c)
	{
		dfs(E[x][i],x);
		if (vis[E[x][i]]) vis[x]=1;
	}
}
void Build()
{
	dfs(1,0);
	int p=0,Max=0;
	rep(i,1,n)
	if (dis[i]>Max) Max=dis[i],p=i;
	dfs(il,0);
	int q=0;Max=0;
	rep(i,1,n)
	if (dis[i]>Max) Max=dis[i],q=i;
	Begin=p;End=q;
	vis[End]=1;
	find(Begin);
}
int main()
{
	scanf("%d",&n);
	rep(i,1,n-1) scanf("%d%d",&x,&y),E[x].pb(y),E[y].pb(x);
	Build();
	scanf("%d",&m);
	rep(i,1,m)
	{
		scanf("%d%d",&x,&y);
		solve(x,y);
	}
}

