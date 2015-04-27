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
const int N=1200000;
struct lj
{
	int x,y,ty;
}E[N];
vector<int> L[N],R[N];
int NxtL[N],NxtR[N],Lmin[N],Lmax[N],Rmin[N],Rmax[N];
int n,m,vis[N],ti;
char s[100];
void dfs(int w)
{
	if (vis[w]) return;
	vis[w]=1;
	//vis[w]=ti;
	for (int i=0;i<L[w].size();i++)
	{
		dfs(L[w][i]);
		Lmax[w]=max(Lmax[w],L[w][i]);
		Lmax[w]=max(Lmax[w],max(Lmax[L[w][i]],Rmax[L[w][i]]));
		Lmin[w]=min(Lmin[w],L[w][i]);
		Lmin[w]=min(Lmin[w],min(Lmin[L[w][i]],Rmin[L[w][i]]));
	}
	for (int i=0;i<R[w].size();i++)
	{
		dfs(R[w][i]);
		Rmax[w]=max(Rmax[w],R[w][i]);
		Rmax[w]=max(Rmax[w],max(Lmax[R[w][i]],Rmax[R[w][i]]));
		Rmin[w]=min(Rmin[w],R[w][i]);
		Rmin[w]=min(Rmin[w],min(Lmin[R[w][i]],Rmin[R[w][i]]));
	}
}
void build(int l,int r)
{
	//printf("%d %d\n",l
	//if (l==95) printf("%d %d\n",l,r);
	if (l==r) return;
	if (!Rmax[l])
	{
		NxtL[l]=l+1;
		build(l+1,r);
		return;
	}
	if (!Lmax[l])
	{
		NxtR[l]=l+1;
		build(l+1,r);
		return;
	}
	if (Lmax[l]==r)
	{
		NxtL[l]=l+1;
		build(l+1,r);
		return;
	}
	if (Rmin[l]==l+1)
	{
		NxtR[l]=l+1;
		build(l+1,r);
		return;
	}
	NxtL[l]=l+1;
	NxtR[l]=Rmin[l];
	printf("%d %d    %d %d\n",l,r,l+1,Rmin[l]-1);
	build(l+1,Rmin[l]-1);
	printf("%d %d    %d %d\n",l,r,Rmin[l],r);
	build(Rmin[l],r);
}
void Mid(int w)
{
	if (NxtL[w]) Mid(NxtL[w]);
	printf("%d ",w);
	if (NxtR[w]) Mid(NxtR[w]);
}
void check(int w)
{
	if (!w) return;
	vis[w]=1;
	check(NxtL[w]);
	check(NxtR[w]);
}
int main()
{
	freopen("D.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,m)
	{
		scanf("%d%d",&E[i].x,&E[i].y);
		scanf("%s",s);
		if (s[0]=='L') E[i].ty=0;
		else E[i].ty=1;
	}
	rep(i,1,m)
	{
		if (E[i].x>=E[i].y) {puts("IMPOSSIBLE");return 0;}
	}
	rep(i,1,m)
		if (!E[i].ty) L[E[i].x].pb(E[i].y);
		else R[E[i].x].pb(E[i].y);
	rep(i,1,n) Lmin[i]=INF,Rmin[i]=INF;

	/*
	drep(i,n,1)
	{
		++ti;
		dfs(i);
	}
	*/
	drep(i,n,1)
	{
		for (int j=0;j<L[i].size();j++) Lmax[i]=max(Lmax[i],max(L[i][j],Lmax[L[i][j]]));
		int p=Lmax[i];
		rep(j,i,p) Lmax[i]=max(Lmax[i],Lmax[j]);
	}
	rep(i,1,n)
	{
		for (int j=0;j<R[i].size();j++) Rmax[i]=max(Rmax[i],max(R[i][j],max(Lmax[R[i][j]],Rmax[R[i][j]])));
	}
	drep(i,n,1)
	{
		for (int j=0;j<R[i].size();j++) Rmin[i]=min(Rmin[i],Rmin[R[i][j]]);
		drep(j,Rmin[i],i)
			if (Rmax[j]>Rmin[i]) Rmin[i]=min(Rmin[i],j);
	}


	rep(i,1,n) if (Lmax[i]>=Rmin[i]) {puts("IMPOSSIBLE");return 0;}
	build(1,n);
	Mid(1);
	puts("");
	
	rep(i,1,m)
	{
		rep(j,1,n) vis[j]=0;
		if (E[i].ty==0) check(NxtL[E[i].x]);
		else check(NxtR[E[i].x]);
		//rep(j,1,n) printf("%d ",vis[j]);puts("");
		if (!vis[E[i].y]) {printf("fail %d\n",i);}
	}

}
