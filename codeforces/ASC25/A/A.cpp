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
namespace KM
{
	const int N=1000;
	vector<int> E[N],F[N];
	int n,m,lx[N],ly[N],l[N],vx[N],vy[N],cnt,sl[N],pos[N];
	int val[N][N];
	void init(int _n,int _m)
	{
		n=_n;m=_m;
		rep(i,1,n) E[i].clear(),F[i].clear(),lx[i]=INF;
		rep(i,1,m) ly[i]=l[i]=0;
	}
	void add(int x,int y,int z)
	{
		E[x].pb(y);F[x].pb(z);val[x][y]=z;
	}
	int dfs(int x)
	{
		vx[x]=cnt;
		for (int i=0;i<E[x].size();i++)
		{
			int y=E[x][i];
			if (lx[x]+ly[y]<F[x][i]) sl[y]=min(sl[y],-lx[x]-ly[y]+F[x][i]);
			else if (vy[y]!=cnt)
			{
				vy[y]=cnt;
				if (!l[y] || dfs(l[y])) {l[y]=x;return 1;}
			}
		}
		return 0;
	}
	int solve()
	{
		rep(i,1,n) for (int j=0;j<F[i].size();j++) lx[i]=min(lx[i],F[i][j]);
		rep(i,1,n)
		{
			rep(j,1,m) sl[j]=INF;cnt++;
			while (!dfs(i))
			{
				int d=INF;
				rep(j,1,m) if (vy[j]!=cnt) d=min(d,sl[j]);
				rep(j,1,n) if (vx[j]==cnt) lx[j]+=d;
				rep(j,1,m) if (vy[j]==cnt) ly[j]-=d;
				rep(j,1,m) sl[j]=INF;
				cnt++;
			}
		}
		int ans=0;
		rep(i,1,m)
			if (l[i]) ans+=val[l[i]][i],pos[l[i]]=i;
		return ans;
	}
}
struct point{int x,y;}P[1000],Q[1000];
int n,m,x,y,k,s,ql,v[1000],ok[1000];
bool vis[1000][1000];
inline int dis(point x,point y) {return abs(x.x-y.x)+abs(x.y-y.y);}
inline int DIS(point x,point y)
{
	return dis(x,y)*500+y.x*50+y.y;
}
int main()
{
	freopen("agrarian.in","r",stdin);
	freopen("agrarian.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&s);
	rep(i,1,k) scanf("%d%d",&P[i].x,&P[i].y),vis[P[i].x][P[i].y]=1;
	rep(i,1,s) scanf("%d%d",&x,&y),vis[x][y]=1;
	rep(i,1,n)
		rep(j,1,m) if (!vis[i][j]) Q[++ql].x=i,Q[ql].y=j;
	n=k;m=ql;
	KM::init(n,m);
	rep(i,1,n)
		rep(j,1,m) KM::add(i,j,dis(P[i],Q[j]));
	KM::solve();
	rep(i,1,n)
	{
		drep(j,n,1)
		if (!v[j])
		{
			int flag=1,cur=INF,pl=0;
			rep(l,1,m)
				if (!ok[l] && DIS(P[j],Q[l])<cur) cur=DIS(P[j],Q[l]),pl=l;
			if (!KM::l[pl]) KM::pos[j]=pl;
			else if (pl!=KM::pos[j]) flag=0;
			if (flag) printf("%d ",j),v[j]=1,ok[KM::pos[j]]=1;
		}
	}
	puts("");
}
