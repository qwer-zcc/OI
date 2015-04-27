//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 14/08/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
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
struct lj{int x,y;}P[100],Q[100];
int n,m,l,r,cnt;
int main()
{
	scanf("%d%d%d%d",&n,&m,&l,&r);
	rep(i,1,n) scanf("%d%d",&P[i].x,&P[i].y);
	rep(i,1,m) scanf("%d%d",&Q[i].x,&Q[i].y);
	rep(i,l,r)
	{
		int flag=0;
		rep(j,1,n)
		{
			rep(k,1,m)
			if (!(P[j].x>Q[k].y+i||P[j].y<Q[k].x+i)) flag=1;
		}
		cnt+=flag;
	}
	printf("%d\n",cnt);
}

