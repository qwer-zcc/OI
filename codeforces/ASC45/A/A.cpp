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
int n,a[100],b[100],al,bl;
vector<int> cur;
vector<vector<int> > all;
void check()
{
	all.pb(cur);
}
void dfs(int w,int pre,int limit)
{
	if (w>n) {check();return;}
	rep(i,pre+1,limit)
	{
		cur.pb(i);
		dfs(w+1,i,limit);
		cur.pop_back();
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1,0,12);
	for (int _=0;_<all.size();_++)
		for (int __=_+1;__<all.size();__++)
		{
			vector<int> x=all[_],y=all[__];
			al=bl=0;
			for (int i=0;i<x.size();i++)
				for (int j=0;j<x.size();j++)
					if (i!=j) a[++al]=x[i]+x[j];
			for (int i=0;i<y.size();i++)
				for (int j=0;j<y.size();j++)
					if (i!=j) b[++bl]=y[i]+y[j];
			sort(a+1,a+al+1);sort(b+1,b+bl+1);
			int flag=1;
			rep(i,1,al) if (a[i]!=b[i]) {flag=0;break;}
			if (flag)
			{
				for (int i=0;i<x.size();i++) printf("%d ",x[i]);puts("");
				for (int i=0;i<y.size();i++) printf("%d ",y[i]);puts("");
		//		puts("");
				return 0;
			}
		}
//	puts("no");
}
