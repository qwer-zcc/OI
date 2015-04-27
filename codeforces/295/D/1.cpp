#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int n,m,ans;
int dp[2010][2010],pd[2010][2010];
int main() {
	scanf("%d%d",&n,&m);
	rep(j,0,m+1) dp[0][j]=1,pd[0][j]=1;
	rep(i,1,n+1) {
		int sm=1;
		dp[i][0]=1; pd[i][0]=0;
		rep(j,1,m+1) {
			sm=(sm+dp[i-1][j])%mod;
			dp[i][j]=(dp[i][j-1]+sm)%mod;
			pd[i][j]=(dp[i][j]-dp[i-1][j])%mod;
		}
	}
	rep(j,0,m+1) rep(i,1,n+1) {
		dp[i][j]=(dp[i-1][j]+dp[i][j])%mod;
		pd[i][j]=(pd[i-1][j]+pd[i][j])%mod;
	}
	rep(c,0,m) rep(k,1,n+1) ans=(ans+1ll*dp[n-k][c]*pd[k-1][c]%mod*(m-c-1))%mod;
	if (ans<0) ans+=mod;
	printf("%d\n",ans);
}
