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
const int N=210000;
pair<int,int> Rem[6000000];
vector<int> P[N];
int rl,n,m,u[N],v[N],fa[N],cnt[N],cur,ans[N];
int g_f(int x)
{
	if (fa[x]==x) return x;
	int p=g_f(fa[x]);
	Rem[++rl]=mp(x,fa[x]);
	fa[x]=p;
	return p;
}
void link(int x,int y)
{
	int p=g_f(x),q=g_f(y);
	if (p!=q)
	{
		Rem[++rl]=mp(p,fa[p]);
		fa[p]=q;
		Rem[++rl]=mp(-1,0);
		cur--;
	}
}
void build(int l,int r)
{
	rep(i,l,r)
	{
		for (int j=0;j<P[i].size();j++)
		{
			Rem[++rl]=mp(P[i][j],-1);
			cnt[P[i][j]]--;
			if (cnt[P[i][j]]==0) link(u[P[i][j]],v[P[i][j]]);
		}
	}
}
void clr(int top)
{
	while (rl>top)
	{
		if (Rem[rl].first==-1) cur++;
		else if (Rem[rl].second==-1) cnt[Rem[rl].first]++;
		else fa[Rem[rl].first]=Rem[rl].second;
		rl--;
	}
}
void solve(int l,int r)
{
	int top=rl;
	if (l==r)
	{
		ans[l]=(cur==1);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid);solve(mid+1,r);
	clr(top);
	build(mid+1,r);solve(l,mid);
}
int main()
{
	//freopen("E.in","r",stdin);
	freopen("disconnected.in","r",stdin);
	freopen("disconnected.out","w",stdout);
	scanf("%d%d",&n,&m);cur=n;int c,x,Q;
	rep(i,1,m) scanf("%d%d",&u[i],&v[i]);
	scanf("%d",&Q);
	rep(i,1,Q)
	{
		scanf("%d",&c);
		rep(_,1,c) scanf("%d",&x),P[i].pb(x),cnt[x]++;
	}
	rep(i,1,n) fa[i]=i;
	rep(i,1,m) if (!cnt[i]) link(u[i],v[i]);
	solve(1,Q);
	rep(i,1,Q) puts(ans[i]?"Connected":"Disconnected");
}
