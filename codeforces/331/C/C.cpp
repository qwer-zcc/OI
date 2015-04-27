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
map<pair<LL,int>,pair<LL,int> > Ans;
pair<LL,int> work(LL x,int y)
{
	if (Ans.count(mp(x,y))) return Ans[mp(x,y)];
	if (x<10) return Ans[mp(x,y)]=mp(x||y,x-max((int)x,y));
	LL c=1;
	while (x/c>=10) c*=10LL;
	return Ans[mp(x,y)]=mp(work(x%c,max(y,int(x/c))).first+work(x-x%c+work(x%c,max(y,int(x/c))).second,y).first,work(x-x%c+work(x%c,max(y,int(x/c))).second,y).second);
}
int main()
{
	LL n;
	scanf("%I64d",&n);
	printf("%I64d\n",work(n,0).first);
}

