//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 30/10/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF ((~0U>>1)-3)
#define LLINF ((~0ULL>>1)-3)
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
struct FLOW
{
	typedef int sz[4100];
	sz to,next,head,v,dis,di,g,pre,re,cost,vis;
	int cnt,n,m,TIM;
	void clr(int _n)
	{
		n=_n;cnt=0;++TIM;
	}
	inline void add(int x,int y,int z)
	{
		if (x==y) return;
		if (vis[x]!=TIM) head[x]=0;
		if (vis[y]!=TIM) head[y]=0;
		vis[x]=vis[y]=TIM;
		to[++cnt]=y;next[cnt]=head[x];head[x]=cnt;g[cnt]=z;re[cnt]=cnt+1;
		to[++cnt]=x;next[cnt]=head[y];head[y]=cnt;g[cnt]=0;re[cnt]=cnt-1;
	}
	inline int sap()
	{
		int i=1;int aug=INF,flow=0;v[0]=n;
		rep(i,1,n) dis[i]=0;
		rep(i,1,n) di[i]=head[i];
		while (dis[1]<n)
		{
			int f=0;
			for (int p=di[i];p;p=next[p])
			if (dis[i]==dis[to[p]]+1 && g[p])
			{
				int j=to[p];di[i]=p;pre[j]=p;aug=min(aug,g[p]);i=j;
				if (j==n)
				{
					flow+=aug;
					while (j!=1) i=pre[j],g[i]-=aug,g[re[i]]+=aug,j=to[re[i]];
					aug=INF;i=1;
				}
				f=1;break;
			}
			if (f) continue;
			int minx=n-1,il=0;
			for (int p=head[i];p;p=next[p]) if (dis[to[p]]<minx && g[p]) minx=dis[to[p]],il=p;
			v[dis[i]]--;
			if (!v[dis[i]]) break;
			dis[i]=minx+1;
			v[dis[i]]++;
			di[i]=il;
			if (i!=1) i=to[re[pre[i]]];
		}
		return flow;
	}
	inline void add(int x,int y,int c,int d)
	{
	    to[++cnt]=y;next[cnt]=head[x];head[x]=cnt;g[cnt]=c;cost[cnt]=-d;re[cnt]=cnt+1;
	    to[++cnt]=x;next[cnt]=head[y];head[y]=cnt;g[cnt]=0;cost[cnt]=d;re[cnt]=cnt-1;
	}
	queue<int>r;
	int spfa()
	{
	    memset(v,0,sizeof(v));
	    rep(i,1,n) dis[i]=INF;
	    dis[1]=0;r.push(1);
	    while (r.size())
	    {
	        int i=r.front();r.pop();v[i]=0;
	        for (int p=head[i];p;p=next[p])
	        if (g[p]!=0 && dis[to[p]]>dis[i]+cost[p])
	        {
	            int j=to[p];dis[j]=dis[i]+cost[p];pre[j]=p;
	            if (!v[j]) r.push(j),v[j]=1;
	        }
	    }
	    return dis[n]!=INF;
	}
	void fyl()
	{
	    int mincost=0;
	    while (spfa())
	    {
	        int p=n,q,aug=INF,cl=0;
	        while (p!=1) {q=pre[p];aug=min(aug,g[q]);p=to[re[q]];}
	        mincost+=aug*dis[n];
	        p=n;
	        while (p!=1) {q=pre[p];g[q]-=aug;g[re[q]]+=aug;p=to[re[q]];}
	    }
	    printf("%d\n",-mincost);
	}
}Flow;
#define xx first
#define yy second
const int N=120000;
vector<int> E[N];
struct lj{int x,y,z,ok;}Edge[N],Ed[N],Fd[N];
int n,m,El,fa[N],ans,Cnt,ind[N],TIM,vis[N],Ans[N],al,Fl;
namespace flow
{
	const int maxn = 210, maxm = 5000;
	int C[maxm], with[maxm], f[maxm], op[maxm], nxt[maxm];
	int cur[maxn], gap[maxn], dis[maxn], head[maxn], _aug[maxn];
	int Index, aug, ans, T, S;
	queue <int> Q;
	pair<int,int>pre[maxn];
	
    void Aug()
    {
        ans += aug;
        for (int i = T; i != S; i = pre[i].xx)
            f[pre[i].yy] += aug, f[op[pre[i].yy]] -= aug;
    }	
    
	int SAP()
	{
		rep(i, 1, n) gap[i] = 0, dis[i] = n, _aug[i] = 0, cur[i] = head[i];
        ans = 0;
        aug = INF;
        dis[T] = 0;
        Q.push(T);
        while (Q.size())
        {
        	int u = Q.front(); Q.pop();
        	for (int i = head[u]; i; i = nxt[i])
        		if (!C[i] && dis[u] + 1 < dis[with[i]]) 
        		{
        			dis[with[i]] = dis[u] + 1;
        			Q.push(with[i]);
        		}
        }
        rep(i, 1, n) gap[dis[i]]++;
        int u = S;
        while (dis[S] < n)
        {
            _aug[u] = aug;
            bool flag = 1;
            for (int i = cur[u]; i; i = nxt[i])
            {
                int v = with[i];
                if (dis[v] + 1 == dis[u] && C[i] - f[i] > 0)
                {
                    cur[u] = i;
                    if (C[i] - f[i] < aug) aug = C[i] - f[i];
                    flag = 0, pre[v] = mp(u, i), u = v;
                    if (u == T) Aug(), u = S, aug = INF;
                    break;
                }
            }
            if (!flag) continue;
            if ((--gap[dis[u]]) == 0) return ans;
            dis[u] = n;
            cur[u]=head[u];
            for (int i = head[u]; i; i = nxt[i])
            {
                int v = with[i];
                if (dis[v] + 1 < dis[u] && C[i] - f[i] > 0) dis[u] = dis[v] + 1, cur[u] = i;
            }
            gap[dis[u]]++;
            if (u != S) u = pre[u].first, aug = _aug[u];
        }
        return ans;
	}
	
    inline void add(int x, int y, int c)
    {
	   	++Index;
    	with[Index] = y; nxt[Index] = head[x]; C[Index] = c; f[Index] = 0; head[x] = Index;
    	op[Index] = Index + 1;
    	++Index;
    	with[Index] = x; nxt[Index] = head[y]; C[Index] = f[Index] = 0; head[y] = Index;
    	op[Index] = Index - 1;
    }
    
	int main(int _S, int _T)
	{
		S = _S; T = _T;
		Index = 0;
		memset(head, 0, sizeof(head));
		rep(i, 1, m) add(Edge[i].x, Edge[i].y, Edge[i].z), add(Edge[i].y, Edge[i].x, Edge[i].z);
		return SAP();	
	}
}
inline int cmp(const lj &a,const lj &b) {return a.z>b.z;}
inline int g_f(int x){return fa[x]==x?x:fa[x]=g_f(fa[x]);}
inline int change(int w,int i,int j)
{
	if (w==1) return i;
	if (w==i) return 1;
	if (w==n) return j;
	if (w==j) return n;
	return w;
}
void dfs(int x,int Fa)
{
	Cnt++;ind[x]=TIM;
	for (int i=0;i<E[x].size();i++)
	if (!vis[E[x][i]] && E[x][i]!=Fa) dfs(E[x][i],x);
}
void solve(int x,int y)
{
	TIM++;
	Cnt=0;
	dfs(x,y);
	if (Cnt==1) {Ans[++al]=x;return;}
	int Min=int(1e8),ax=0,ay=0;
	rep(i,1,Fl)
	if (ind[Fd[i].x]==TIM && ind[Fd[i].y]==TIM && Fd[i].z<Min)
		Min=Fd[i].z,ax=Fd[i].x,ay=Fd[i].y;
	vis[ay]=1;solve(ax,ay);
	vis[ax]=1;vis[ay]=0;solve(ay,ax);
	vis[ax]=vis[ay]=1;
}
void Permutation()
{
	int Min=int(1e8),ax=0,ay=0;
	rep(i,1,Fl)
	if (Fd[i].z<Min)
		Min=Fd[i].z,ax=Fd[i].x,ay=Fd[i].y;
	vis[ay]=1;solve(ax,ay);vis[ax]=1;vis[ay]=0;solve(ay,ax);
	rep(i,1,n) printf("%d ",Ans[i]);
	puts("");
}
int main()
{
	//freopen("E.in","r",stdin);
	read(n);read(m);
	rep(i,1,m) read(Edge[i].x),read(Edge[i].y),read(Edge[i].z);
	rep(i,1,n) rep(j,i+1,n)
	{
		Ed[++El].x=i,Ed[El].y=j;Ed[El].z=flow::main(i,j);
		continue;
		Flow.clr(n);
		rep(_,1,m)
		{
			int x=Edge[_].x,y=Edge[_].y,z=Edge[_].z;
			x=change(x,i,j);y=change(y,i,j);
			Flow.add(x,y,z);Flow.add(y,x,z);
		}	
		Ed[++El].x=i;Ed[El].y=j;Ed[El].z=Flow.sap();
	}
	sort(Ed+1,Ed+El+1,cmp);
	rep(i,1,n) fa[i]=i;
	rep(i,1,El)
	{
		if (g_f(Ed[i].x)!=g_f(Ed[i].y))
		{
			E[Ed[i].x].pb(Ed[i].y);
			E[Ed[i].y].pb(Ed[i].x);
			Fd[++Fl]=Ed[i];
			ans+=Ed[i].z;
			fa[g_f(Ed[i].x)]=g_f(Ed[i].y);
			Ed[i].ok=1;
		}
	}
	printf("%d\n",ans);
	
	Permutation();
}
