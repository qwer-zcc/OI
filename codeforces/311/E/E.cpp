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
typedef int sz[120000];
struct FLOW
{
	sz to,next,head,v,dis,di,g,pre,re,cost;
	int cnt,n,m;
	inline void add(int x,int y,int z)
	{
		if (x==y) return;
		to[++cnt]=y;next[cnt]=head[x];head[x]=cnt;g[cnt]=z;re[cnt]=cnt+1;
		to[++cnt]=x;next[cnt]=head[y];head[y]=cnt;g[cnt]=0;re[cnt]=cnt-1;
	}
	inline int sap()
	{
		int i=1;LL aug=INF,flow=0;v[0]=n;
		rep(i,1,n) di[i]=head[i];
		while (dis[1]<n)
		{
			int f=0;
			for (int p=di[i];p;p=next[p])
			if (dis[i]==dis[to[p]]+1 && g[p])
			{
				int j=to[p];di[i]=p;pre[j]=p;aug=min(aug,(LL)g[p]);i=j;
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
		return int(flow);
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
int n,m,extra,x,ans,is;
sz sex,val,Cnt;
int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d%d%d",&n,&m,&extra);
	rep(i,1,n) scanf("%d",&sex[i]);
	rep(i,1,n) scanf("%d",&val[i]);
	rep(i,1,n)
	{
		if (!sex[i]) Flow.add(1,i+1,val[i]);
		else Flow.add(i+1,n+m+2,val[i]);
	}
	rep(i,1,m)
	{
		scanf("%d%d%d",&sex[i],&val[i],&Cnt[i]);ans+=val[i];
		rep(j,1,Cnt[i])
		{
			scanf("%d",&x);
			if (!sex[i]) Flow.add(i+n+1,x+1,INF);
			else Flow.add(x+1,i+n+1,INF);
		}
		scanf("%d",&is);
		if (!sex[i]) Flow.add(1,i+n+1,val[i]+(is?extra:0));
		else Flow.add(i+n+1,n+m+2,val[i]+(is?extra:0));
	}
	Flow.n=n+m+2;
	printf("%d\n",ans-Flow.sap());
}

