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
const int N=500000;
struct lj{int x,y,ty;}E[N];
int n,m,el,fa[N];
char s[10];
int g_f(int x) {return fa[x]==x?x:fa[x]=g_f(fa[x]);}
void solve()
{
	rep(i,1,n) fa[i]=i;
	int ans=n;
	rep(i,1,el)
		if (!E[i].ty)
		{
			int p=g_f(E[i].x),q=g_f(E[i].y);
			if (p!=q) fa[p]=q,ans--;
		}
	printf("%d\n",ans);
}
int x,y;
int main()
{
	freopen("A.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,m)
	{
		scanf("%s",s);
		if (s[0]=='?') solve();
		else if (s[0]=='+')
		{
			scanf("%d%d",&x,&y);
			E[++el].x=x,E[el].y=y;
		}
		else
		{
			scanf("%d%d",&x,&y);
			rep(j,1,el)
				if (E[j].x==x && E[j].y==y) E[j].ty=1;
		}
	}
}
