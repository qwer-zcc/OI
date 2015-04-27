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
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
const int Mod=1000000007;
int dp[5002][5002],sum[5002];
int n,a,b,k;
int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&k);
	dp[0][a]=1;
	rep(i,1,n) sum[i]=sum[i-1]+dp[0][i];
	rep(i,1,k)
	{
		rep(j,1,n)
		if (j!=b)
		{
			if (j<b)
			{
				dp[i][j]=(dp[i][j]+sum[j+(b-j-1)/2])%Mod;
				dp[i][j]-=dp[i-1][j];
				if (dp[i][j]<0) dp[i][j]+=Mod;
			}
			else
			{
				int p=sum[n],q=sum[j-(j-b-1)/2-1];
				p-=q;
				if (p<0) p+=Mod;
				dp[i][j]=(dp[i][j]+p)%Mod;
				dp[i][j]-=dp[i-1][j];
				if (dp[i][j]<0) dp[i][j]+=Mod;
			}
		}
		rep(j,1,n) sum[j]=(sum[j-1]+dp[i][j])%Mod;
	}
	printf("%d\n",sum[n]);
}

