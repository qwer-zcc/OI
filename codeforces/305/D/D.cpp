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
const int Mod=1000000007,N=1200000;
int n,m,k,x,y,ok[N],po2[N],ans,vis[N];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m)
	{
		scanf("%d%d",&x,&y);
		if (y!=x+1 && y!=x+k+1) {puts("0");return 0;}
		if (y==x+k+1) ok[x]=1,vis[x]=1;
	}
	rep(i,n-k,n) ok[i]=1;
	rep(i,1,n) ok[i]+=ok[i-1],vis[i]+=vis[i-1];
	rep(i,1,n)
	if (vis[i])
	{
		if (vis[i-1] || (vis[n]-vis[i+k])) {puts("0");return 0;}
		break;
	}
	po2[0]=1;
	rep(i,1,n) po2[i]=po2[i-1]*2%Mod;
	ans=1;
	rep(i,1,n-k-1)
	{
		if (vis[i-1]) continue;
		if (vis[n]-vis[i+k]) continue;
		if (vis[i]!=vis[i-1])
		{
			if (k-(ok[i+k]-ok[i-1])>=0) ans=(ans+po2[k+1-(ok[i+k]-ok[i-1])]-1)%Mod;
		}
		else
		{
			if (k-(ok[i+k]-ok[i-1])>=0) ans=(ans+po2[k-(ok[i+k]-ok[i-1])])%Mod;
		}
	}
	printf("%d\n",(ans+Mod)%Mod);
}

