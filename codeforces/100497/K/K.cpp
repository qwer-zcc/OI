//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 30/09/2014                 |
//+-------------------------------------+
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
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
#define Chen(a,b,c) int((LL)(a)*(LL)(b)%(LL)(c))
#define pb push_back
#define mp make_pair
#define ps push
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
const int N=1200000;
string s;
queue<int> Q;
vector<int> E[N];
map<string,int> hash;
int cnt,vis[N],ans,rd[N];
int main()
{
	//freopen("K.in","r",stdin);
	int ok=1,x=0;
	while (cin>>s)
	{
		if (s=="0") {ok=1;continue;}
		int id;
		if (!hash[s]) hash[s]=id=++cnt;
		else id=hash[s];
		if (ok==1) {vis[id]=1;x=id;ok=0;continue;}
		E[id].pb(x);rd[x]++;
	}
	rep(i,1,cnt)
	if (!rd[i] && vis[i]) Q.push(i),ans++;
	while (Q.size())
	{
		x=Q.front();Q.pop();
		for (int i=0;i<E[x].size();i++)
		{
			rd[E[x][i]]--;
			if (rd[E[x][i]]==0 && vis[E[x][i]]) ans++,Q.push(E[x][i]);
		}
	}
	printf("%d\n",ans);
}

