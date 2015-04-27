//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 14/08/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF ~0U>>1
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
const int N=320000;
int n,L,W;
LL Ans;
struct Vertice_Divide_and_Conquer
{
	private:
	vector<int> E[N],F[N];
	vector<pair<int,int> > Dis[N<<1];
	int rt,fa[N],vis[N],A[N],al,size[N],sub[N],dep[N],gs[N],Cnt,t[N];
	public:
	void add(int x,int y,int z){E[x].pb(y);E[y].pb(x);F[x].pb(z);F[y].pb(z);}
	void Dfs(int w,int Fa,int R,int dis,int lth,int par,int TT)
	{
		Dis[R].pb(mp(lth,dis));
		Dis[par].pb(mp(lth,dis));
		for (int i=0;i<E[w].size();i++)
		if (!vis[E[w][i]] && E[w][i]!=Fa)
		{
			if (par) Dfs(E[w][i],w,R,dis+1,lth+F[w][i],par,F[w][i]);
			else ++Cnt,Dfs(E[w][i],w,R,dis+1,lth+F[w][i],Cnt,TT);
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
	void T_add(int x,int c)
	{
		x++;
		if (x<0) return;
		for (int i=x;i<=n+10;i+=i&(-i)) t[i]+=c;
	}
	int T_ask(int x)
	{
		x++;
		if (x<0) return 0;
		int ans=0;
		for (int i=x;i;i-=i&(-i)) ans+=t[i];
		return ans;
	}
	void SORT(int x,int ty)
	{
		LL aa=0;
		int Last=Dis[x].size()-1;
		sort(Dis[x].begin(),Dis[x].end());
		//for (int i=0;i<Dis[x].size();i++) printf("%d %d\n",Dis[x][i].first,Dis[x][i].second);
		//puts("");
		for (int i=0;i<Dis[x].size();i++) T_add(Dis[x][i].second,1);
		for (int i=0;i<Dis[x].size();i++)
		if (Dis[x][i].first<=W)
		{
			while (Last>=0 && Dis[x][Last].first+Dis[x][i].first>W) T_add(Dis[x][Last].second,-1),Last--;
			aa+=(LL)ty*(LL)T_ask(L-Dis[x][i].second);
			if (Dis[x][i].first*2<=W && Dis[x][i].second*2<=L) aa-=ty;
		}
		while (Last>=0) T_add(Dis[x][Last].second,-1),Last--;
		Ans+=aa/2;
	}
	void dfs(int rt,int Fa)
	{
		vis[rt]=1;
		int CCnt=Cnt;
		Dfs(rt,Fa,rt,0,0,0,0);fa[rt]=Fa;
		SORT(rt,1);
		rep(i,CCnt+1,Cnt) SORT(i,-1);
		for (int i=0;i<E[rt].size();i++)
		if (!vis[E[rt][i]] && E[rt][i]!=Fa) dfs(Get_Center(E[rt][i],rt),rt);
	}
	void build()
	{
		Cnt=n+1;
		rt=Get_Center(1,0);
		dfs(rt,0);
	}
}VDC;
int m,x,y;
int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d%d%d",&n,&L,&W);
	rep(i,1,n-1) scanf("%d%d",&x,&y),VDC.add(x,i+1,y);
	VDC.build();
	printf("%lld\n",Ans);
}

