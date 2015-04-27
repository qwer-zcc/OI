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
struct lj{D p,q,s;}P[200];
int n;
D a,b,ans,Mincost=1e20;
D cost(D x)
{
	D ans=x*b;
	rep(i,1,n) ans+=max(P[i].p-P[i].s*x,0.)/P[i].q*a;
	return ans;
}
void check(D p)
{
	if (cost(p)<Mincost) Mincost=cost(p),ans=p;
}
int main()
{
	freopen("academy.in","r",stdin);
	freopen("academy.out","w",stdout);
	scanf("%d%lf%lf",&n,&a,&b);
	rep(i,1,n) scanf("%lf%lf%lf",&P[i].p,&P[i].q,&P[i].s);
	check(0);
	rep(i,1,n) check(P[i].p/P[i].s);
	printf("%.12lf\n",Mincost);
	printf("%.12lf\n",ans);
	rep(i,1,n) printf("%.12lf ",max(P[i].p-P[i].s*ans,0.)/P[i].q);puts("");
}
