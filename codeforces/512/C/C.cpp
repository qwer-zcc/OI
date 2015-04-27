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
typedef int sz[100000];
struct FLOW  //  is not very fast
{
	sz to,nxt,head,v,dis,di,g,pre,re,cost,vis;
	int cnt,n,m;
	inline void add(int x,int y,int z)
	{
		to[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;g[cnt]=z;re[cnt]=cnt+1;
		to[++cnt]=x;nxt[cnt]=head[y];head[y]=cnt;g[cnt]=0;re[cnt]=cnt-1;
	}
	int sap()
	{
		rep(i,1,n) di[i]=head[i],dis[i]=0;vis[0]=n;
		int i=1,aug=INF,flow=0;
		while (dis[1]<n)
		{
			int flag=0;
			for (int p=di[i];p;p=nxt[p])
			if (dis[i]==dis[to[p]]+1 && g[p])
			{
				int j=to[p];
				di[i]=p;pre[j]=p;aug=min(aug,g[p]);
				if (j==n)
				{
					flow+=aug;
					while (j!=1) i=pre[j],g[i]-=aug,g[re[i]]+=aug,j=to[re[i]];
					aug=INF;
				}
				i=j;flag=1;break;
			}
			if (flag) continue;
			int minx=n-1,il=0;
			for (int p=head[i];p;p=nxt[p]) if (g[p] && dis[to[p]]<minx) minx=dis[to[p]],il=p;
			vis[dis[i]]--;
			if (!vis[dis[i]]) break;
			dis[i]=minx+1;
			vis[dis[i]]++;
			di[i]=il;
			if (i!=1) i=to[re[pre[i]]];
		}
		return (int)flow;
		//printf("%lld\n",flow);
	}
	inline void add(int x,int y,int c,int d)
	{
	    to[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;g[cnt]=c;cost[cnt]=-d;re[cnt]=cnt+1;
	    to[++cnt]=x;nxt[cnt]=head[y];head[y]=cnt;g[cnt]=0;cost[cnt]=d;re[cnt]=cnt-1;
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
	        for (int p=head[i];p;p=nxt[p])
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
vector<int> E[1000],Ans[1000];
int a[1000],is[30000],n,ok[1000],ti;
void init()
{
	rep(i,2,25000) is[i]=1;
	rep(i,2,25000)
	{
		rep(j,2,int(sqrt(i)))
			if (i%j==0) {is[i]=0;break;}
	}
}
void dfs(int w,int an)
{
	Ans[ti].pb(w);
	ok[w]=1;
	for (int i=0;i<E[w].size();i++)
		if (!ok[E[w][i]]) {dfs(E[w][i],an);return;}
}
int main()
{
	//freopen("C.in","r",stdin);
	init();
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	int p=0;
	rep(i,1,n)
		if (a[i]&1) Flow.add(1,i+1,2),p++;
		else Flow.add(i+1,n+2,2);
	if (p!=n/2 || (n&1)) {puts("Impossible");return 0;}
	rep(i,1,n) rep(j,1,n)
		if (is[a[i]+a[j]] && (a[i]&1)) Flow.add(i+1,j+1,1);
	Flow.n=n+2;
	int ans=Flow.sap();
	if (ans!=n) {puts("Impossible");return 0;}
	rep(i,1,n)
		if (a[i]&1)
		{
			for (int p=Flow.head[i+1];p;p=Flow.nxt[p])
			if (!Flow.g[p] && Flow.to[p]>=2 && Flow.to[p]<=n+1) E[i].pb(Flow.to[p]-1),E[Flow.to[p]-1].pb(i);
		}
	rep(i,1,n)
		if (!ok[i]) ++ti,dfs(i,i);
	printf("%d\n",ti);
	rep(i,1,ti) {printf("%lu ",Ans[i].size());for (int j=0;j<Ans[i].size();j++) printf("%d ",Ans[i][j]);puts("");}
}
