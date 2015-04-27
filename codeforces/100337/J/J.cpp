//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 14/08/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
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
int dp[10000],n,Mod;
int C[2510][2510];
int main()
{
	freopen("twothree.in","r",stdin);
	freopen("twothree.out","w",stdout);
	scanf("%d%d",&n,&Mod);
	C[0][0]=1;
	rep(i,1,2500)
	{
		C[i][0]=1;
		rep(j,1,2500) C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
	dp[1]=1;dp[2]=1;dp[3]=1;
	rep(i,4,n) rep(j,0,i/2)
	if ((i-j*2)%3==0) dp[i]=(dp[i]+int(((LL)dp[j+(i-j*2)/3]*C[j+(i-j*2)/3][j])%(LL)Mod)    )%Mod;
	printf("%d\n",dp[n]);
}

