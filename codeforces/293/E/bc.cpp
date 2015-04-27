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

const int N=101000;
VI vec;
vector<pair<int,PII> > evt;
vector<PII> e[N],pt[N];
int c[N];
int n,a,b,p,w;
ll ans;

int q[N],f[N],vis[N],sz[N],ms[N];
int find(int u) {
	int t=1;q[0]=u;f[u]=-1;
	rep(i,0,t) {
		u=q[i];
		rep(j,0,SZ(e[u])) {
			int v=e[u][j].fi;
			if (!vis[v]&&v!=f[u]) f[q[t++]=v]=u;
		}
		ms[q[i]]=0;
		sz[q[i]]=1;
	}
	for (int i=t-1;i>=0;i--) {
		ms[q[i]]=max(ms[q[i]],t-sz[q[i]]);
		if (ms[q[i]]*2<=t) return q[i];
		sz[f[q[i]]]+=sz[q[i]];
		ms[f[q[i]]]=max(ms[f[q[i]]],sz[q[i]]);
	}
	return 0;
}
void dfs(int u,int f,int xa,int xb,int rt,int rt2) {
	pt[rt].pb(mp(xa,xb));
	pt[rt2].pb(mp(xa,xb));
	rep(i,0,SZ(e[u])) {
		int v=e[u][i].fi;
		if (vis[v]||v==f) continue;
		dfs(v,u,xa+1,xb+e[u][i].se,rt,rt2);
	}
}
void modify(int x) { for (;x<=SZ(vec);x+=x&-x) c[x]++;}
int query(int x) { int s=0; for (;x;x-=x&-x) s+=c[x]; return s;}
ll solve(vector<PII> &p) {
	ll x=0;
	vec.clear();
	rep(i,0,SZ(p)) vec.pb(p[i].se);
	sort(all(vec));
	evt.clear();
	rep(i,0,SZ(p)) if (2*p[i].fi<=a&&2*p[i].se<=b) --x;
	rep(i,0,SZ(p)) {
		evt.pb(mp(p[i].fi,mp(0,lower_bound(all(vec),p[i].se)-vec.begin()+1)));
		evt.pb(mp(a-p[i].fi,mp(1,upper_bound(all(vec),b-p[i].se)-vec.begin())));
	}
	sort(all(evt));
	sort(all(vec));
	rep(i,0,SZ(vec)+1) c[i]=0;
	rep(i,0,SZ(evt)) {
		if (evt[i].se.fi==0) modify(evt[i].se.se);
		else x+=query(evt[i].se.se);
	}
	return x;
}
void solve(int u) {
	u=find(u);
	pt[u].clear();
	pt[u].pb(mp(0,0));
	rep(i,0,SZ(e[u])) {
		int v=e[u][i].fi;
		if (vis[v]) continue;
		pt[v].clear();
		dfs(v,u,1,e[u][i].se,v,u);
		ans-=solve(pt[v]);
	}
	ans+=solve(pt[u]);
	vis[u]=1;
	rep(i,0,SZ(e[u])) {
		int v=e[u][i].fi;
		if (vis[v]) continue;
		solve(v);
	}
}
int main() {
	freopen("E.in","r",stdin);
	scanf("%d%d%d",&n,&a,&b);
	rep(i,2,n+1) {
		scanf("%d%d",&p,&w);
		e[i].pb(mp(p,w));
		e[p].pb(mp(i,w));
	}
	solve(1);
	printf("%I64d\n",ans/2);
}