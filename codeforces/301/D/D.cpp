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
const int N=300000;
vector<int> E[N],F[N],G[N];
int t[N],pos[N],w[N],n,m;
LL ans[N];
LL ask(int x){LL ans=0;for(int i=x;i;i-=i&(-i)) ans+=(LL)t[i];return ans;}
void add(int x,int c){for (int i=x;i<=n;i+=i&(-i)) t[i]+=c;}
int main()
{
	scanf("%d%d",&n,&m);int x,y;
	rep(i,1,n) scanf("%d",&w[i]),pos[w[i]]=i;
	rep(i,1,n) rep(j,1,n/w[i]) if (pos[w[i]*j]>=i) E[i].pb(pos[w[i]*j]);
	else E[pos[w[i]*j]].pb(i);
	rep(i,1,n) for(int j=0;j<E[i].size();j++) add(E[i][j],1);
	rep(i,1,m) scanf("%d%d",&x,&y),F[x].pb(y),G[x].pb(i);
	rep(i,1,n)
	{
		for (int j=0;j<E[i-1].size();j++) add(E[i-1][j],-1);
		for (int j=0;j<F[i].size();j++) ans[G[i][j]]=ask(F[i][j]);
	}
	rep(i,1,m) printf("%lld\n",ans[i]);
}

