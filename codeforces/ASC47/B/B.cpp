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
const int N=1000;
LL po[N],dp[N],m;
int ans[N],n;
LL solve()
{
	dp[0]=1;
	rep(i,1,n)
	{
		int cnt=0;
		rep(j,1,i)
			if (ans[j]==0) cnt++;
		dp[i]=po[cnt];
		rep(j,1,i/2)
		{
			cnt-=(ans[j]==0)+(ans[i-j+1]==0);
			int flag=1;
			rep(k,1,j)
				if (ans[k]!=ans[i-j+k] && ans[k] && ans[i-j+k]) {flag=0;break;}
			if (flag) dp[i]-=dp[j]*po[cnt];
		}
	}
	return dp[n];
}
int main()
{
	freopen("borderless.in","r",stdin);
	freopen("borderless.out","w",stdout);
	po[0]=1;
	rep(i,1,63) po[i]=po[i-1]*2;
	while (scanf("%d%lld",&n,&m) && n)
	{
		rep(i,1,n) ans[i]=0;
		rep(i,1,n)
		{
			ans[i]=1;LL c=solve();
			if (c<m) ans[i]=2,m-=c;
		}
		rep(i,1,n) printf("%c",ans[i]+'a'-1);puts("");
	}
}
