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
// [pos][lastnumber][count to do][ways]
const int Mod=1000000007;
int C[200][200],n,m,T,dp[60][60][60][120],ans;
int main()
{
	scanf("%d%d%d",&n,&m,&T);
	C[0][0]=1;
	rep(i,1,100)
	{
		C[i][0]=1;
		rep(j,1,i) C[i][j]=min(T+1,C[i-1][j]+C[i-1][j-1]);
	}
	
	rep(i,1,n/2) dp[i][1][i][1]=1;
	rep(i,1,n/2)
	rep(j,1,min(m,n/2))
	rep(k,1,n/2)
	rep(l,1,T)
	if (dp[i][j][k][l])
	{
		//printf("%d %d %d %d    %d\n",i,j,k,l,dp[i][j][k][l]);
		//ans=(ans+(LL)dp[i][j][k][l]*(m-j))%Mod;
		rep(x,1,n/2-i)
		{
			int c=l*C[k+x-1][k-1];
			if (c>T) continue;
			dp[i+x][j+1][x][c]=(dp[i+x][j+1][x][c]+dp[i][j][k][l])%Mod;
		}
	}
	rep(j,1,min(m,n/2))
	{
		
	}
	printf("%d\n",ans);
}

