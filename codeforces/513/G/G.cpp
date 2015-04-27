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
int ans,ti,a[1000],n,m;
void get()
{
	//rep(i,1,n) printf("%d ",a[i]);
	//puts("");
	++ti;
	rep(i,1,n)
		rep(j,i+1,n)
		if (a[i]>a[j]) ans++;
}
void dfs(int w)
{
	if (w>m) {get();return;}
	rep(i,1,n)
		rep(j,i,n)
		{
			rep(k,i,(i+j)/2) swap(a[k],a[j-(k-i)]);
			dfs(w+1);
			rep(k,i,(i+j)/2) swap(a[k],a[j-(k-i)]);
		}
}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&a[i]);
	dfs(1);
	printf("%.12lf\n",(D)ans/(D)ti);
}
