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
const int N=100010;
int X[N],Y[N],Z[N],Dmax[N];
pair<int,int> dm[N];
int dis[300][300],n,m;
D ans=5e18;
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,1,n) dis[i][j]=int(5e8);
	rep(i,1,n) dis[i][i]=0;
	rep(i,1,m) scanf("%d%d%d",&X[i],&Y[i],&Z[i]),dis[X[i]][Y[i]]=Z[i],dis[Y[i]][X[i]]=Z[i];
	rep(k,1,n) rep(i,1,n) rep(j,1,n)
	if (dis[i][k]+dis[k][j]<dis[i][j]) dis[i][j]=dis[i][k]+dis[k][j];
	rep(i,1,n)
	{
		int x=0;
		rep(j,1,n) x=max(x,dis[i][j]);
		ans=min(ans,(D)x);
	}
	rep(i,1,m)
	{
		int p=0,q=0;
		rep(j,1,n) dm[j]=mp(dis[j][X[i]],dis[j][Y[i]]);
		sort(dm+1,dm+n+1);
		Dmax[n+1]=0;
		drep(j,n,1) Dmax[j]=max(Dmax[j+1],dm[j].second);
		rep(j,1,n)
		{
			int p=dm[j].first,q=Dmax[j+1];
			if (p+Z[i]>q && q+Z[i]>p) ans=min(ans,(p+q+Z[i])/2.);
		}
	}
	printf("%.1lf\n",ans);
}

