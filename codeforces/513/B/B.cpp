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
int n,cnt,a[100];
LL m;
/*
void get()
{
	//rep(i,1,m) printf("%d ",a[i]);
	//puts("");
	++cnt;
	if (cnt==m)
	{
		rep(i,1,n) printf("%d ",a[i]);
		puts("");
		exit(0);
	}
}
void dfs(int w,int l,int r)
{
	if (l>r) {get();return;}
	if (l==r) {a[l]=w;dfs(w+1,l+1,r);return;}
	a[l]=w;
	dfs(w+1,l+1,r);
	a[r]=w;
	dfs(w+1,l,r-1);
}
int main()
{
	scanf("%d%d",&n,&m);
	dfs(1,1,n);
}
*/
int main()
{
	scanf("%d%lld",&n,&m);
	//dp[1]=1;
	//rep(i,1,n) dp[i]=dp[i-1]*2;
	int l=1,r=n,cnt=0;
	drep(i,n-2,0)
	{
		if (m>(1LL<<i)) a[r]=++cnt,r--,m-=1LL<<i;
		else a[l]=++cnt,l++;
	}
	rep(i,1,n) if (!a[i]) a[i]=n;
	rep(i,1,n) printf("%d ",a[i]);puts("");
}
