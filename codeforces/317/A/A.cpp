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
LL x,y,m,cnt;
int main()
{
	scanf("%lld%lld%lld",&x,&y,&m);
	if (x>y) swap(x,y);
	if (x>=m || y>=m) {puts("0");return 0;}
	if (x<=0 && y<=0) {puts("-1");return 0;}
	if (x>0 && y>0)
	{
		while (!(x>=m|| y>=m))
		{
			if (x>y) swap(x,y);
			x=x+y;cnt++;
		}
		printf("%lld\n",cnt);
		return 0;
	}
	cnt+=-x/y;
	x+=cnt*y;
	while (!(x>=m|| y>=m))
	{
		if (x>y) swap(x,y);
		x=x+y;cnt++;
	}
	printf("%lld\n",cnt);
}

