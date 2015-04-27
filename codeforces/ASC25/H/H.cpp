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
const int N=300;
vector<int> E[N];
int dt[N][N],n,vis[N],l[N],ans,cnt;
int solve(int x)
{
	for(int i=0;i<E[x].size();i++)
		if (vis[E[x][i]]!=cnt)
		{
			vis[E[x][i]]=cnt;
			if (!l[E[x][i]]||solve(l[E[x][i]])) {l[E[x][i]]=x;return 1;}
		}
	return 0;
}
int main()
{
	freopen("perfect.in","r",stdin);
	freopen("perfect.out","w",stdout);
	scanf("%d",&n);int x,y;
	rep(i,1,n)
	{
		scanf("%d",&x);
		while(x--) scanf("%d",&y),dt[i][y]=1;
	}
	rep(i,1,n) rep(j,1,n) if (dt[i][j] && dt[j][i]) E[i].pb(j);
	rep(i,1,n) ++cnt,ans+=solve(i);
	puts(ans==n?"YES":"NO");
}
