//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 05/07/2014                 |
//+-------------------------------------+
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
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
#define dep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define Chen(a,b,c) int((LL)(a)*(LL)(b)%(LL)(c))
#define pb push_back
#define mp make_pair
#define ins insert
#define ps push
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
inline void read(int &x)
{
	char ch;
	while ((ch=getchar()) && !(ch>='0' && ch<='9'));x=ch-'0';
	while ((ch=getchar()) && (ch>='0' && ch<='9')) x=x*10+ch-'0';
}
struct point
{
	int x,y;
	point() {}
	point(int _x,int _y) : x(_x),y(_y) {}
} ;
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p);
	rep(i,1,n) rep(j,1,m) scanf("%d",&w[i][j]),row[i]+=w[i][j],col[j]+=w[i][j];
	rep(_,1,min(n+m,k))
	{
		int ty=0,Max=-1,il=0;
		rep(i,1,n)
		if (row[i]>Max) Max=row[i],ty=1,il=i;
		rep(i,1,m)
		if (col[i]>Max) Max=col[i],ty=2,il=i;
		ans+=Max;
		if (ty==1)
		{
			row[il]=0;
			rep(i,1,m) col[i]-=p,w[il][i]-=p;
		}
		else
		{
			col[il]=0;
			rep(i,1,n) row[i]-=p,w[i][il]-=p;
		}
	}
	LL Ans=0;
	rep(i,1,k)
	{
		Ans+=(LL)ans;
		ans-=
	}
}

