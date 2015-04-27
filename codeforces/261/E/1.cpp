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

const int N=3010000;
int dp[N],a[N],vis[N];
int p[110],s,l,r,tot,ans;
void dfs(ll u,int cpr) {
	if (cpr>=100) { a[tot++]=u;return;}
	int npr=cpr+1; 
	while (p[npr]) ++npr;
	while (u<=r) dfs(u,npr),u=u*cpr;
}
int main() {
	freopen("E.in","r",stdin);
	scanf("%d%d%d",&l,&r,&s);
	for (int i=2;i<=100;i++) for (int j=i+i;j<=100;j+=i) p[j]=1;
	dfs(1,2);
	sort(a,a+tot);
	rep(i,0,tot) dp[i]=s+1;
	dp[0]=1; vis[0]=1;
	rep(i,0,tot) printf("%d ",a[i]);puts("");
	rep(j,2,s+1) {
		int ptr=0;
		rep(i,0,tot) {
			if (dp[i]<=s) vis[i]=1;
			//printf("%d %d\n",i+1,dp[i]);
			dp[i]+=1;
		}
		rep(i,0,tot) {
			if (dp[i]>s) continue;
			while (ptr<tot&&1ll*a[i]*j!=a[ptr]) ++ptr;
			if (ptr>=tot) break;
			dp[ptr]=min(dp[ptr],dp[i]+1);
		}
	}
	rep(i,0,tot) if (a[i]>=l && vis[i]) ans++,printf("%d\n",a[i]);
	printf("%d\n",ans);
}
