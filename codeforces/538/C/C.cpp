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
const int N=120000;
int n,m,a[N],b[N],ans;
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,m) scanf("%d%d",&a[i],&b[i]);
	rep(i,1,m-1)
		if (abs(a[i+1]-a[i])<abs(b[i]-b[i+1])) {puts("IMPOSSIBLE");return 0;}
	ans=max(b[1]+a[1]-1,b[m]+n-a[m]);
	rep(i,1,m-1)
	{
		int x=min(b[i],b[i+1]),y=max(b[i],b[i+1]),t=a[i+1]-a[i];
		t-=y-x;
		ans=max(ans,y+t/2);
	}
	printf("%d\n",ans);
}
