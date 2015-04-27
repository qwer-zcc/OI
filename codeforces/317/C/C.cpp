//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 12/10/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF (~0U>>1)-3
#define LLINF ~0ULL>>1
#define LL long long
#define uLL unsigned long long
#define uint unsigned int
#define D double
#define LD long double
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define pb push_back
#define mp make_pair
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
template<class T> void read(T &x)
{
    char ch;
    while ((ch=getchar()) && !isdigit(ch));x=ch-'0';
    while ((ch=getchar()) && isdigit(ch)) x=x*10+ch-'0';
}
struct point
{
    int x,y;
    point() {}
    point(int _x,int _y) : x(_x),y(_y) {}
} ;
struct flow
{
	int x,y,c;
	flow() {}
	flow(int _x,int _y,int _c) : x(_x),y(_y),c(_c) {}
};
const int N=400;
vector<int> E[N];
LL sum;
int a[N],b[N],fa[N],n,v,m,vis[N],al;
LL Left[N],all[N];
vector<flow> Ans;
void dfs_check(int w,int Fa)
{
	sum+=(LL)(b[w]-a[w]);
	for (int i=0;i<E[w].size();i++)
	if (E[w][i]!=Fa) dfs_check(E[w][i],w);
}
int g_f(int x){return fa[x]==x?x:fa[x]=g_f(fa[x]);}
void dfs_all(int w,int Fa)
{
	all[w]=v-a[w];
	for (int i=0;i<E[w].size();i++)
	if (!vis[E[w][i]] && E[w][i]!=Fa)
	{
		dfs_all(E[w][i],w);
		all[w]+=all[E[w][i]];
	}
}
void dfs_Left(int w,int Fa)
{
	Left[w]=a[w];
	for (int i=0;i<E[w].size();i++)
	if (!vis[E[w][i]] && E[w][i]!=Fa)
	{
		dfs_Left(E[w][i],w);
		Left[w]+=Left[E[w][i]];
	}
}
void push(int w,int c,int Fa)
{
	if (v-a[w]>=c)
	{
		Ans.pb(flow(Fa,w,c));
		a[Fa]-=c;
		a[w]+=c;
		return;
	}
	int now=c,T=c-(v-a[w]);
	if (a[w]!=v) Ans.pb(flow(Fa,w,v-a[w])),a[Fa]-=v-a[w],a[w]=v;
	for (int i=0;i<E[w].size();i++)
	if (!vis[E[w][i]] && E[w][i]!=Fa)
	{
		int can=min(all[E[w][i]],(LL)now);
		push(E[w][i],can,w);
		now-=can;
		if (!now) break;
	}
	Ans.pb(flow(Fa,w,T));
	a[Fa]-=T;
	a[w]+=T;
}
void pull(int w,int c,int Fa)
{
	if (a[w]>=c)
	{
		Ans.pb(flow(w,Fa,c));
		a[Fa]+=c;
		a[w]-=c;
		return;
	}
	int now=c,T=c-a[w];
	if (a[w]) Ans.pb(flow(w,Fa,a[w])),a[Fa]+=a[w],a[w]=0;
	for (int i=0;i<E[w].size();i++)
	if (!vis[E[w][i]] && E[w][i]!=Fa)
	{
		int can=min(Left[E[w][i]],(LL)now);
		pull(E[w][i],can,w);
		now-=can;
		if (!now) break;
	}
	Ans.pb(flow(w,Fa,T));
	a[Fa]+=T;
	a[w]-=T;
}
void work(int x)
{
	if (a[x]==b[x]) return;
	else if (a[x]>b[x])
	{
		dfs_all(x,0);int now=a[x]-b[x];
		for (int i=0;i<E[x].size();i++)
		if (!vis[E[x][i]])
		{
			int c=min(all[E[x][i]],(LL)now);
			push(E[x][i],c,x);
			now-=c;
			if (!now) break;
		}
	}
	else if (a[x]<b[x])
	{
		dfs_Left(x,0);int now=b[x]-a[x];
		for (int i=0;i<E[x].size();i++)
		if (!vis[E[x][i]])
		{
			int c=min(Left[E[x][i]],(LL)now);
			pull(E[x][i],c,x);
			now-=c;
			if (!now) break;
		}
	}
}
int rd[N];
queue<int> Q;
int main()
{
	//freopen("C.in","r",stdin);
	scanf("%d%d%d",&n,&v,&m);int x,y;
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) scanf("%d",&b[i]);
	rep(i,1,n) fa[i]=i;
	rep(i,1,m)
	{
		scanf("%d%d",&x,&y);
		if (g_f(x)!=g_f(y)) fa[g_f(x)]=g_f(y),E[x].pb(y),E[y].pb(x),rd[x]++,rd[y]++;
	}
	rep(i,1,n)
	{
		dfs_check(i,0);
		if (sum!=0) {puts("NO");return 0;}
	}
	rep(i,1,n) if (rd[i]==1) Q.push(i);
	while (Q.size())
	{
		int x=Q.front();vis[x]=1;work(x);Q.pop();
		for (int i=0;i<E[x].size();i++)
		{
			rd[E[x][i]]--;
			if (rd[E[x][i]]==1) Q.push(E[x][i]);
		}
	}
	printf("%d\n",Ans.size());
	for (int i=0;i<Ans.size();i++) printf("%d %d %d\n",Ans[i].x,Ans[i].y,Ans[i].c);
}

