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
int main()
{
	freopen("C.in","w",stdout);
	srand(time(0));
	int n=100,m=10;
	printf("%d %d\n",n,m);
	rep(i,1,n) printf("%d ",rand()%1000+1);puts("");
	rep(i,1,n) printf("%d ",rand()%1000+1);puts("");
	rep(i,1,m)
	{
		int p=rand()%n+1,q=rand()%n+1;
		while ((p-q+n)%n<=2) p=rand()%n+1,q=rand()%n+1;
		printf("%d %d\n",p,q);
	}
}
