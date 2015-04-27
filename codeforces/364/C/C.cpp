//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 30/10/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF ((~0U>>1)-3)
#define LLINF ((~0ULL>>1)-3)
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
int n,val[10000000],ans[10000000];
int Prime(int x)
{
	rep(i,2,int(sqrt(x)))
	if (x%i==0) return 0;
	return 1;
}
set<int> S;
int now,ti,all;
int main()
{
	scanf("%d",&n);
	val[now=1]=1;
	rep(p,2,n)
	if (Prime(p) && now<=n)
	{
		for (int i=1;i<=now;i++)
		if ((LL)val[i]*p<=2LL*(LL)n*n) val[++now]=val[i]*p;
	}
	rep(i,1,n) ans[i]=val[now-i+1];
	sort(ans+1,ans+n+1);
	rep(i,1,n) printf("%d ",ans[i]);puts("");
	rep(i,1,n) S.insert(val[i]);
	if (S.size()!=n) puts("error!");
	rep(p,2,n)
	if (Prime(p))
	{
		int gs=0;
		rep(i,1,n)
		if (ans[i]%p==0) gs++;
		if (gs) printf("%d\n",gs);
	}
}
