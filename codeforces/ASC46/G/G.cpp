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
const LL Mod=242121643LL;
int n,m;
LL C[300][300];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	rep(i,0,200) C[i][0]=1;
	rep(i,1,200) rep(j,1,200) C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	while (scanf("%d%d",&n,&m)!=EOF && n)
	{
		int cnt=0,x;
		rep(i,1,n) scanf("%d",&x),cnt+=x==1;
		LL ans=0;
		rep(i,1,cnt)
			if (i<=m && (i&1)) ans=(ans+C[cnt][i]*C[n-cnt][m-i])%Mod;
		printf("%lld\n",ans);
	}
}
