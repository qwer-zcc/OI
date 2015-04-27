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
const int N=320000;
struct lj{int x,y,z,id;}P[N];
int n,m,S,T,Row[N],Col[N],Rid[N],Cid[N],pre[N],ans[N],Ans;
int cmp(lj a,lj b){return a.x<b.x||(a.x==b.x && a.y<b.y);}
int main()
{
	//freopen("I.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d%d%d",&P[i].x,&P[i].y,&P[i].z),P[i].id=i;
	sort(P+1,P+n+1,cmp);
	rep(i,1,n)
	if (P[i].id==1) S=i;
	else if (P[i].id==n) T=i;
	rep(i,1,n)
	if (P[i].id==1) 
	Row[P[S].x]=Col[P[S].y]=P[S].z;
	Rid[P[S].x]=Cid[P[S].y]=S;
	rep(i,S+1,T)
	{
		int x=-INF,ty=-1;
		if (Row[P[i].x]-m>=0) x=Row[P[i].x]-m,ty=0;
		if (Col[P[i].y]-m>=0 && Col[P[i].y]-m>x) x=Col[P[i].y]-m,ty=1;
		if (ty==-1) continue;
		if (ty==0) pre[i]=Rid[P[i].x];
		else pre[i]=Cid[P[i].y];
		x+=P[i].z;
		Ans=x;
		if (x>Row[P[i].x]) Row[P[i].x]=x,Rid[P[i].x]=i;
		if (x>Col[P[i].y]) Col[P[i].y]=x,Cid[P[i].y]=i;
	}
	printf("%d\n",Ans);
	int al=1;
	ans[al]=T;
	while (T!=S) T=pre[T],ans[++al]=T;
	printf("%d\n",al);
	drep(i,al,1) printf("%d %d\n",P[ans[i]].x,P[ans[i]].y);
}

