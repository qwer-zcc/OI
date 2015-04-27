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

const int V=100100,N=110000;
vector<PII> e[N];
int n,m,u,v,w,fg,s,t;
ll pw[N],pw2[N];
int fin[N],vis[N],pre[N],Dis[N];
VI ans;

struct node{
	node *s[2];
	int c1,sz;
	ll hs;
}pool[10100000],*cur=pool,*zero[N],*dis[N];
void upd(node *p) {
	p->c1=p->s[0]->c1+p->s[1]->c1;
	p->hs=p->s[1]->hs*pw[p->s[0]->sz]+p->s[0]->hs;
}
bool cmp(node *a,node *b) {
	assert(a->sz==b->sz);
	if (a->sz==1) return a->c1<b->c1;
	else {
		if (a->s[1]->hs!=b->s[1]->hs) return cmp(a->s[1],b->s[1]);
		else return cmp(a->s[0],b->s[0]);
	}
}
node *add(node *p) {
	node *q=cur++; q->sz=p->sz;
	if (q->sz==1) q->c1=q->hs=1;
	else {
		if (p->s[0]->c1==p->s[0]->sz) q->s[0]=zero[p->s[0]->sz],q->s[1]=add(p->s[1]);
		else q->s[0]=add(p->s[0]),q->s[1]=p->s[1];
		upd(q);
	}
	return q;
}
node *add(node *p,int l,int r,int x) {
	node *q=cur++; q->sz=p->sz;
	if (l==r) {
		if (p->c1==0) q->c1=q->hs=1,fg=0;
		else q=zero[1];
	} else {
		int md=(l+r)>>1;
		if (x>md) q->s[1]=add(p->s[1],md+1,r,x),q->s[0]=p->s[0];
		else {
			q->s[0]=add(p->s[0],l,md,x);
			if (fg) {
				if (p->s[1]->c1==p->s[1]->sz) q->s[1]=zero[p->s[1]->sz];
				else q->s[1]=add(p->s[1]),fg=0;
			} else q->s[1]=p->s[1];
		}
		upd(q);
	}
	return q;
}
typedef pair<node*,int> pr;
struct Cmp { bool operator()(const pr&p, const pr&q) { return !cmp(p.fi,q.fi);} };
priority_queue<pr,vector<pr>,Cmp> q;

int main() {
	freopen("E.in","r",stdin);
	//freopen("bc.out","w",stdout);
	scanf("%d%d",&n,&m);
	zero[1]=cur++;
	rep(i,2,V+1) {
		zero[i]=cur++;
		zero[i]->s[0]=zero[i-i/2];
		zero[i]->s[1]=zero[i/2];
	}
	pw[0]=pw2[0]=1;
	rep(i,1,V+1) zero[i]->sz=i,pw[i]=pw[i-1]*13331,pw2[i]=pw2[i-1]*2%mod;
	rep(i,0,m) {
		scanf("%d%d%d",&u,&v,&w);
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	scanf("%d%d",&s,&t);
	fin[s]=1;
	dis[s]=zero[V];
	q.push(mp(dis[s],s));
	while (!q.empty()) {
		u=q.top().se; q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		rep(j,0,SZ(e[u])) {
			v=e[u][j].fi,w=e[u][j].se;;
			if (vis[v]) continue;
			fg=1;
			node *c=add(dis[u],0,V-1,w);
			if (!fin[v]||cmp(c,dis[v])) {
				pre[v]=u;fin[v]=1;dis[v]=c;Dis[v]=(Dis[u]+pw2[w])%mod;
				q.push(mp(dis[v],v));
			}
		}
	}
	if (!fin[t]) return puts("-1"),0;
	else {
		printf("%d\n",Dis[t]);
		return 0;
		v=t; ans.pb(v);
		while (v!=s) v=pre[v],ans.pb(v);
		printf("%d\n",SZ(ans));
		per(i,1,SZ(ans)) printf("%d ",ans[i]);
		printf("%d\n",ans[0]);
	}
}