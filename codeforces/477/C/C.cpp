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
char s1[2010],s2[510];
int l1,l2,dp[2010][2010],id[100],pre[2010][100],fin[2010];
int main()
{
	//freopen("C.in","r",stdin);
	scanf("%s%s",s1+1,s2+1);l1=strlen(s1+1),l2=strlen(s2+1);
	rep(i,1,l1)
	{
		id[s1[i]-'a']=i;
		rep(j,0,25) pre[i][j]=id[j];
	}
	rep(i,1,l1)
	{
		int c=i;
		drep(j,l2,1) c=pre[c][s2[j]-'a']-1;
		fin[i]=c;
	}
	rep(i,0,l1) rep(j,0,l1) dp[i][j]=-1000000;
	dp[0][0]=0;
	rep(i,1,l1)
	{
		rep(j,0,i)
		{
			dp[i][j]=max(j>0?dp[i-1][j-1]:0,dp[i-1][j]);
			if (fin[i]>=0 && j>=i-fin[i]-l2) dp[i][j]=max(dp[i][j],dp[fin[i]][j-(i-fin[i]-l2)]+1);
		}
	}
	rep(i,0,l1) printf("%d ",dp[l1][i]);
}

