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
LL ans;
int n,a,b,ax,ay;
void add(LL x,LL y)
{
	LL c=(a*x+b*y)^(b*x+a*y);
	if (c>=ans) ans=c,ax=x,ay=y;
}
int main()
{
	freopen("crypto.in","r",stdin);
	freopen("crypto.out","w",stdout);
	scanf("%d%d%d",&n,&a,&b);
	rep(i,1,n)
	{
		for (int j=i;j;j=(j-1)&i) add(i,j);
	}
	printf("%d %d\n",ax,ay);
}
