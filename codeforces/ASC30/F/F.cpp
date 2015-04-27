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
LL n;
int main()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	scanf("%lld",&n);
	if (n==1) {puts("WIN");return 0;}
	while (n>1)
	{
		LL p=(LL)(sqrt(n));
		if (p*p==n || (p+1)*(p+1)==n) {puts("WIN");return 0;}
		n-=(LL)(sqrt(n));
		if (n==1) {puts("LOSE");return 0;}
		n--;
	}
	puts("WIN");
}
