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
const int N=111;
struct lj{int n,can;LL val,g;}P[N];
int n,m;LL b;
LL dp[1<<21],ans=INF;
inline int cmp(const lj &a,const lj &b) {return a.g<b.g;}
int main()
{
	printf("%lld\n",LLINF);
	scanf("%d%d%lld",&n,&m,&b);int x;
	rep(i,1,n)
	{
		scanf("%lld%lld%d",&P[i].val,&P[i].g,&P[i].n);
		rep(j,1,P[i].n) scanf("%d",&x),P[i].can|=1<<(x-1);
	}
	sort(P+1,P+n+1,cmp);
	rep(i,1,(1<<m)-1) dp[i]=INF;
	rep(i,1,n)
	{
		rep(j,0,(1<<m)-1) dp[j|P[i].can]=min(dp[j|P[i].can],dp[j]+P[i].val);
		ans=min(ans,dp[(1<<m)-1]+P[i].g*b);
	}
	printf("%lld\n",ans>=INF?-1:ans);
}
