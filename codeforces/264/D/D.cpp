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
const int N=1000;
char a[N],b[N];
int n,m,dp[N][N];
LL ans;
int main()
{
	freopen("D.in","r",stdin);
	//freopen("D.out","w",stdout);
	scanf("%s%s",a+1,b+1);n=strlen(a+1),m=strlen(b+1);
	dp[1][1]=1;
	rep(i,1,n) rep(j,1,m)
	if (dp[i][j])
	{
		ans++;
		if (a[i]==b[j])
		{
			if (i<n && j<m) dp[i+1][j+1]=1;
		}
		else
		{
			
			if (j<m) dp[i][j+1]=1;
			if (i<n) dp[i+1][j]=1;
		}
	}
	rep(i,1,n)
	{
		rep(j,1,m) printf("%d",dp[i][j]);
		puts("");
	}
	printf("%I64d\n",ans);
}

