#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define LL long long
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define clr(a) memset(a,0,sizeof(a));
using namespace std;
typedef int Restype;
struct FLOW
{
	static const int FM=220000,FN=20000;
	int cnt,n,dis[FN],pre[FN],to[FM],nxt[FM],head[FN],gap[FN],cur[FN],re[FM],g[FM];
	inline void add(int x,int y,int z)
	{
		++cnt;to[cnt]=y;nxt[cnt]=head[x];head[x]=cnt;g[cnt]=z;
		++cnt;to[cnt]=x;nxt[cnt]=head[y];head[y]=cnt;g[cnt]=0;
	}
	void init()
	{
		cnt=1;
		clr(dis);clr(pre);clr(head);clr(gap);clr(cur);
	}
	Restype sap()
	{
		int x=1;gap[0]=n;
		Restype flow=0;
		rep(i,1,n) cur[i]=head[i];
		while (dis[1]<=n)
		{
			while (cur[x] && (!g[cur[x]] || dis[to[cur[x]]]+1!=dis[x])) cur[x]=nxt[cur[x]];
			if (cur[x])
			{
				int y=to[cur[x]];
				pre[y]=cur[x]^1;
				x=y;
				if (x==n)
				{
					Restype aug=INF;
					for (int p=pre[n];p;p=pre[to[p]]) aug=min(aug,g[p^1]);
					for (int p=pre[n];p;p=pre[to[p]]) g[p^1]-=aug,g[p]+=aug;
					flow+=aug;x=1;
				}
			}
			else
			{
				gap[dis[x]]--;
				if (!gap[dis[x]]) break;
				cur[x]=head[x];
				int mdis=n;
				for (int j=head[x];j;j=nxt[j])
					if (g[j] && dis[to[j]]<mdis) mdis=dis[to[j]],cur[x]=j;
				dis[x]=mdis+1;
				gap[dis[x]]++;
				if (x!=1) x=to[pre[x]];
			}
		}
		return flow;
	}
}Flow;
const int N=120000;
int n,m,extra,x,ans,is;
int sex[N],val[N],Cnt[N];
int main()
{
	Flow.init();
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
