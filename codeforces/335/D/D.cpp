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
const int N=110000;
struct lj{int x1,y1,x2,y2;}P[N];
int n,al,ans[N],dt[3010][3010],isxu[3010][3010],isxd[3010][3010],isyu[3010][3010],isyd[3010][3010],Is[3010][3010],maxn,maxm;
void get_ans(int x1,int y1,int x2,int y2)
{
	rep(i,1,n)
	if (P[i].x1>=x1 && P[i].x1<=x2 &&
		P[i].x2>=x1 && P[i].x2<=x2 &&
		P[i].y1>=y1 && P[i].y1<=y2 &&
		P[i].y2>=y1 && P[i].y2<=y2) ans[++al]=i;
	printf("YES %d\n",al);
	rep(i,1,al) printf("%d ",ans[i]);puts("");
	exit(0);
}
inline int ask_sum(int x1,int y1,int x2,int y2) {x1--;y1--;return dt[x2][y2]-dt[x1][y2]-dt[x2][y1]+dt[x1][y1];}
inline int ask_isxu(int x1,int y1,int x2,int y2) {x1--;y1--;return isxu[x2][y2]-isxu[x1][y2]-isxu[x2][y1]+isxu[x1][y1];}
inline int ask_isxd(int x1,int y1,int x2,int y2) {x1--;y1--;return isxd[x2][y2]-isxd[x1][y2]-isxd[x2][y1]+isxd[x1][y1];}
inline int ask_isyu(int x1,int y1,int x2,int y2) {x1--;y1--;return isyu[x2][y2]-isyu[x1][y2]-isyu[x2][y1]+isyu[x1][y1];}
inline int ask_isyd(int x1,int y1,int x2,int y2) {x1--;y1--;return isyd[x2][y2]-isyd[x1][y2]-isyd[x2][y1]+isyd[x1][y1];}
int main()
{
	//freopen("D.in","r",stdin);
	read(n);
	rep(i,1,n)
	{
		read(P[i].x1),read(P[i].y1),read(P[i].x2),read(P[i].y2),P[i].x1++,P[i].y1++;
		maxn=max(maxn,P[i].x2);
		maxm=max(maxm,P[i].y2);
	}
	rep(_,1,n)
	{
		rep(i,P[_].x1,P[_].x2) rep(j,P[_].y1,P[_].y2) dt[i][j]=1;
		rep(i,P[_].x1,P[_].x2) isxd[i][P[_].y1]=isxu[i][P[_].y2]=1;
		rep(i,P[_].y1,P[_].y2) isyd[P[_].x1][i]=isyu[P[_].x2][i]=1;
		rep(i,P[_].x1,P[_].x2) Is[i][P[_].y1]=Is[i][P[_].y2]=_;
		rep(i,P[_].y1,P[_].y2) Is[P[_].x1][i]=Is[P[_].x2][i]=_;
	}
	rep(i,1,maxn) rep(j,1,maxm) dt[i][j]+=dt[i-1][j]+dt[i][j-1]-dt[i-1][j-1],
								isxu[i][j]+=isxu[i-1][j]+isxu[i][j-1]-isxu[i-1][j-1],
								isyd[i][j]+=isyd[i-1][j]+isyd[i][j-1]-isyd[i-1][j-1],
								isxd[i][j]+=isxd[i-1][j]+isxd[i][j-1]-isxd[i-1][j-1],
								isyu[i][j]+=isyu[i-1][j]+isyu[i][j-1]-isyu[i-1][j-1];
	rep(_,1,n)
	{
		int x=P[_].x1,y=P[_].y1;
		rep(i,1,3000)
		if (x+i-1<=maxn && y+i-1<=maxm)
		{
			if (ask_sum(x,y,x+i-1,y+i-1)!=i*i) break;
			if (ask_isxd(x,y,x+i-1,y)!=i) break;
			if (ask_isyd(x,y,x,y+i-1)!=i) break;
			if (Is[x-1][y]==Is[x][y] || Is[x+i][y]==Is[x+i-1][y]) continue;
			if (Is[x][y-1]==Is[x][y] || Is[x][y+i]==Is[x][y+i-1]) continue;
			if (ask_isxu(x,y+i-1,x+i-1,y+i-1)!=i || Is[x-1][y+i-1]==Is[x][y+i-1] || Is[x+i][y+i-1]==Is[x+i-1][y+i-1]) continue;
			if (ask_isyu(x+i-1,y,x+i-1,y+i-1)!=i || Is[x+i-1][y-1]==Is[x+i-1][y] || Is[x+i-1][y+i]==Is[x+i-1][y+i-1]) continue;
			get_ans(x,y,x+i-1,y+i-1);
		}
		else break;
	}
	puts("NO");
}

