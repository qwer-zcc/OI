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
int n,m,k,dt[1000][1000],TIM,sum;
char s[1000];
void print()
{
	rep(i,1,n)
	{
		rep(j,1,m)
		if (dt[i][j]==1) printf("#");
		else if (dt[i][j]==TIM) printf(".");
		else printf("X");
		puts("");
	}
	exit(0);
}
void check(int x,int y)
{
	if (!(x>=1 && x<=n && y>=1 && y<=m)) return;
	dt[x][y]=TIM;
	if (dt[x][y]!=1) sum++;
	if (sum==k) print();
	if (dt[x+1][y]!=1 && dt[x+1][y]!=TIM) check(x+1,y);
	if (dt[x-1][y]!=1 && dt[x-1][y]!=TIM) check(x-1,y);
	if (dt[x][y-1]!=1 && dt[x][y-1]!=TIM) check(x,y-1);
	if (dt[x][y+1]!=1 && dt[x][y+1]!=TIM) check(x,y+1);
}
int main()
{
	//freopen("A.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);int sum=0;
	rep(i,1,n)
	{
		scanf("%s",s);
		rep(j,0,m-1) dt[i][j+1]=s[j]=='#',sum+=!dt[i][j+1];
	}
	TIM=10;
	if (!k)
	{
		rep(i,1,n)
		{
			rep(j,1,m)
			if (dt[i][j]) printf("#");
			else printf(".");
			puts("");
		}
		return 0;
	}
	k=sum-k;
	rep(i,1,n)
	rep(j,1,m)
	if (dt[i][j]!=1)
	{
		++TIM;sum=0;
		check(i,j);
	}
}

