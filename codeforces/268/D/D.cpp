//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 12/10/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF (~0U>>1)-3
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
const int Mod=1000000009;
int n,h;
int dp[1010][31][31][31][2],ans;
void add(int &a,int b) {a=(a+b)%Mod;}
int main()
{
	scanf("%d%d",&n,&h);
	dp[0][h][h][h][1]=1;
	rep(i,0,n-1)
	rep(p1,0,h) rep(p2,0,h) rep(p3,0,h) rep(p4,0,1)
	if (dp[i][p1][p2][p3])
	{
		add(dp[i+1][p4?h:0][max(p2-1,0)][max(p3-1,0)][p1>1],dp[i][p1][p2][p3][p4]);
		add(dp[i+1][max(p1-1,0)][p4?h:0][max(p3-1,0)][p2>1],dp[i][p1][p2][p3][p4]);
		add(dp[i+1][max(p1-1,0)][max(p2-1,0)][p4?h:0][p3>1],dp[i][p1][p2][p3][p4]);
		add(dp[i+1][max(p1-1,0)][max(p2-1,0)][max(p3-1,0)][p4],dp[i][p1][p2][p3][p4]);
	}
	rep(p1,0,h) rep(p2,0,h) rep(p3,0,h) rep(p4,0,1)
	if (p1||p2||p3||p4) add(ans,dp[n][p1][p2][p3][p4]);
	printf("%d\n",ans);
}

