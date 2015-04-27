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
const int N=510000;
struct point
{
	int x,id,ty;
	point(){}
	point(int _x,int _id,int _ty) : x(_x),ty(_ty),id(_id) {}
}P[N];
int pl,n,cur,dp[N],x[N],w[N];
int operator < (point a,point b)
{
	return a.x<b.x||(a.x==b.x && a.ty>b.ty);
}
int main()
{
	freopen("B.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n)
	{
		scanf("%d%d",&x[i],&w[i]);
		P[++pl]=point(x[i]-w[i],i,0);
		P[++pl]=point(x[i]+w[i],i,1);
	}
	sort(P+1,P+pl+1);
	rep(i,1,pl)
	{
		if (P[i].ty==0) dp[P[i].id]=cur+1;
		else cur=max(cur,dp[P[i].id]);
	}
	printf("%d\n",cur);
}
