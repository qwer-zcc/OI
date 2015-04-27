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
const int N=310000;
struct Tri
{
	int x,y,z;
	Tri(){}
	Tri(int _x,int _y,int _z) : x(_x),y(_y),z(_z) {}
};
struct lj
{
	int x,y,id,ty;
}opt[N];
Tri Rem[3000000];
vector<int> E[N];
map<pair<int,int>,int> Hash;
int rl,n,m,L[N],R[N],fa[N],dep[N],cur,ans[N],cnt;
struct dsu
{
	int n,fa[N],ty;
	dsu(){}
	dsu(int _n,int _ty) : n(_n),ty(_ty) {rep(i,1,n) fa[i]=i;}
	int g_f(int x) {return fa[x]==x?x:fa[x]=g_f(fa[x]);}
	int get_f(int x)
	{
		if (fa[x]==x) return x;
		int p=get_f(fa[x]);
		Rem[++rl]=Tri(x,fa[x],ty);
		fa[x]=p;
		return p;
	}
	void link(int x,int y)
	{
		int p=get_f(x),q=get_f(y);
		Rem[++rl]=Tri(p,fa[p],ty);
		fa[p]=q;
	}
}d1,d2;
void link(int x,int y)
{
	if (d1.get_f(x)!=d1.get_f(y))
	{
		d1.link(x,y);
		Rem[++rl]=Tri(0,-1,0);
		cur++;
	}
	else
	{
		x=d2.get_f(x),y=d2.get_f(y);
		while (x!=y)
		{
			if (dep[x]<dep[y]) swap(x,y);
			d2.link(x,d2.get_f(fa[x]));
			x=d2.get_f(x);
			Rem[++rl]=Tri(0,-2,0);
			cur--;
		}
	}
}
void reload(int top)
{
	for(;rl>top;rl--)
	{
		if (Rem[rl].z==1) d1.fa[Rem[rl].x]=Rem[rl].y;
		else if (Rem[rl].z==2) d2.fa[Rem[rl].x]=Rem[rl].y;
		else if (Rem[rl].y==-1) cur--;
		else if (Rem[rl].y==-2) cur++;
	}
}
void solve(int l,int r)
{
	if (r==m) printf("l = %d  r = %d  cur = %d\n",l,r,cur);
	if (l>r) return;
	int top=rl;
	if (l==r) {if (opt[l].ty==3) ans[l]=cur;return;}
	int mid=(l+r)>>1;
	rep(i,mid+1,r)
		if (opt[i].ty==2 && L[opt[i].id]<l) link(opt[i].x,opt[i].y);
	solve(l,mid);
	reload(top);
	rep(i,l,mid)
		if (opt[i].ty==1 && (!R[opt[i].id]||R[opt[i].id]>r))
		{
			if (r==m) printf("%d %d    %d %d\n",opt[i].x,opt[i].y,l,r);
			link(opt[i].x,opt[i].y);
		}
	solve(mid+1,r);
	reload(top);
}
void Link(int x,int y)
{
	int p=d1.g_f(x),q=d2.g_f(y);
	if (p==q) return;
	d1.link(p,q);
	E[x].pb(y);E[y].pb(x);
}
void dfs(int w,int Fa)
{
	fa[w]=Fa;dep[w]=dep[Fa]+1;
	for (int i=0;i<E[w].size();i++)
		if (E[w][i]!=Fa) dfs(E[w][i],w);
}
char s[10];
int main()
{
	freopen("D.in","r",stdin);
	scanf("%d%d",&n,&m);d1=dsu(n,1),d2=dsu(n,2);
	rep(i,1,m)
	{
		int id=i*2-1;
		scanf("%s",s);
		if (s[0]=='A')
		{
			opt[id].ty=1;
			scanf("%d%d",&opt[id].x,&opt[id].y);Link(opt[id].x,opt[id].y);
			if (opt[id].x>opt[id].y) swap(opt[id].x,opt[id].y);
			opt[id].id=++cnt;
			Hash[mp(opt[id].x,opt[id].y)]=cnt;
			L[cnt]=id;
		}
		else if (s[0]=='D')
		{
			opt[id].ty=2;
			scanf("%d%d",&opt[id].x,&opt[id].y);
			if (opt[id].x>opt[id].y) swap(opt[id].x,opt[id].y);
			opt[id].id=Hash[mp(opt[id].x,opt[id].y)];
			R[opt[id].id]=id;
			Hash[mp(opt[id].x,opt[id].y)]=0;
		}
		opt[i<<1].ty=3;
	}
	rep(i,1,n) if (!dep[i]) dfs(i,0);d1=dsu(n,1);
	m<<=1;
	solve(1,m);
	rep(i,1,m) if (opt[i].ty==3) printf("%d\n",ans[i]);
}
