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
struct point
{
	LL x,y;
	point(){}
	point(LL _x,LL _y) : x(_x),y(_y) {}
}P[4000];
pair<pair<LL,LL>,pair<LL,int> > T[4000];
int n,m,ans[4000];
LL dis(point a,point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
void work()
{
	rep(i,1,n) scanf("%lld%lld",&P[i].x,&P[i].y);
	scanf("%d",&m);
	rep(i,1,m)
	{
		ans[i]=0;LL x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		if (x>y) swap(x,y);
		T[i]=mp(mp(x,y),mp(z,i));
	}
	sort(T+1,T+m+1);
	T[m+1]=mp(mp(0,0),mp(0,0));
	rep(i,1,n) rep(j,i+1,n)
	{
		LL x=dis(point(0,0),P[i]),y=dis(point(0,0),P[j]),z=dis(P[i],P[j]);
		if (x>y) swap(x,y);
		pair<pair<LL,LL>,pair<LL,int> > a=mp(mp(x,y),mp(z,0));
		int pos=lower_bound(T+1,T+m+1,a)-T;
		while (T[pos].first.first==x && T[pos].first.second==y && T[pos].second.first==z)
			ans[T[pos].second.second]++,pos++;
	}
	rep(i,1,m) printf("%d\n",ans[i]);
}
int main()
{
	freopen("astronomy.in","r",stdin);
	freopen("astronomy.out","w",stdout);
	while (scanf("%d",&n)!=EOF && n) work();
}
