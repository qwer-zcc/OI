//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 05/07/2014                 |
//+-------------------------------------+
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
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
#define dep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define Chen(a,b,c) int((LL)(a)*(LL)(b)%(LL)(c))
#define pb push_back
#define mp make_pair
#define ins insert
#define ps push
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
inline void read(int &x)
{
	char ch;
	while ((ch=getchar()) && !(ch>='0' && ch<='9'));x=ch-'0';
	while ((ch=getchar()) && (ch>='0' && ch<='9')) x=x*10+ch-'0';
}
struct point
{
	int x,y;
	point() {}
	point(int _x,int _y) : x(_x),y(_y) {}
} ;
const int N=400000;
set<pair<int,int> > S;
int n,m,t[N],T[N],Max;
D ans,p[N],last=1;
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d%lf",&t[i],&p[i]);
	rep(i,1,m) S.insert(mp(0,i));
	rep(i,1,n)
	{
		set<pair<int,int> >::iterator It;
		It=S.lower_bound(mp(0,0));
		if (It->first+t[i]<Max) ans+=last*(1.-p[i])*(D)Max;
		else ans+=last*(1.-p[i])*(It->first+t[i]);
		S.insert(mp(It->first+t[i],It->second));
		T[It->second]=It->first+t[i];
		Max=max(Max,It->first+t[i]);
		S.erase(It);
		last*=p[i];
	}
	ans+=last*(D)Max;
	printf("%lf\n",ans);
}

