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
D dp[1010][1010],f[1010],g[1010],ans;
int n,m,w[1010];
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d%d",&n,&m);int x,y;
	rep(i,1,n) scanf("%d",&w[i]);
	rep(i,1,n) rep(j,i+1,n) dp[i][j]=(D)(w[i]>w[j]);
	rep(_,1,m)
	{
		scanf("%d%d",&x,&y);int ax=x,ay=y;
		x=min(ax,ay);y=max(ax,ay);
		rep(i,1,n) f[i]=dp[min(x,i)][max(x,i)];
		rep(i,1,n) g[i]=dp[min(i,y)][max(i,y)];
		rep(i,x+1,y-1) dp[x][i]=f[i]*0.5+(1-g[i])*0.5;
		rep(i,x+1,y-1) dp[i][y]=g[i]*0.5+(1-f[i])*0.5;
		rep(i,y+1,n) dp[x][i]=f[i]/2+g[i]/2;
		rep(i,y+1,n) dp[y][i]=f[i]/2+g[i]/2;
		rep(i,1,x-1) dp[i][x]=g[i]/2+f[i]/2;
		rep(i,1,x-1) dp[i][y]=f[i]/2+g[i]/2;
		dp[x][y]=0.5;
	}
	rep(i,1,n) rep(j,i+1,n) ans+=dp[i][j];
	printf("%lf\n",ans);
}

