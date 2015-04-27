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
char s[5000];
int n,a[5000],X,sum[5000],Hash[5100*10],gs;
LL ans;
int main()
{
	//freopen("A.in","r",stdin);
	scanf("%d",&X);
	scanf("%s",s+1);n=strlen(s+1);
	rep(i,1,n) a[i]=s[i]-'0';
	rep(i,1,n) sum[i]=sum[i-1]+a[i];
	rep(i,1,n) rep(j,i,n) Hash[sum[j]-sum[i-1]]++,gs++;
	if (X==0)
	{
		int Cnt=0;
		rep(i,1,n) rep(j,i,n)
		{
			if (sum[j]-sum[i-1]==0) ans+=(LL)gs,Cnt++;
		}
		ans*=2;
		ans-=(LL)Cnt*Cnt;
	}
	else
	{
		rep(i,1,n) rep(j,i,n)
			if ((sum[j]-sum[i-1])!=0)
			{
				if (X%(sum[j]-sum[i-1])==0 && (X/(sum[j]-sum[i-1])<=5000*10)) ans+=(LL)Hash[X/(sum[j]-sum[i-1])];
			}
	}
	printf("%I64d\n",ans);
}

