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
const int Mod=1000000007;
int n,m,k,a[15][15],vis[20],Vis[20],cnt,b[15][15],to[20];
LL ans;
void calc()
{
	int cnt=0;
	M(Vis);M(to);
	rep(i,1,n) rep(j,1,m)
	if (b[i][j])
	{
		if (Vis[b[i][j]] && Vis[b[i][j]]!=a[i][j]) return;
		if (to[a[i][j]] && to[a[i][j]]!=b[i][j]) return;
		if (!Vis[b[i][j]]) cnt++;
		Vis[b[i][j]]=a[i][j];
		to[a[i][j]]=b[i][j];
	}
	int c=0;
	rep(i,1,n) rep(j,1,m) c=max(c,a[i][j]);
	c-=cnt;k-=cnt;
	LL sum=1;
	drep(i,k,k-c+1) sum=(sum*(LL)i)%(LL)Mod;
	ans=(ans+sum)%(LL)Mod;
	k+=cnt;
}
void dfs(int x,int y)
{
	int xx=x,yy=y;
	if (x>n) {calc();return;}
	rep(i,1,k)
	if (vis[i]>y)
	{
		int t=vis[i];
		vis[i]=y;a[x][y]=i;
		y++;
		if (y>m) x++,y=1;
		dfs(x,y);
		x=xx;y=yy;
		vis[i]=t;a[x][y]=0;
	}
	int il=0;
	rep(i,1,k) if (!vis[i]) {il=i;break;}
	if (il==0) return;
	a[x][y]=il;vis[il]=y;
	y++;
	if (y>m) x++,y=1;
	dfs(x,y);
	x=xx;y=yy;
	vis[il]=0;a[x][y]=0;
}
int main()
{
	//freopen("B.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n) rep(j,1,m) scanf("%d",&b[i][j]);
	if (k<n+m-1) {puts("0");return 0;}
	dfs(1,1);
	printf("%lld\n",ans);
}
