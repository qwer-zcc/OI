//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 12/10/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF (int(1e9)-3)
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
const int N=110;
struct lj{int ty,x;}P[N];
int n,m,w[N],x,dp[21][(1<<20)+1],vis[21][(1<<20)+1];
char s[10];
int main()
{
	freopen("C.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&w[i-1]);
	sort(w,w+n,greater<int>());
	scanf("%d",&m);
	rep(i,1,m)
	{
		scanf("%s%d",s,&x);
		if (s[0]=='p') P[i].ty=1,P[i].x=x;
		else P[i].ty=2,P[i].x=x;
	}
	rep(j,0,(1<<m)-1) vis[m+1][j]=1;
	
	drep(i,m,1)
	rep(j,0,(1<<m)-1)
	if (vis[i+1][j])
	{
		if (P[i].x==1 && P[i].ty==1)
		{
			rep(k,0,m-1)
			if ((j&(1<<k)))
			{
				if (!vis[i][j-(1<<k)]) dp[i][j-(1<<k)]=dp[i+1][j]+w[k];
				else dp[i][j-(1<<k)]=max(dp[i+1][j]+w[k],dp[i][j-(1<<k)]);
				vis[i][j-(1<<k)]=1;
				break;
			}
			continue;
		}
		if (P[i].x==2 && P[i].ty==1)
		{
			rep(k,0,m-1)
			if ((j&(1<<k)))
			{
				if (!vis[i][j-(1<<k)]) dp[i][j-(1<<k)]=dp[i+1][j]-w[k];
				else dp[i][j-(1<<k)]=min(dp[i+1][j]-w[k],dp[i][j-(1<<k)]);
				vis[i][j-(1<<k)]=1;
				break;
			}
			continue;
		}
		if (P[i].x==1 && P[i].ty==2)
		{
			rep(k,0,m-1)
			if ((j&(1<<k)))
			{
				if (!vis[i][j-(1<<k)]) dp[i][j-(1<<k)]=dp[i+1][j];
				else dp[i][j-(1<<k)]=max(dp[i+1][j],dp[i][j-(1<<k)]);
				vis[i][j-(1<<k)]=1;
			}
		}
		if (P[i].x==2 && P[i].ty==2)
		{
			rep(k,0,m-1)
			if ((j&(1<<k)))
			{
				if (!vis[i][j-(1<<k)]) dp[i][j-(1<<k)]=dp[i+1][j];
				else dp[i][j-(1<<k)]=min(dp[i+1][j],dp[i][j-(1<<k)]);
				vis[i][j-(1<<k)]=1;
			}
		}
	}
	int ans=-INF;
	rep(i,0,(1<<m)-1) if (vis[1][i]) ans=max(ans,dp[1][i]);
	printf("%d\n",ans);
}

