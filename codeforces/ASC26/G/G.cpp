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
const int Mod=10003;
int C[200][200],dp[60][60][60],n,m,al;
int main()
{
	freopen("rooks.in","r",stdin);
	freopen("rooks.out","w",stdout);
	scanf("%d%d%d",&n,&m,&al);
	C[0][0]=1;
	rep(i,1,100)
	{
		C[i][0]=1;
		rep(j,1,100) C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
	dp[0][0][0]=1;
	rep(i,0,n-1) rep(j,0,m) rep(k,0,m)
		if (dp[i][j][k])
		{
			if (k>=2) dp[i+1][j+2][k-2]=(dp[i+1][j+2][k-2]+dp[i][j][k]*C[k][2])%Mod;
			if (m-j-k>=2) dp[i+1][j][k+2]=(dp[i+1][j][k+2]+dp[i][j][k]*C[m-j-k][2])%Mod;
			if (k>=1 && m-j-k>=1) dp[i+1][j+1][k]=(dp[i+1][j+1][k]+dp[i][j][k]*C[k][1]*C[m-j-k][1])%Mod;
			if (k>=1) dp[i+1][j+1][k-1]=(dp[i+1][j+1][k-1]+dp[i][j][k]*C[k][1])%Mod;
			if (m-j-k>=1) dp[i+1][j][k+1]=(dp[i+1][j][k+1]+dp[i][j][k]*C[m-j-k][1])%Mod;
			dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k])%Mod;
		}
	int ans=0;
	rep(j,0,m) rep(k,0,m)
		if (j*2+k==al) ans=(ans+dp[n][j][k])%Mod;
	printf("%d\n",ans);
}
