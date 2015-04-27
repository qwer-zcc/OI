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
const int a[26]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
const int N=4000000;
int All[N],cnt,dp[N],l,r,p,vis[N];
void dfs(LL c,int w)
{
	if (w>25) {All[++cnt]=c;return;}
	while (c<=r) dfs(c,w+1),c*=a[w];
}
int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d%d%d",&l,&r,&p);
	dfs(1,1);
	sort(All+1,All+cnt+1);
	rep(i,1,cnt) dp[i]=p+1;
	dp[1]=1;
	rep(i,2,p)
	{
		int now=0;
		rep(j,1,cnt) vis[j]|=dp[j]<=p,dp[j]++;
		for(int j=1;j<=cnt && now<=cnt;j++)
		{
			while (now<=cnt && All[j]*i!=All[now]) now++;
			dp[now]=min(dp[now],dp[j]+1);
		}
	}
	int ans=0;
	rep(i,1,cnt) if (All[i]>=l && vis[i]) ans++;
	printf("%d\n",ans);
}

