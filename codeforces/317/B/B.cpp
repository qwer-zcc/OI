//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 02/11/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF int(2e9)
#define LLINF (LL)(8e18)
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
LL Pow(LL a,LL b,LL Mod){LL ans=1;a%=Mod;for(;b;b>>=1) ans=b&1?(ans*a%Mod):ans,a=a*a%Mod;return ans;}
const int U[4]={0,0,1,-1};
const int V[4]={1,-1,0,0};
queue<pair<int,int> > Q;
int num[300][300],n,t,x,y;
int main()
{
	scanf("%d%d",&n,&t);
	num[100][100]=n;Q.push(mp(100,100));
	while (Q.size())
	{
		int x=Q.front().first,y=Q.front().second;Q.pop();
		if (num[x][y]<4) continue;
		rep(i,0,3)
		{
			num[x+U[i]][y+V[i]]+=num[x][y]/4;
			if (num[x+U[i]][y+V[i]]>=4) Q.push(mp(x+U[i],y+V[i]));
		}
		num[x][y]%=4;
	}
	rep(i,1,t)
	{
		scanf("%d%d",&x,&y);
		x+=100;y+=100;
		if (x>=0 && x<=200 && y>=0 && y<=200) printf("%d\n",num[x][y]);
		else puts("0");
	}
}

