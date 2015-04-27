#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define INF int(1e8)
#define LL long long
#define D double
#define LD long double
#define pb push_back
#define mp make_pair
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
const int N=2000;
int n1,n2,m,vis[N],ti,Pair[N],ok[N];
vector<int> E[N];
int dfs(int x)
{
	if (vis[x]==ti) return 0;vis[x]=ti;
	for (int i=0;i<E[x].size();i++)
		if (!ok[E[x][i]])
		{
			if (!Pair[E[x][i]] || dfs(Pair[E[x][i]]))
			{
				Pair[E[x][i]]=x;
				Pair[x]=E[x][i];
				return 1;
			}
		}
	return 0;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	//freopen("A.in","r",stdin);
	scanf("%d%d%d",&n1,&n2,&m);int x,y;
	rep(i,1,m) scanf("%d%d",&x,&y),E[x].pb(y+n1),E[y+n1].pb(x);
	rep(_,1,n1)
	{
		++ti;
		dfs(_);
	}
	rep(i,1,n1+n2)
	{
		if (!Pair[i]) printf("P");
		else
		{
			ok[i]=1;int p=Pair[i];
			Pair[Pair[i]]=0;Pair[i]=0;
			++ti;
			if (dfs(p))
				printf("P");
			else
			{
				Pair[i]=p;Pair[p]=i;
				printf("N");
			}
			ok[i]=0;
		}
		if (i==n1) puts("");
	}
	puts("");
}
