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
int n,a[10000],b[10000];
void work()
{
	int t=1;
	for(;t<n;)t<<=1;
	if (t!=n) {puts("No");return;}
	a[1]=1;a[2]=4;
	b[1]=2;b[2]=3;
	for(t=2;t<n;t<<=1)
		rep(i,1,t) a[i+t]=t*2+b[i],b[i+t]=t*2+a[i];
	puts("Yes");
	rep(i,1,n) printf("%d ",a[i]);puts("");
	rep(i,1,n) printf("%d ",b[i]);puts("");
}
int main()
{
	freopen("analogous.in","r",stdin);
	freopen("analogous.out","w",stdout);
	while (scanf("%d",&n)!=EOF && n) work();
}
