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
const int U[8]={0,0,1,-1,1,1,-1,-1};
const int V[8]={1,-1,0,0,1,-1,1,-1};
const int N=1020;
int v[N][N],vis[N][N],n,m,dt[N][N],al,T,ans,FLAG,gs,Gs,T1[N][N],X,Y;
void dfs(int x,int y,int T)
{
	if (x==1||x==n||y==1||y==m) FLAG=1;
	v[x][y]=T;
	rep(i,0,7)
	if (x+U[i] && x+U[i]<=n && y+V[i] && y+V[i]<=m && v[x+U[i]][y+V[i]]!=T)
	if (dt[x+U[i]][y+V[i]])
	{
		if (!gs) X=x+U[i],Y=y+V[i];
		gs+=T1[x+U[i]][y+V[i]]!=T,T1[x+U[i]][y+V[i]]=T,v[x+U[i]][y+V[i]]=T;
	}
	else dfs(x+U[i],y+V[i],T);
}
char s[N];
void Dfs(int x,int y)
{
	v[x][y]=0;Gs++;
	int p=0;
	rep(i,0,3)
	if (T1[x+U[i]][y+V[i]]==T) p++;
	if (p>2) FLAG=1;
	rep(i,0,3)
	if (v[x+U[i]][y+V[i]]==T && T1[x+U[i]][y+V[i]]) Dfs(x+U[i],y+V[i]);
}
int main()
{
	freopen("D.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n)
	{
		scanf("%s",s);
		rep(j,0,m-1) dt[i][j+1]=s[j]=='1';
	}
	rep(i,1,n) rep(j,1,m)
	if (!dt[i][j] && !v[i][j])
	{
		FLAG=gs=Gs=0;
		dfs(i,j,++T);
		if (FLAG) continue;
		Dfs(X,Y);
		if (FLAG) continue;
		if (Gs==gs) ans=max(ans,gs);
	}
	rep(i,1,n) rep(j,1,n)
	if (dt[i][j] && dt[i+1][j] && dt[i][j+1] && dt[i+1][j+1]) ans=max(ans,4);
	printf("%d\n",ans);
}
