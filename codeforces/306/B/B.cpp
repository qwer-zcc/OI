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
const int N=2100000;
struct point
{
    int x,y;
    point() {}
    point(int _x,int _y) : x(_x),y(_y) {}
} P[N];
int n,m,Begin,End,val[N],ans[N],al,vis[N],need[N],id[N];
int main()
{
	//freopen("B.in","r",stdin);
	scanf("%d%d",&n,&m);Begin=n+10;int x,y;
	rep(i,1,m) scanf("%d%d",&x,&y),P[i].x=x,P[i].y=x+y-1,Begin=min(Begin,P[i].x),End=max(End,P[i].y);
	rep(i,1,m)
	{
		if (P[i].y>val[P[i].x])
		val[P[i].x]=P[i].y,id[P[i].x]=i;
	}
	int now=Begin-1;pair<int,int> T=mp(0,0);
	rep(i,Begin,End)
	{
		pair<int,int> x=mp(val[i],i);
		if (x.first>T.first) T=x;
		if (now<i)
		{
			vis[id[T.second]]=1;
			now=T.first;
		}
	}
	rep(i,1,m)
	if (!vis[i]) ans[++al]=i;
	printf("%d\n",al);
	rep(i,1,al) printf("%d ",ans[i]);puts("");
}
