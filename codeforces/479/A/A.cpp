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
int a[10],ans;
int main()
{
	scanf("%d%d%d",&a[1],&a[2],&a[3]);
	ans=max(ans,a[1]+a[2]+a[3]);
	ans=max(ans,a[1]+a[2]*a[3]);
	ans=max(ans,a[1]*a[2]+a[3]);
	ans=max(ans,(a[1]+a[2])*a[3]);
	ans=max(ans,a[1]*(a[2]+a[3]));
	ans=max(ans,a[1]*a[2]*a[3]);
	printf("%d\n",ans);
}

