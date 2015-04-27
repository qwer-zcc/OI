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
#define INF int(2e9)
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define Pi M_PI
#define clr(a) memset(a,0,sizeof(a));
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
const int N=510000;
struct seg{int l,r,c,flag;}t[N<<2];
priority_queue<pair<int,int> > Q;
vector<int> root;
vector<int> E[N];
int can[N],fa[N],cave[N],miner[N],tmp[N],rem,n,m,cover[N];
void dfs(int w,int Fa)
{
	can[w]=min(can[Fa],cave[w]);fa[w]=Fa;
	for (int i=0;i<E[w].size();i++)
		if (E[w][i]!=Fa) dfs(E[w][i],w);
}
void build(int w,int l,int r)
{
	t[w].l=l;t[w].r=r;
	if (l==r) {t[w].c=-l;return;}
	int mid=(l+r)>>1;
	build(w<<1,l,mid);build(w<<1|1,mid+1,r);
	t[w].c=min(t[w<<1].c,t[w<<1|1].c);
}
void push(int w)
{
	if (!t[w].flag) return;
	int l=w<<1;
	if (t[l].l) t[l].flag+=t[w].flag,t[l].c+=t[w].flag;
	l|=1;
	if (t[l].l) t[l].flag+=t[w].flag,t[l].c+=t[w].flag;
	t[w].flag=0;
}
void add(int w,int l,int r,int c)
{
	if (t[w].l==l && t[w].r==r)
	{
		t[w].c+=c;
		t[w].flag+=c;
		return;
	}
	push(w);
	int mid=(t[w].l+t[w].r)>>1;
	if (r<=mid) add(w<<1,l,r,c);
	else if (l>mid) add(w<<1|1,l,r,c);
	else add(w<<1,l,mid,c),add(w<<1|1,mid+1,r,c);
	t[w].c=min(t[w<<1].c,t[w<<1|1].c);
}
int ask()
{
	return t[1].c;
}
void add_sub(int w)
{
	int x=lower_bound(tmp+1,tmp+rem+1,can[w],greater<int>())-tmp;
	if (x<=rem) add(1,x,rem,1);
	cover[w]=x;
	for (int i=0;i<E[w].size();i++)
		if (E[w][i]!=fa[w]) add_sub(E[w][i]);
}
void Replay(int w)
{
	if (cover[w]<=rem) add(1,cover[w],rem,-1);
	can[w]=min(can[fa[w]],cave[w]);
	int x=lower_bound(tmp+1,tmp+rem+1,can[w],greater<int>())-tmp;
	if (x<=rem) add(1,x,rem,1);
	cover[w]=x;
	for (int i=0;i<E[w].size();i++)
		if (E[w][i]!=fa[w]) Replay(E[w][i]);
}
int main()
{
	freopen("A.in","r",stdin);
	scanf("%d",&n);int x,y;
	rep(i,1,n) scanf("%d",&cave[i]);
	rep(i,1,n-1) scanf("%d%d",&x,&y),E[x].pb(y),E[y].pb(x);
	scanf("%d",&m);
	rep(i,1,m) scanf("%d",&miner[i]);
	sort(miner+1,miner+m+1,greater<int>());
	can[0]=INF;
	dfs(1,0);
	Q.push(mp(can[1],1));
	int curin=0;
	while (Q.size())
	{
		curin++;
		pair<int,int> x=Q.top();Q.pop();
		if (x.first<miner[curin])
		{
			rem=m-curin+1;
			rep(i,1,rem) tmp[i]=miner[i+curin-1];
			build(1,1,m-curin+1);
			if (ask()>=0) {puts("0");return 0;}
			int ans=INF;
			root.clear();root.pb(x.second);
			while (Q.size()) root.pb(Q.top().second),Q.pop();
			for (int i=0;i<root.size();i++)
				add_sub(root[i]);
			for (int i=0;i<root.size();i++)
			{
				int t=cave[root[i]];
				cave[root[i]]=miner[curin];
				Replay(root[i]);
				cave[root[i]]=t;
				if (ask()>=0) ans=min(ans,max(miner[curin]-cave[root[i]],0));
				Replay(root[i]);
			}
			if (ans==INF) {puts("-1");return 0;}
			printf("%d\n",ans);
			return 0;
		}
		for (int i=0;i<E[x.second].size();i++)
			if (E[x.second][i]!=fa[x.second])
			{
				Q.push(mp(can[E[x.second][i]],E[x.second][i]));
			}
	}
	puts("0");
}
