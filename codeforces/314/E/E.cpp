//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 12/10/2014                 |
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
const uint Mod=(uint)4294967296;
const int N=120000;
int n,Gs;
uint f[N];
char s[N];
int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d%s",&n,s+1);
	if (n&1) {puts("0");return 0;}
	rep(i,1,n) Gs+=s[i]!='?';
	if (Gs>n/2) {puts("0");return 0;}
	f[0]=1;
	rep(_,1,n)
	{
		if (s[_]=='?')
		{
			LL c=f[1];
			for (int i=2-(_&1);i<=min(_,n/2);i+=2) f[i]=f[i-1]+f[i+1];
			f[0]=c;
		}
		else
		{
			drep(i,min(_,n/2),1) f[i]=f[i-1];
			f[0]=0;
		}
	}
	uint ans=f[0];
	rep(i,1,n/2-Gs) ans=ans*25;
	printf("%u\n",ans);
}

