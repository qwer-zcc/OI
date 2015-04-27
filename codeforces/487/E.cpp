//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 30/10/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF (int(2e9))
#define LLINF ((LL)(1e18))
#define LL long long
#define uLL unsigned long long
#define uint unsigned int
#define D double
#define LD long double
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define pb push_back
#define mp make_pairw
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
template<class T> void read(T &x)
{
    char ch;
    while ((ch=getchar()) && !(ch>='0'&&ch<='9'));x=ch-'0';
    while ((ch=getchar()) && (ch>='0'&&ch<='9')) x=x*10+ch-'0';
}
struct point
{
    int x,y;
    point() {}
    point(int _x,int _y) : x(_x),y(_y) {}
} ;
LL Pow(LL a,LL b,LL mod) {LL res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL Pow(LL a,LL b) {LL res=1;for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
#define Dfn(x) HLD.DFN(x)
#define an(x) HLD.AN(x)
const int N=120000;
vector<int> E[N];
set<pair<int,int> > val[N];
int dfn[N],low[N],n,ti,w[N],num,be[N],cut[N],cl,is[N];
pair<int,int> st[N];
struct Heavy_Light_Decomposition
{
    private:
    	struct Tree{int l,r,Min;}t[N<<2];
    	vector<int> E[N];
    	int ti,n,f[N][22],dep[N],An[N],dfn[N],size[N],low[N];
        void dp() {rep(j,1,20) rep(i,1,n) f[i][j]=f[f[i][j-1]][j-1];}
        int lca(int x,int y)
		{
			if (dep[x]<dep[y]) swap(x,y);
			drep(i,20,0)
			if (dep[f[x][i]]>=dep[y]) x=f[x][i];
			if (x==y) return x;
			drep(i,20,0)
			if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
			return f[x][0];
		}
		void dfs(int w,int Fa)
		{
			dep[w]=dep[Fa]+1;f[w][0]=Fa;size[w]=1;
			for (int i=0;i<E[w].size();i++)
			if (E[w][i]!=Fa) dfs(E[w][i],w),size[w]+=size[E[w][i]];
		}
		void Dfs(int x,int Fa,int c)
		{
			dfn[x]=++ti;An[x]=c;
			int Max=0,il=0;
			for (int i=0;i<E[x].size();i++)
			if (E[x][i]!=Fa) if (size[E[x][i]]>Max) Max=size[E[x][i]],il=E[x][i];
			if (il) Dfs(il,x,c);
			for (int i=0;i<E[x].size();i++)
			if (E[x][i]!=Fa && E[x][i]!=il) Dfs(E[x][i],x,E[x][i]);
		}
		void update(int w)
		{
			t[w].Min=min(t[w<<1].Min,t[w<<1|1].Min);
		}
		void build(int w,int l,int r)
		{
			t[w].l=l;t[w].r=r;t[w].Min=INF;
			if (l==r) return;
			int mid=l+r>>1;
			build(w<<1,l,mid);build(w<<1|1,mid,r);
		}
		void change(int w,int l,int c)
		{
			if (t[w].l==t[w].r) {t[w].Min=c;return;}
			int mid=t[w].l+t[w].r>>1;
			if (l<=mid) change(w<<1,l,c);
			else change(w<<1|1,l,c);
			update(w);
		}
		int ask_min(int w,int l,int r)
		{
			if (t[w].l==l && t[w].r==r) return t[w].Min;
			int mid=l+r>>1;
			if (r<=mid) return ask_min(w<<1,l,r);
			else if (l>mid) return ask_min(w<<1|1,l,r);
			else return min(ask_min(w<<1,l,mid),ask_min(w<<1|1,mid+1,r));
		}
    public:
        inline int Ask_Min(int x,int y){return ask_min(1,x,y);}
        inline int Ask_Max(int x,int y){}
        inline int DFN(int x) {return dfn[x];}
        inline int AN(int x) {return An[x];}
        inline void Change_Val(int x,int c){change(1,x,c);}
        inline void Insert(int x,int y) {E[x].pb(y),E[y].pb(x);}
        inline void Init(int nn)
        {
        	n=nn;
        	dfs(1,0);Dfs(1,0,1);
        	build(1,1,n);
        }
        /*
        inline int Ask(int x,int y)
        {
        	x=be[x],y=be[y];
        	if (x==y) return w[x];
        	int ans=INF;
        	while (An[x]!=An[y])
        	{
        		if (dep[An[x]]<dep[An[y]]) swap(x,y);
        		ans=min(ans,ask_min(1,dfn[An[x]],dfn[x]));
        		x=f[An[x]][0];
        	}
        	if (dep[x]>dep[y]) swap(x,y);
        	ans=min(ans,ask(1,dfn[x],dfn[y]));
        	if (!is[x] && f[x][0]) ans=min(ans,
        }
        */
        inline int Ask(int x,int y)
        {
        	return 0;
        }
}HLD;
void dfs(int w,int Fa)
{
	printf("%d   %d\n",w,E[w].size());
    dfn[w]=low[w]=++ti;
    st[++num]=mp(Fa,w);
    for (int i=0;i<E[w].size();i++)
    {
        int x=E[w][i];
        //printf("   x = %d %d %d\n",x,Fa,dfn[x]);
        if (x!=Fa)
        {
        	if (!dfn[x])
        	{
        		dfs(x,w);
        		if (low[x]>=dfn[w])
        		{
        			cut[++cl]=w;is[w]=1;
        			do
        			{
        				be[st[num].first]=be[st[num].second]=cl;
        				num--;
        			}while (st[num+1].first!=w||st[num+1].second!=x);
        		}
        		else low[w]=min(low[w],low[x]);
        	}
        	else low[w]=min(low[w],dfn[x]);
        }
    }
    printf("%d\n",w);
}
void tarjan()
{
    rep(i,1,n)
    if (!dfn[i]) dfs(i,0);
}
map<pair<int,int> ,int > vis;
void ReEdge()
{
	rep(i,1,n)
	{
		for (int j=0;i<E[i].size();j++)
		if (!vis.count(mp(be[i],be[E[i][j]])))
		{
			HLD.Insert(be[i],be[E[i][j]]);
			HLD.Insert(be[E[i][j]],be[i]);
			vis[mp(be[i],be[E[i][j]])]=1;
			vis[mp(be[E[i][j]],be[i])]=1;
		}
	}
	rep(i,1,n) val[be[i]].insert(mp(w[i],i));
}
void Change(int x,int c)
{
	val[be[x]].erase(mp(w[x],x));
	w[x]=c;val[be[x]].insert(mp(w[x],x));
	HLD.Change_Val(Dfn(be[x]),val[be[x]].begin()->first);
}
int m,q;
int main()
{
	freopen("E.in","r",stdin);
	scanf("%d%d%d",&n,&m,&q);char s[3],x,y;
    rep(i,1,n) scanf("%d",&w[i]);
    rep(i,1,m) scanf("%d%d",&x,&y),E[x].pb(y),E[y].pb(x);
    tarjan();
    rep(i,1,n) printf("%d ",be[i]);puts("");
    return 0;
    ReEdge();
    HLD.Init(cl);
    rep(i,1,cl) HLD.Change_Val(Dfn(cl),val[cl].begin()->first);
    rep(i,1,q)
    {
    	scanf("%s%d%d",s,&x,&y);
    	if (s[0]=='A') Change(x,y);
    	else printf("%d\n",HLD.Ask(x,y));
    }
}
