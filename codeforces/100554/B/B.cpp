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
#include <stack>
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
const int N=410000;
vector<pair<int,int> >E[N];
int size[N],sub[N],up[N],Len[N],n,dis[N],nl,need[N],Ok[N],cover[N];
vector<int> center;
void clr()
{
	rep(i,1,n+10) E[i].clear();
	center.clear();
	rep(i,1,n+10) size[i]=sub[i]=up[i]=Len[i]=dis[i]=need[i]=0;
	nl=0;
}
void dfs(int w,int Fa)
{
	size[w]=1;
	for (int i=0;i<E[w].size();i++)
		if (E[w][i].first!=Fa)
		{
			dfs(E[w][i].first,w);
			sub[w]=max(sub[w],size[E[w][i].first]);
			size[w]+=size[E[w][i].first];
		}
}
void dfs2(int w,int Fa,int c)
{
	up[w]=c;
	for (int i=0;i<E[w].size();i++)
		if (E[w][i].first!=Fa)
			dfs2(E[w][i].first,w,c+size[w]-size[E[w][i].first]);
}
void Erase(int x,int y)
{
	for(vector<pair<int,int> >::iterator It=E[x].begin();It!=E[x].end();It++)
		if (It->first==y) {E[x].erase(It);break;}
}
void link(int x,int y,int c)
{
	E[x].pb(mp(y,c+1));
	E[y].pb(mp(x,c+1));
}
void combine()
{
	Erase(center[0],center[1]);
	Erase(center[1],center[0]);
	link(n+1,center[0],0);
	link(n+1,center[1],0);
	center.clear();
	center.pb(n+1);
}
void Find_Center()
{
	center.clear();
	dfs(1,0);dfs2(1,0,0);
	rep(i,1,n)
		if (max(sub[i],up[i])<=n/2) center.pb(i);
	if (center.size()>1) combine();
}
void dfs3(int w,int Fa,int limit)
{
	Ok[w]=1;
	vector<int> pre,nxt;
	pre.clear();nxt.clear();
	for (int i=0;i<E[w].size();i++)
		if (E[w][i].first!=Fa)
		{
			dfs3(E[w][i].first,w,limit);
			if (cover[E[w][i].first]>=E[w][i].second) Ok[w]=0;
			cover[w]=max(cover[w],cover[E[w][i].first]-E[w][i].second);
		}
	if (E[w].size()>=1)
	{
		pre.pb(cover[E[w][0].first]-E[w][0].second);
		for (int i=1;i<E[w].size();i++)
			pre.pb(max(pre[i-1],cover[E[w][i].first]-E[w][i].second));
	}
	for (int i=0;i<E[w].size();i++) nxt.pb(0);
	if (E[w].size()>=1)
	{
		nxt.pb(cover[E[w][E[w].size()-1].first]-E[w][E[w].size()-1].second);
		if (E[w].size()>=2)
		{
			for (int i=E[w].size()-2;i>=0;i--) nxt[i]=max(nxt[i+1],cover[E[w][i].first]-E[w][i].second);
		}
	}
	for (int i=0;i<E[w].size();i++)
		if (E[w][i].first!=Fa)
			if (Len[E[w][i].first] || Ok[E[w][i].first])
			{
				int p=Len[E[w][i].first]+E[w][i].second,q=cover[E[w][i].first];
				q=max(q,pre[i]-E[w][i].second);
				q=max(q,nxt[i]-E[w][i].second);
				if (p>q) Len[w]=max(Len[w],p);
//				if (w==3) printf("             %d %d\n",p,q);
//				Len[w]=max(Len[w],Len[E[w][i].first]+E[w][i].second-max(cover[E[w][i].first],cover[w]));
			}
	//if (E[w].size()==1 && E[w][0].first==Fa) Ok[w]=1;
//	printf("%d %d %d\n",w,cover[w],Len[w]);
	if (Len[w]>=limit && Len[w]>cover[w])
	{
//		printf("w = %d\n",w);
		need[nl++]=w;
		Ok[w]=0;
		cover[w]=limit;
		Len[w]=0;
	}
//	printf("%d %d %d\n",w,cover[w],Len[w]);
}
void dfs4(int w,int Fa)
{
	for (int i=0;i<E[w].size();i++)
		if (E[w][i].first!=Fa)
		{
			dis[E[w][i].first]=min(dis[E[w][i].first],dis[w]+E[w][i].second);
			dfs4(E[w][i].first,w);
		}
}
int check(int mid)
{
	nl=0;
	dfs3(center[0],0,mid);
//	printf("        %d   %d\n",center[0],nl);
	if (nl==1 && need[0]!=center[0]) need[nl++]=center[0];
	rep(i,1,n+1) dis[i]=INF,Ok[i]=0,Len[i]=cover[i]=0;
//	printf("%d %d            nl = %d\n",need[0],need[1],nl);
	if (nl==0) {need[nl++]=1;return 1;}
	dis[need[0]]=0;
	dfs4(need[0],0);
	if (nl>1) dis[need[1]]=0,dfs4(need[1],0);
//	rep(i,1,n) printf("%d ",dis[i]);puts("");
	rep(i,1,n)
		if (dis[i]>mid) return 0;
	return 1;
}
void work(int ti)
{
	scanf("%d",&n);int x,y;
//	if (ti==814) printf("%d\n",n);
	clr();
	rep(i,1,n-1)
	{
		scanf("%d%d",&x,&y),link(x,y,1);
//		if (ti==814) printf("%d %d\n",x,y);
	}
	//return;
	Find_Center();
	int mid,ans,l=1,r=n/2;
//	printf("%d\n",check(4));
//	printf("%d\n",check(8));
//	printf("%d\n",check(4));
//	return;
	while (l<=r)
	{
		mid=(l+r)>>1;
//		printf("%d %d %d %d    %d\n",l,r,mid,ans,check(mid*2));
		if (check(mid*2)) ans=mid*2,r=mid-1;else l=mid+1;
	}
	check(ans);
	printf("%d\n",ans/2);
	return;
	printf("%d %d ",ans/2,need[0]);
	if (nl==1)
		printf("%d\n",need[0]%n+1);
	else printf("%d\n",need[1]);
}
int main()
{
	freopen("B.in","r",stdin);
	int cs,ti=0;
	scanf("%d",&cs);
	while (cs--) work(++ti);
}
