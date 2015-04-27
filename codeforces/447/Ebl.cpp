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
const int N=400000;
const int Mod=1000000009;
int w[N],n,m,f[N];
int main()
{
	freopen("E.in","r",stdin);
	scanf("%d %d\n",&n,&m);
	rep(i,1,n) scanf("%d",&w[i]);
	f[1]=1;f[2]=1;int ty,x,y;
	rep(i,3,n) f[i]=(f[i-1]+f[i-2])%Mod;
	rep(i,1,m)
	{
		scanf("%d%d%d",&ty,&x,&y);
		if (ty==1)
		{
			rep(j,x,y) w[j]=(w[j]+f[j-x+1])%Mod;
		}
		else
		{
			int ans=0;
			rep(j,x,y) ans=(ans+w[j])%Mod;
			printf("%d\n",ans);
		}
	}
}

