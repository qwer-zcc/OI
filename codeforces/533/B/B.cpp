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
#define LD long double
#define pb push_back
#define mp make_pair
#define Pi M_PI
#define clr(a) memset(a,0,sizeof(a));
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
const int N=320000;
vector<int> E[N];
LL val[N];
pair<LL,LL> ans[N];
int n;
void dfs(int w)
{
	for (int i=0;i<E[w].size();i++)
		dfs(E[w][i]);
	pair<LL,LL> p=mp(0,(LL)-1e16);
	for (int i=0;i<E[w].size();i++)
	{
		pair<LL,LL> q=ans[E[w][i]];
		p=mp( max(p.first+q.first,p.second+q.second) , max(p.first+q.second,p.second+q.first));
	}
	ans[w].first=p.first;
	ans[w].second=max(p.second,val[w]+p.first);
}
int main()
{
	freopen("B.in","r",stdin);
	scanf("%d",&n);int x,y;
	rep(i,1,n)
	{
		scanf("%d%d",&x,&y);
		if (x!=-1) E[x].pb(i);
		val[i]=y;
	}
	dfs(1);
	printf("%lld\n",max(ans[1].first,ans[1].second));
}
