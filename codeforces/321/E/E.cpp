//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 02/11/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF int(2e9)
#define LLINF (LL)(8e18)
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
LL Pow(LL a,LL b,LL Mod){LL ans=1;a%=Mod;for(;b;b>>=1) ans=b&1?(ans*a%Mod):ans,a=a*a%Mod;return ans;}
int n,m,dp[810][4010],val[4010][4010],sum[4010][4010];
void solve(int i,int l,int r,int Ol,int Or)
{
	if (l>r) return;
	if (l==r) {rep(j,Ol,min(Or,l-1)) dp[i][l]=min(dp[i][l],dp[i-1][j]+sum[j+1][l]);return;}
	int mid=l+r>>1,o=0;
	rep(j,Ol,min(Or,mid-1))
	if (dp[i-1][j]+sum[j+1][mid]<dp[i][mid]) dp[i][mid]=dp[i-1][j]+sum[j+1][mid],o=j;
	solve(i,l,mid-1,Ol,o);solve(i,mid+1,r,o,Or);
}
int main()
{
	//freopen("E.in","r",stdin);
	read(n);read(m);
	rep(i,1,n) rep(j,1,n) read(val[i][j]);
	rep(i,1,n) rep(j,1,n) val[i][j]+=val[i-1][j]+val[i][j-1]-val[i-1][j-1];
	rep(i,1,n) rep(j,1,n) sum[i][j]=(val[j][j]-val[i-1][j]-val[j][i-1]+val[i-1][i-1])>>1;
	rep(i,0,m) rep(j,0,n) dp[i][j]=INF;
	dp[0][0]=0;
	rep(i,1,m) solve(i,1,n,0,n);
	printf("%d\n",dp[m][n]);
}

