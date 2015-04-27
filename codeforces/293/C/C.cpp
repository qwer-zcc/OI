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
int ans,pl;
LL n,P[100000];
int main()
{
	scanf("%lld",&n);
	if (n%3!=0) {puts("0");return 0;}
	n/=3;
	for(LL i=1;i*i<=n;i++)
	if (n%i==0)
	{
		P[++pl]=i;
		if (i*i!=n) P[++pl]=n/i;
	}
	sort(P+1,P+pl+1);
	rep(i,1,pl)
	if (i*i*i<=n)
	{
		rep(j,i,pl)
		{
			if (n%(P[i]*P[j])==0)
			{
				LL k=n/P[i]/P[j];
				if (((P[i]+P[j]+k)&1)||k<P[i]||k<P[j]||(P[i]+P[j]+k)/2<=k) continue;
				if (P[i]==P[j] && P[i]==k) ans++;
				else if (P[i]==P[j] || P[i]==k || P[j]==k) ans+=3;
				else ans+=6;
			}
			if (n/P[i]/P[j]<P[j]) break;
		}
	} else break;
	printf("%d\n",ans);
}

