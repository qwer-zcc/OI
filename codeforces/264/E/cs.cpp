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
#include <windows.h>
int vis[100010],Vis[100010],g[100010],cnt;
int main()
{
	srand(GetTickCount());
	freopen("E.in","w",stdout);
	int n=20,m=20,K=10;
	printf("%d %d\n",n,m);
	rep(i,1,m)
	{
		int ty=rand()%4;
		if (ty)
		{
			printf("1 ");
			int p=rand()%n+1,q=rand()%10+1;
			while (vis[p]) p=rand()%n+1;
			vis[p]=1;
			while (Vis[q]) q=rand()%10+1;
			Vis[q]=1;
			printf("%d %d\n",p,q);
			cnt++;
		}
		else
		{
			if (!cnt) {i--;continue;}
			printf("2 ");
			printf("%d\n",rand()%cnt+1);
			cnt--;
		}
		rep(j,1,10) g[j]=0;
		rep(j,1,10)
		if (Vis[j]) g[j+1]=1;
		rep(j,1,10) Vis[j]=g[j];
	}
}

