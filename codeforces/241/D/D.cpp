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
int dp[33][33][50010],ans[100],al,whe[100],nn,p;
void g_ans(int n)
{
	puts("Yes");
	int j=0,k=0;
	while(1)
	{
		//printf("%d %d %d  %d\n",n,j,k,dp[n][j][k]);
		int jj=dp[n][j][k]/1000000,kk=(dp[n][j][k]-jj*1000000)/10,t=dp[n][j][k]%10;
		if (t) ans[++al]=whe[n];
		if (jj==0 && kk==0) break;
		n--;j=jj;k=kk;
	}
	printf("%d\n",al);
	drep(i,al,1) printf("%d ",ans[i]);puts("");
}
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d%d",&nn,&p);int x,K,n=0;
	dp[0][0][0]=1;
	rep(i,1,nn)
	{
		scanf("%d",&x);
		if (x>31) continue;
		whe[n+1]=i;
		rep(j,0,31) rep(k,0,p-1)
		if (dp[n][j][k])
		{
			if (x<10) K=(k*10+x)%p;
			else K=(k*100+x)%p;
			dp[n+1][j^x][K]=j*1000000+k*10+1;
			if ((j^x)==0 && K==0) {g_ans(n+1);return 0;}
			dp[n+1][j][k]=j*1000000+k*10;
		}
		n++;
	}
	puts("No");
}

