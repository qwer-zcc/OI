//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 02/11/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF ((~0U>>1)-3)
#define LLINF (~0ULL>>1)
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
LL Pow(LL a,LL b,LL Mod){LL ans=1;a%=Mod;for(;b;b>>=1) ans=b&1?(ans*a%Mod):ans,a=a*a%Mod;return ans;}
const int N=220000;
int col[N];
struct Vertice_Divide_and_Conquer
{
	private:
	vector<int> E[N],DIS[N];
	vector<pair<int,int> > Dis[N],An[N];
	int n,rt,fa[N],vis[N],A[N],al,size[N],sub[N],f[N][19],dep[N],gs[N],Cnt;
	map<pair<int,int> , int> Hash;
	public:
	void add(int x,int y){E[x].pb(y);E[y].pb(x);}
	void Dfs(int w,int Fa,int R,int dis,int par)
	{
		An[w].pb(mp(R,Cnt));Dis[R].pb(mp(dis,0));
		Dis[par].pb(mp(dis-1,0));
		for (int i=0;i<E[w].size();i++)
		if (!vis[E[w][i]] && E[w][i]!=Fa)
		{
			if (par) Dfs(E[w][i],w,R,dis+1,par);
			else ++Cnt,Dfs(E[w][i],w,R,dis+1,Cnt);
		}
	}
	void Subsize(int x,int Fa)
	{
		A[++al]=x;size[x]=sub[x]=1;
		for (int i=0;i<E[x].size();i++)
		if (!vis[E[x][i]] && E[x][i]!=Fa)
		{
			Subsize(E[x][i],x);
			size[x]+=size[E[x][i]];
			sub[x]=max(sub[x],size[E[x][i]]);
		}
	}
	int Get_Center(int x,int Fa)
	{
		al=0;
		Subsize(x,Fa);
		rep(i,1,al) sub[A[i]]=max(sub[A[i]],al-size[A[i]]);
		int ans=0;
		rep(i,1,al) if (sub[A[i]]<=(al+1)/2) return A[i];
	}
	void SORT(int x)
	{
		sort(Dis[x].begin(),Dis[x].end());
		for (int i=0;i<Dis[x].size();i++) gs[Dis[x][i].first]++;
		for (int i=0;i<Dis[x].size();i++) Dis[x][i]=mp(Dis[x][i].first,gs[Dis[x][i].first]);
		for (int i=1;i<Dis[x].size();i++)
		if (Dis[x][i].first!=Dis[x][i-1].first) Dis[x][i]=mp(Dis[x][i].first,Dis[x][i].second+Dis[x][i-1].second);
		else Dis[x][i]=Dis[x][i-1];
		for (int i=0;i<Dis[x].size();i++) gs[Dis[x][i].first]--;
		DIS[x].pb(Dis[x][0].second);
		for (int i=1;i<Dis[x].size();i++)
		if (Dis[x][i].first!=Dis[x][i-1].first) DIS[x].pb(Dis[x][i].second);
	}
	void dfs(int rt,int Fa,int dep)
	{
		vis[rt]=1;col[rt]=dep;
		int CCnt=Cnt;
		Dfs(rt,Fa,rt,0,0);fa[rt]=Fa;
		//SORT(rt);
		//rep(i,CCnt+1,Cnt) SORT(i);
		for (int i=0;i<E[rt].size();i++)
		if (!vis[E[rt][i]] && E[rt][i]!=Fa) dfs(Get_Center(E[rt][i],rt),rt,dep+1);
	}
	void Dep_dfs(int w,int Fa)
	{
		f[w][0]=Fa;dep[w]=dep[Fa]+1;
		for (int i=0;i<E[w].size();i++)
		if (E[w][i]!=Fa) Dep_dfs(E[w][i],w);
	}
	void dp() {rep(j,1,17) rep(i,1,n*2-1) f[i][j]=f[f[i][j-1]][j-1];}
	int lca(int x,int y)
	{
	    if (dep[x]<dep[y]) swap(x,y);
	    drep(i,17,0)
	    if (dep[f[x][i]]>=dep[y]) x=f[x][i];
	    if (x==y) return x;
	    drep(i,17,0)
	    if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	    return f[x][0];
	}
	int Len(int a,int b)
	{
		int z=lca(a,b);
		return dep[a]+dep[b]-dep[z]*2;
	}
	void build(int nn)
	{
		n=nn;
		Cnt=n+1;
		Dep_dfs(1,0);
		dp();
		rt=Get_Center(1,0);
		dfs(rt,0,0);
	}
	int Len_Num(int x,int c)
	{
		if (c<0) return 0;
		if (c>=DIS[x].size()) return DIS[x][DIS[x].size()-1];
		return DIS[x][c];
		vector<pair<int,int> >::iterator It;
		It=lower_bound(Dis[x].begin(),Dis[x].end(),mp(c,0));
		if (It==Dis[x].end()||It->first!=c) It--;
		return It->second;
	}
}VDC;
int n,x,y;
int main()
{
	//freopen("C.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n-1) scanf("%d%d",&x,&y),VDC.add(x,y);
	VDC.build(n);
	rep(i,1,n) printf("%c ",col[i]+'A');puts("");
}

