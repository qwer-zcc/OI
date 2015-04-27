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
int id[1000000];
int main()
{
	srand(unsigned(time(0)));
	freopen("D.in","w",stdout);
	int n=100000,m=10;
	rep(i,1,n) id[i]=i;
	random_shuffle(id+1,id+n+1);
	printf("%d\n",n);
	rep(i,2,n) printf("%d %d %d\n",id[rand()%(i-1)+1],id[i],rand()%1000000+10000);
	printf("%d\n",m);
	rep(i,1,m) printf("%lld\n",(LL)(rand()%10000+10000)*(LL)(rand()%1000+100));
}
