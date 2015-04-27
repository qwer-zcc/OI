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
vector<int> E[120000];
int n,x,y;
D ans;
void dfs(int w,int Fa,int dep)
{
	ans+=1./(D)dep;
	for (int i=0;i<E[w].size();i++)
	if (E[w][i]!=Fa) dfs(E[w][i],w,dep+1);
}
int main()
{
	scanf("%d",&n);
	rep(i,1,n-1) scanf("%d%d",&x,&y),E[x].pb(y),E[y].pb(x);
	dfs(1,0,1);
	printf("%lf\n",ans);
}

