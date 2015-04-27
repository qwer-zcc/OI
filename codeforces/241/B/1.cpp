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

const int N=50100,M=30;
struct node {
	int ct,cnt[M];
	node *s[2];
} pool[N*35],*cur=pool,*rt;
vector<node*> vf;
ll gg[35],m;
int n,a[N];
void dfs(node *p) {
	rep(i,0,2) if (p->s[i]) {
		dfs(p->s[i]);
		p->ct+=p->s[i]->ct;
		rep(j,0,M) p->cnt[j]+=p->s[i]->cnt[j];
	}
}
void ff(int x,int y) {
	if (y==0) { vf.pb(rt); return;}
	--y;
	node *p=rt;
	per(i,0,M) {
		int u=(x>>i)&1,v=(y>>i)&1;
		if (v==0) {
			if (p->s[u^1]) vf.pb(p->s[u^1]);
		}
		p=p->s[u^v];
		if (!p) break;
	}
}
ll calc(int x) {
	if (x==0) return 1ll*n*(n-1)/2;
	ll sm=0;
	rep(i,0,n) {
		vf.clear();
		ff(a[i],x);
		rep(j,0,SZ(vf)) sm+=vf[j]->ct;
	}
	return sm/2;
}
ll csum(int x) {
	ll sm=0;
	rep(k,0,M) gg[k]=0;
	rep(i,0,n) {
		vf.clear();
		ff(a[i],x);
		rep(j,0,SZ(vf)) sm+=vf[j]->ct;
		rep(k,0,M) {
			int u=(a[i]>>k)&1;
			rep(j,0,SZ(vf)) {
				if (u==0) gg[k]+=vf[j]->cnt[k];
				else gg[k]+=vf[j]->ct-vf[j]->cnt[k];
			}
		}
	}
	ll ans=0;
	rep(k,0,M) ans=(ans+(gg[k]/2)%mod*(1<<k))%mod;
	return ans;
}
int main() {
	freopen("B.in","r",stdin);
	scanf("%d%I64d",&n,&m);
	if (m==0) return puts("0"),0;
	rt=cur++;
	rep(i,0,n) {
		scanf("%d",a+i);
		node *p=rt;
		per(j,0,M) {
			int w=(a[i]>>j)&1;
			if (!p->s[w]) p->s[w]=cur++;
			p=p->s[w];
		}
		p->ct++;
		rep(j,0,M) if ((a[i]>>j)&1) p->cnt[j]++;
	}
	dfs(rt);
	int l=0,r=(1<<M)-1;
	while (l+1<r) {
		int md=(l+r)>>1;
		if (calc(md)>=m) l=md; else r=md;
	}
	printf("%I64d\n",(csum(r)+(m-calc(r))*l)%mod);
}

