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
const LL Mod=175781251LL;
int n;
LL po[30000],C[300][300],f[300];
int main()
{
	freopen("bipartite.in","r",stdin);
	freopen("bipartite.out","w",stdout);
	po[0]=1;
	rep(i,1,20000) po[i]=po[i-1]*3%Mod;
	rep(i,0,100) C[i][0]=1;
	rep(i,1,100) rep(j,1,100) C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	f[0]=1;
	rep(i,1,100)
	{
		rep(j,0,i) f[i]=(f[i]+C[i][j]*po[j*(i-j)])%Mod;
		f[i]=(f[i]*(Mod+1)/2)%Mod;
		rep(j,1,i-1) f[i]=(f[i]-C[i-1][j]*f[j]%Mod*f[i-j])%Mod;
		f[i]=(f[i]+Mod)%Mod;
	}
	while (scanf("%d",&n)!=EOF && n) printf("%lld\n",f[n]);
}
