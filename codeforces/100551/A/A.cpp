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
const int N=2020000;
map<pair<int,int>,int> Hash;
pair<int,int> st[N];
struct lj{int x,y,id,ty;}opt[N];
int fa[N],n,m,stcnt,ans[N],L[N],R[N],cur,cnt;
int g_f(int x)
{
	if (fa[x]==x) return x;
	int p=fa[x];
	fa[x]=g_f(fa[x]);
	st[++stcnt]=mp(x,p);
	return fa[x];
}
void link(int x,int y)
{
	int p=g_f(x),q=g_f(y);
	if (p!=q)
	{
		st[++stcnt]=mp(p,fa[p]);
		fa[p]=q;cur--;
		st[++stcnt]=mp(0,0);
	}
}
void reload(int stL)
{
	while (stcnt>stL)
	{
		if (st[stcnt].first==0) cur++;
		else fa[st[stcnt].first]=st[stcnt].second;
		stcnt--;
	}
}
void solve(int l,int r)
{
	if (l>r) return;
	int stL=stcnt;
	if (l==r) {if (opt[l].ty==3) ans[l]=cur;return;}
	int mid=(l+r)>>1;
	rep(i,mid+1,r)
		if (opt[i].ty==2 && L[opt[i].id]<l) link(opt[i].x,opt[i].y);
	solve(l,mid);
	reload(stL);
	rep(i,l,mid)
		if (opt[i].ty==1 && (!R[opt[i].id]||R[opt[i].id]>r)) link(opt[i].x,opt[i].y);
	solve(mid+1,r);
	reload(stL);
}
char s[10];
int main()
{
	freopen("connect.in","r",stdin);
	freopen("connect.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n) fa[i]=i;cur=n;
	rep(i,1,m)
	{
		scanf("%s",s);
		if (s[0]=='?') opt[i].ty=3;
		else if (s[0]=='+')
		{
			opt[i].ty=1;
			scanf("%d%d",&opt[i].x,&opt[i].y);
			if (opt[i].x>opt[i].y) swap(opt[i].x,opt[i].y);
			opt[i].id=++cnt;
			Hash[mp(opt[i].x,opt[i].y)]=cnt;
			L[cnt]=i;
		}
		else if (s[0]=='-')
		{
			opt[i].ty=2;
			scanf("%d%d",&opt[i].x,&opt[i].y);
			if (opt[i].x>opt[i].y) swap(opt[i].x,opt[i].y);
			opt[i].id=Hash[mp(opt[i].x,opt[i].y)];
			R[opt[i].id]=i;
			Hash[mp(opt[i].x,opt[i].y)]=0;
		}
	}
	solve(1,m);
	rep(i,1,m) if (opt[i].ty==3) printf("%d\n",ans[i]);
}
