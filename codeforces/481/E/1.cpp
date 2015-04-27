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
const int N=310000;
struct lj{int x,y;}P[N];
int delta,n,ty[N],vis[N],ans[N],T;
int cmp(lj a,lj b){return a.x<b.x || (a.x==b.x && a.y<b.y);}
int main()
{
	scanf("%d",&n);
	rep(i,1,n)
	{
		scanf("%d%d",&P[i].x,&P[i].y);
		if (P[i].x>P[i].y) delta++,ty[i]=1;
		else if (P[i].x==P[i].y) ty[i]=2;
	}
	delta=n-delta*2+1;
	if (delta<=0) {puts("0");return 0;}
	T=delta;
	rep(i,2,n)
	if (!vis[i-1])
	{
		if (!delta) break;int cnt=0;
		if (P[i-1].x>P[i-1].y) cnt++;
		if (P[i].x>P[i].y) cnt++;
		if (P[i].x+P[i-1].x>P[i].y+P[i-1].y) cnt--;
		if (cnt<=0) ans[delta]=i-1,delta--,vis[i-1]=vis[i]=1;
	}
	if (delta) {puts("-1");return 0;}
	printf("%d\n",T);
	rep(i,1,T) printf("%d %d\n",ans[i],ans[i]+1);
}
