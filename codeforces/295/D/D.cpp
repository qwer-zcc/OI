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
const int Mod=1000000007;
int n,m,C[2010][2010],sum[2010][2010],ans;
int main()
{
	scanf("%d%d",&n,&m);
	C[0][0]=1;
	rep(i,1,2000)
	{
		C[i][0]=1;
		rep(j,1,2000) C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
	rep(i,0,2000)
	{
		sum[i][0]=C[i][0];
		rep(j,1,1000) sum[i][j]=(sum[i][j-1]+C[i][j*2])%Mod;
	}
	//rep(i,0,2000)
	//rep(j,1,i/2) sum[i][j]=(sum[i][j-1]+sum[i][j])%Mod;
	rep(i,1,n)
	{
		rep(j,2,m)
		{
			printf("%d %d   %d\n",j,i-1,sum[j][i-1]);
			printf("     %d %d   %d\n",j-2,n-i,sum[j-2][n-i]);
			int S1=sum[j][i-1],S2=sum[j-2][n-i];
			S1=(S1*S2)%Mod;
			ans=(ans+int((LL)S1*(m-j+1)%(LL)Mod))%Mod;
		}
	}
	printf("%d\n",ans);
}

