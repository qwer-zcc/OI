//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 14/08/2014                 |
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
#define INF ~0U>>1
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
int n,m,x,y,ans,g;
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n)
	{
		scanf("%d%d",&x,&y);
		if (x>m||(x==m && y>0)) {g++;continue;}
		if (y==0) continue;
		ans=max(ans,100-y);
		int X=x,Y=y;
		while (1)
		{
			x+=X;y+=Y;
			if (y>100) x++,y-=100;
			if (x>m||(x==m && y>0)) break;
			ans=max(ans,100-y);
		}
	}
	if (g==n) puts("-1");
	else printf("%d\n",ans);
}

