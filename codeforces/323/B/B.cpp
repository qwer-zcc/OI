//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 30/09/2014                 |
//+-------------------------------------+
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#define INF (~0U>>1)-1
#define LLINF ~0ULL>>1
#define LL long long
#define uLL unsigned long long
#define uint unsigned int
#define D double
#define LD long double
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define Chen(a,b,c) int((LL)(a)*(LL)(b)%(LL)(c))
#define pb push_back
#define mp make_pair
#define ps push
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
int n,dt[1010][1010];
int main()
{
	scanf("%d",&n);
	if (n==4) {puts("-1");return 0;}
	if (n&1) rep(i,1,n) rep(j,1,n/2) dt[i][(i+j-1)%n+1]=1;
	else
	{
		rep(i,1,n-1) rep(j,1,(n-1)/2) dt[i][(i+j-1)%(n-1)+1]=1;
		rep(i,1,n-1) if (i&1) dt[i][n]=1;else dt[n][i]=1;
	}
	rep(i,1,n) {rep(j,1,n) printf("%d ",dt[i][j]);puts("");}
}

