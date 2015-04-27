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
int a[3][3],n,p1,p2;
char s1[2200000],s2[2200000];
int main()
{
	scanf("%d%s%s",&n,s1+1,s2+1);n<<=1;
	rep(i,1,n) a[s1[i]-'0'][s2[i]-'0']++;
	rep(i,1,n>>1)
	{
		if (a[1][1]) p1++,a[1][1]--;
		else if (a[0][1]) a[0][1]--;
		else if (a[1][0]) a[1][0]--,p1++;
		else a[0][0]--;
		if (a[1][1]) p2++,a[1][1]--;
		else if (a[1][0]) a[1][0]--;
		else if (a[0][1]) a[0][1]--,p2++;
		else a[0][0]--;
	}
	puts(p1==p2?"Draw":(p1>p2?"First":"Second"));
}

