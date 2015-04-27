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
#define dn dp[i][j][k]
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
const int N=160,Mod=1000000007;
int dp[N][N][N][2][2],n,m,sum[N][N][N][2][2];
void add(int &a,int b) {a=(a+b)%Mod;}
inline int calc(int i,int p,int q,int x1,int y1,int x2,int y2)
{
	if (x1>x2) return 0;
	if (y1>y2) return 0;
	int ans=sum[i][x2][y2][p][q];
	add(ans,-sum[i][x2][y1-1][p][q]);
	add(ans,-sum[i][x1-1][y2][p][q]);
	add(ans,sum[i][x1-1][y1-1][p][q]);
	ans=(ans+Mod)%Mod;
	return ans;
}
int ans=0;
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n)
	{
		rep(j,1,m) rep(k,j,m)
		{
			dn[0][0]=1;
			add(dn[0][0],calc(i-1,0,0,j,j,k,k));
			add(dn[0][1],calc(i-1,0,0,j,k+1,k,m));
			add(dn[0][1],calc(i-1,0,1,j,k,k,m));
			add(dn[1][0],calc(i-1,0,0,1,j,j-1,k));
			add(dn[1][0],calc(i-1,1,0,1,j,j,k));
			add(dn[1][1],calc(i-1,0,0,1,k+1,j-1,m));
			add(dn[1][1],calc(i-1,1,0,1,k,j-1,m));
			add(dn[1][1],calc(i-1,0,1,1,k+1,j,m));
			add(dn[1][1],calc(i-1,1,1,1,k,j,m));
			add(ans,dn[0][0]);
			add(ans,dn[0][1]);
			add(ans,dn[1][0]);
			add(ans,dn[1][1]);
		}
		rep(p,0,1) rep(q,0,1)
		{
			rep(j,1,m) rep(k,1,m)
			{
				sum[i][j][k][p][q]=dn[p][q];
				add(sum[i][j][k][p][q],sum[i][j-1][k][p][q]);
				add(sum[i][j][k][p][q],sum[i][j][k-1][p][q]);
				add(sum[i][j][k][p][q],-sum[i][j-1][k-1][p][q]);
				sum[i][j][k][p][q]=(sum[i][j][k][p][q]+Mod)%Mod;
			}
		}
	}
	printf("%d\n",ans);
}

