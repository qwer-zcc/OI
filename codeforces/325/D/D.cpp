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
const int N=3010;
const int u[8]={-1,-1,-1,0,0,1,1,1};
const int v[8]={1,0,-1,1,-1,1,0,-1};
int fa[N*N*3],n,m,K,cnt,vis[N][N<<1],ans;
pair<int,int> Stack[N<<3];
#define id(i,j) ((i-1)*(m<<1)+j)
int g_f(int x)
{
	if (fa[x]==x) return x;
	int y=g_f(fa[x]);
	Stack[++cnt]=mp(x,fa[x]);
	fa[x]=y;
}
void Insert(int x,int y)
{
	rep(_,0,7)
	{
		int xx=x+u[_],yy=y+v[_];
		if (xx==0 || xx==n+1) continue;
		if (yy==0) yy=m<<1;
		if (yy>(m<<1)) yy=1;
		if (!vis[xx][yy]) continue;
		int p=g_f(id(x,y)),q=g_f(id(xx,yy));
		Stack[++cnt]=mp(p,fa[p]);
		fa[p]=q;
	}
	vis[x][y]=1;
}
void Erase()
{
	
}
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d%d%d",&n,&m,&K);int x,y;
	rep(i,1,n) rep(j,1,m<<1) fa[id(i,j)]=id(i,j);
	rep(i,1,K)
	{
		scanf("%d%d",&x,&y);
		Insert(x,y);Insert(x,y+m);
		if (g_f(id(x,y))==g_f(id(x,y+m)))
		{
			while(cnt--) fa[Stack[cnt].first]=Stack[cnt].second;
			vis[x][y]=vis[x][y+m]=0;
		}
		else ans++;
		cnt=0;
	}
	printf("%d\n",ans);
}


































int
double
long
short
bool
const
char
void
for
if
while
do
goto
break
continue
return
else
struct
namespace
class
template
inline
using
