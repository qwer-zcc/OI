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
#define INF 1000000000
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
const int N=300;
int ans=-INF,sum,n,m,w[N];
multiset<int> S1,S2;
int main()
{
	freopen("A.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&w[i]);
	rep(i,1,n) ans=max(ans,w[i]);
	rep(i,1,n) rep(j,i,n)
	if (w[i]>=0 && w[j]>=0)
	{
		int sum=0;
		S1.clear();S2.clear();
		rep(k,i,j) S1.insert(w[k]),sum+=w[k];
		rep(k,1,i-1) S2.insert(-w[k]);
		rep(k,j+1,n) S2.insert(-w[k]);
		ans=max(ans,sum);
		if (!S2.size()) continue;
		rep(k,1,m)
		{
			int p=*S1.begin(),q=*S2.begin();
			if (-q>p) sum+=-q-p;
			else break;
			S1.erase(S1.begin());
			S2.erase(S2.begin());
			S1.insert(-q);
			S2.insert(-p);
		}
		ans=max(ans,sum);
	}
	printf("%d\n",ans);
}

