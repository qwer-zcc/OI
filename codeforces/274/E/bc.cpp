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

const int N=201000;
int n,m,k,x,y,dx,dy,bx[N],by[N];
char dir[10];
set<int> bk[N],pnt[N];
vector<PII> tv1[N],tv2[N];
ll ret;
void ff() {
	int px=x,py=y;
	if (dx==-1) px+=1;
	if (dy==-1) py+=1;
	if (!bk[px+dx].count(py+dy)) return;
	if ((bk[px+dx].count(py)^bk[px].count(py+dy))==0) dx*=-1, dy*=-1;
	else if (bk[px+dx].count(py)) dx*=-1; else dy*=-1;
}
int gg() {
	if (dx==1&&dy==1) return *pnt[x+m-y].upper_bound(x)-x;
	else if (dx==1&&dy==-1) return *pnt[x+y].upper_bound(x)-x;
	else if (dx==-1&&dy==1) return x-*(--pnt[x+y].lower_bound(x));
	else return x-*(--pnt[x+m-y].lower_bound(x));
}
void addpnt(int px,int py) {
	if ((px+py+x+y)%2==0) {
		pnt[px+py].insert(px);
		pnt[px+m-py].insert(px);
	}
}
void addrec(int d) {
	if (dx==1&&dy==1) tv1[x+m-y].pb(mp(x+1,x+d+1));
	else if (dx==-1&&dy==-1) tv1[x+m-y].pb(mp(x-d+1,x+1));
	else if (dx==1&&dy==-1) tv2[x+y].pb(mp(x+1,x+d+1));
	else tv2[x+y].pb(mp(x-d+1,x+1));
}
void gao(vector<PII> &a) {
	if (!SZ(a)) return;
	sort(all(a));
	ret+=a[0].se-a[0].fi;
	rep(i,1,SZ(a)) {
		a[i].fi=max(a[i-1].se,a[i].fi);
		a[i].se=max(a[i].se,a[i].fi);
		ret+=a[i].se-a[i].fi;
	}
}
int main() {
	freopen("E.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,k) scanf("%d%d",bx+i,by+i);
	scanf("%d%d%s",&x,&y,dir);
	if (dir[0]=='S') dx=1; else dx=-1;
	if (dir[1]=='E') dy=1; else dy=-1;
	if (dx==1) --x;
	if (dy==1) --y;
	addpnt(x,y);
	rep(i,0,n+1) addpnt(i,0),addpnt(i,m);
	rep(i,0,m+1) addpnt(0,i),addpnt(n,i);
	rep(i,1,n+1) bk[i].insert(0),bk[i].insert(m+1);
	rep(i,0,m+2) bk[0].insert(i),bk[n+1].insert(i);
	rep(i,0,k) {
		int cx=bx[i],cy=by[i];
		addpnt(cx-1,cy-1);
		addpnt(cx,cy-1);
		addpnt(cx-1,cy);
		addpnt(cx,cy);
		bk[cx].insert(cy);
	}
	int sx0=x,sy0=y,sx1=dx,sy1=dy;
	while (1) {
		int d=gg();
		addrec(d);
		x=x+d*dx; y=y+d*dy;
		ff();
		if (x==sx0&&y==sy0&&dx==sx1&&dy==sy1) break;
	}
	rep(i,0,n+m+1) gao(tv1[i]),gao(tv2[i]);
	printf("%I64d\n",ret);
}
