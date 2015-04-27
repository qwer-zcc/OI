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
const int N=110000;
struct point
{
	int x,y;
	point() {}
	point(int _x,int _y) : x(_x),y(_y) {}
} Ans[N];
int n,pri[N],pl,vis[N],b[N],bl,al;
int main()
{
	scanf("%d",&n);
	pri[pl=1]=2;
	rep(i,3,n/2)
	{
		int flag=1;
		rep(j,2,int(sqrt(i)))
		if (i%j==0) flag=0;
		if (flag) pri[++pl]=i;
	}
	rep(i,2,pl)
	{
		bl=0;
		rep(j,1,n/pri[i])
		if (!vis[j*pri[i]]) b[++bl]=j*pri[i];
		if (bl&1)
		{
			if (bl>=3)
			{
				Ans[++al]=point(b[1],b[3]);
				vis[b[1]]=vis[b[3]]=1;
				rep(j,1,(bl-3)/2) Ans[++al]=point(b[(j+1)*2],b[(j+1)*2+1]),vis[b[(j+1)*2]]=vis[b[(j+1)*2+1]]=1;
			}
		}
		else
		{
			rep(j,1,bl/2) Ans[++al]=point(b[j*2-1],b[j*2]),vis[b[j*2-1]]=vis[b[j*2]]=1;
		}
	}
	bl=0;
	rep(i,1,n/2)
	if (!vis[i*2]) b[++bl]=i*2;
	rep(i,1,bl/2) Ans[++al]=point(b[i*2-1],b[i*2]);
	printf("%d\n",al);
	rep(i,1,al) printf("%d %d\n",Ans[i].x,Ans[i].y);
}

