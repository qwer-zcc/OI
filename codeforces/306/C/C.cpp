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
const int N=5000,Mod=1000000009;
LL ans;
int n,W,B,C[N][N],fac[N];
int main()
{
	scanf("%d%d%d",&n,&W,&B);
	fac[1]=1;
	rep(i,2,4010) fac[i]=(fac[i-1]*(LL)i)%(LL)Mod;
	C[0][0]=1;
	rep(i,1,4010)
	{
		C[i][0]=1;
		rep(j,1,4010) C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
	n--;
	rep(i,1,W-1) rep(j,0,n-2)
	{
		ans=(ans+ (LL)C[B-1][j]*C[W-2][n-2-j])%(LL)Mod;
	}
	ans=(ans*(LL)fac[W])%(LL)Mod;
	ans=(ans*(LL)fac[B])%(LL)Mod;
	printf("%lld\n",ans);
}

