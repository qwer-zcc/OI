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
const int N=1020;
vector<int> E[N];
queue<int> Q;
int n,dis[N],v[N],k,ans,w[N],dt[N][N];
void spfa(int w)
{
	rep(i,1,n) dis[i]=0;
	dis[w]=1;v[w]=1;
	Q.push(w);
	while (Q.size())
	{
		int x=Q.front();Q.pop();v[x]=0;
		for (int i=0;i<E[x].size();i++)
		if (dis[E[x][i]]<dis[x]+1)
		{
			dis[E[x][i]]=dis[x]+1;
			if (!v[E[x][i]]) v[E[x][i]]=1,Q.push(E[x][i]);
		}
	}
	rep(i,1,n) ans=max(ans,dis[i]);
}
int main()
{
	freopen("D.in","r",stdin);
	scanf("%d%d",&n,&k);
	rep(i,1,k)
	{
		rep(j,1,n) scanf("%d",&w[j]);
		rep(j,1,n-1) rep(k,j+1,n)
		dt[w[k]][w[j]]=1;
	}
	rep(i,1,n)
	rep(j,1,n)
	if (dt[i][j]==0 && i!=j) E[i].pb(j);
	rep(i,1,n) spfa(i);
	printf("%d\n",ans);
}

