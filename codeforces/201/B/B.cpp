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
LL ans=(LL)1e18;
int ax,ay,n,m,a[1010][1010];
void check(int x,int y)
{
	x*=4;y*=4;
	LL sum=0;
	rep(i,1,n) rep(j,1,m)
	{
		int x0=(i*4-2),y0=(j*4-2);
		sum+=(LL)((x-x0)*(x-x0)+(y-y0)*(y-y0))*(LL)a[i][j];
	}
	if (sum<ans)
	{
		ans=sum;
		ax=x/4;ay=y/4;
	}
}
int main()
{
	//freopen("B.in","r",stdin);
	read(n);read(m);
	rep(i,1,n) rep(j,1,m) read(a[i][j]);
	D x=0,y=0,z=0;
	rep(i,1,n) rep(j,1,m)
	if (a[i][j])
	{
		if (x==0)
		{
			x=(D)(i*4-2),y=(D)(j*4-2),z=(D)a[i][j];
			continue;
		}
		D x0=(D)(i*4-2),y0=(D)(j*4-2),z0=(D)a[i][j];
		x=x+(x0-x)*z0/(z0+z);
		y=y+(y0-y)*z0/(z0+z);
		z+=z0;
	}
	int X=int(x)/4,Y=int(y)/4;
	check(X,Y);
	check(X+1,Y);
	check(X+1,Y+1);
	check(X,Y+1);
	printf("%lld\n",ans);
	printf("%d %d\n",ax,ay);
}

