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
const int N=120000;
int ans[N],n,m,pos[N],val[N],cnt;
vector<pair<int,int> > E;
void work()
{
	rep(i,1,m) ans[i]=val[i]=pos[i]=0;cnt=0;
	int x,y;E.clear();
	rep(i,1,m)
	{
		scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		if (x>1) ans[i]=++cnt,val[x]+=cnt,val[y]+=cnt;
		else ans[i]=-y;
	}
	rep(i,1,n) E.pb(mp(val[i],i));
	sort(E.begin(),E.end());
	for (int i=0;i<E.size();i++)
		if (E[i].second>1) pos[E[i].second]=++cnt;
	rep(i,1,m)
		if (ans[i]<0) ans[i]=pos[-ans[i]];
	puts("Yes");
	rep(i,1,m) printf("%d ",ans[i]);puts("");
}
int main()
{
	freopen("flights.in","r",stdin);
	freopen("flights.out","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF && n) work();
}
