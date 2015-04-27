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
const int N=11000,Mod=1000000007;
int dp[N][8],n,dt[4][N],Ox,Oy,ans,ty[10];
char s[N];
int get()
{
	M(dp);
	dp[0][7]=1;
	rep(i,1,n)
	{
		rep(j,0,7) rep(k,0,7)
		{
			int flag=0;
			rep(l,0,2) if (!(j&(1<<l)) && (!(k&(1<<l))||dt[l+1][i])   ) flag=1;
			rep(l,0,2)
			if (dt[l+1][i] && !(k&(1<<l))) flag=1;
			rep(l,0,2)
			if (!dt[l+1][i] && (j&(1<<l)) && (k&(1<<l))) flag=1;
			if (flag) continue;
			dp[i][k]=(dp[i][k]+dp[i-1][j])%Mod;
		}
		if (dt[1][i]==0 && dt[2][i]==0) dp[i][3]=(dp[i][3]+dp[i][0])%Mod;
		if (dt[2][i]==0 && dt[3][i]==0) dp[i][6]=(dp[i][6]+dp[i][0])%Mod;
		if (dt[1][i]==0 && dt[2][i]==0) dp[i][7]=(dp[i][7]+dp[i][4])%Mod;
		if (dt[2][i]==0 && dt[3][i]==0) dp[i][7]=(dp[i][7]+dp[i][1])%Mod;
		
	}
	return dp[n][7];
}
void work(int ty)
{
	if (ty==0) dt[Ox][Oy-1]^=1,dt[Ox][Oy-2]^=1;
	else if (ty==1) dt[Ox][Oy+1]^=1,dt[Ox][Oy+2]^=1;
	else if (ty==2) dt[Ox+1][Oy]^=1,dt[Ox+2][Oy]^=1;
	else dt[Ox-1][Oy]^=1,dt[Ox-2][Oy]^=1;
}
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,3)
	{
		scanf("%s",s+1);
		rep(j,1,n)
		{
			if (s[j]!='.') dt[i][j]=1;
			if (s[j]=='O') Ox=i,Oy=j;
		}
	}
	if (Oy>2 && !dt[Ox][Oy-1] && !dt[Ox][Oy-2])
	{
		work(0);
		ans=(ans+get())%Mod;
		work(0);
		ty[0]=1;
	}
	if (Oy+2<=n && !dt[Ox][Oy+1] && !dt[Ox][Oy+2])
	{
		work(1);
		ans=(ans+get())%Mod;
		work(1);
		ty[1]=1;
	}
	if (Ox==1 && !dt[Ox+1][Oy] && !dt[Ox+2][Oy])
	{
		work(2);
		ans=(ans+get())%Mod;
		work(2);
		ty[2]=1;
	}
	if (Ox==3 && !dt[Ox-1][Oy] && !dt[Ox-2][Oy])
	{
		work(3);
		ans=(ans+get())%Mod;
		work(3);
		ty[3]=1;
	}
	rep(i,0,3)
	rep(j,i+1,3)
	if (ty[i] && ty[j])
	{
		work(i);work(j);
		ans=(ans-get())%Mod;
		work(i);work(j);
	}
	rep(i,0,3)
	rep(j,i+1,3)
	rep(k,j+1,3)
	if (ty[i] && ty[j] && ty[k])
	{
		work(i);work(j);work(k);
		ans=(ans+get())%Mod;
		work(i);work(j);work(k);
	}
	printf("%d\n",(ans+Mod)%Mod);
}
