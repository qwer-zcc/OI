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
#define INF (LL)(1e18)
#define LL long long
#define D double
#define LD long double
#define pb push_back
#define mp make_pair
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
const int N=120000;
struct lj{LL x,y;}P[N];
inline int cmp(const lj &a,const lj &b) {return a.x<b.x;}
set<pair<LL,int> > S;
int n;
LL ans[N];
int main()
{
	freopen("pulp.in","r",stdin);
	freopen("pulp.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) scanf("%lld%lld",&P[i].x,&P[i].y);
	sort(P+1,P+n+1,cmp);
	P[n+1].x=INF;
	S.insert(mp(P[1].y,1));
	rep(i,2,n+1)
	{
		if (i<=n && P[i].x==P[i-1].x)
		{
			S.insert(mp(P[i].y,i));
			continue;
		}
		LL sum=P[i].x-P[i-1].x,ti=P[i-1].x;
		while (S.size() && sum)
		{
			set<pair<LL,int> >::iterator It=S.begin();
			if (It->first<=sum)
			{
				sum-=It->first;
				ans[It->second]=ti+It->first;
				ti+=It->first;
				S.erase(It);
			}
			else
			{
				S.erase(It);
				S.insert(mp(It->first-sum,It->second));
				sum=0;
			}
		}
		if (i<=n) S.insert(mp(P[i].y,i));
	}
	LL sum=0;
	rep(i,1,n) sum+=(LL)ans[i];
	printf("%lld\n",sum);
}
