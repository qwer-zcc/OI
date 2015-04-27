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
const LL Mod=175781251LL;
int n;
LL dp[300],po[300],f[300][300],g[300][300];
LL Pow(LL a,int k)
{
	LL b=1;
	for(;k;k>>=1)
	{
		if (k&1) b=(b*a)%Mod;
		a=(a*a)%Mod;
	}
	return b;
}
int main()
{
	scanf("%d",&n);
	po[0]=1;rep(i,1,200) po[i]=po[i-1]*3LL%Mod;
	dp[1]=1;g[0][0]=1;
	rep(i,2,n)
	{
		rep(j,1,i-1)
			rep(k,0,j)
				g[i-1][j]=(g[i-1][j]+g[i-1-j][k]*j*2LL%Mod*dp[j])%Mod;
		rep(j,1,i-1) dp[i]=(dp[i]+g[i-1][j])%Mod;
	}
	rep(i,1,n) printf("%lld ",dp[i]);puts("");
	LL ans=0;
	f[0][0]=1;
	df[1]=1;
	rep(i,2,n) df[i]=Pow(i,Mod-2)%Mod;
	rep(i,0,n) rep(j,0,n)
	{
		rep(k,max(j,1),n)
			if (i+k<=n) f[i+k][k]=(f[i+k][k]+f[i][j]*dp[k]*df[k])%Mod;
	}
	rep(i,1,n) ans=(ans+f[n][i])%Mod;
	printf("%lld\n",ans);
	/*
	LL ans=0;
	rep(_,1,n)
	rep(i,0,n/2) ans=(ans+dp[_][i])%Mod,printf("%lld\n",dp[_][i]);
	printf("%lld\n",ans);
	*/
	//printf("%lld\n",dp[n]);
}
