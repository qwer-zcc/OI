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
map<string,int> Hash;
queue<int> Q;
vector<int> E[10000];
int n,ans,dis[10000],vis[10000],cnt;
string a,b,c;
void spfa(int S)
{
	rep(j,1,cnt) dis[j]=0,vis[j]=0;
	Q.push(S);dis[S]=1;
	while (Q.size())
	{
		int x=Q.front();vis[x]=0;Q.pop();
		for (int i=0;i<E[x].size();i++)
			if (dis[E[x][i]]<dis[x]+1)
			{
				dis[E[x][i]]=dis[x]+1;
				if (!vis[E[x][i]]) vis[E[x][i]]=1,Q.push(E[x][i]);
			}
	}
}
int main()
{
	cin>>n;int x,y;
	rep(i,1,n)
	{
		cin>>a>>b>>c;
		for (int j=0;j<a.size();j++)
			if (a[j]>='A' && a[j]<='Z') a[j]='a'+a[j]-'A';
		for (int j=0;j<c.size();j++)
			if (c[j]>='A' && c[j]<='Z') c[j]='a'+c[j]-'A';
		if (Hash[a]) x=Hash[a];
			else x=Hash[a]=++cnt;
		if (Hash[c]) y=Hash[c];
			else y=Hash[c]=++cnt;
		E[x].pb(y);
	}
	rep(i,1,cnt)
	{
		spfa(i);
		rep(j,1,cnt) ans=max(ans,dis[j]);
	}
	printf("%d\n",ans);
}
