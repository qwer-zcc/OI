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
int n;
LL a[4000],dp[4000],nxt[4000];
int main()
{
	freopen("ebola.in","r",stdin);
	freopen("ebola.out","w",stdout);
	while (scanf("%d",&n) && n)
	{
		rep(i,1,n) scanf("%lld",&a[i]);
		nxt[n+1]=0;
		drep(i,n,1) nxt[i]=nxt[i+1]+a[i];
		dp[1]=0;
		rep(i,2,n+1)
		{
			LL c=0;dp[i]=(LL)1e18;
			drep(j,i-1,1)
			{
				dp[i]=min(dp[i],dp[j]+c+(3*(i-j-1)+i-j+1)*nxt[i]);
				c+=min(2*(nxt[j]-nxt[i]),3*(i-j)*a[j-1]+nxt[j]-nxt[i]);
			}
		}
		printf("%lld\n",dp[n+1]);
	}
}
