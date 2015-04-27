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
int x,y;
void work()
{
	int bit=1,p;
	while (bit<y) bit<<=1;
	p=(bit<<1)+1;
	printf("%d\n",p);
	rep(i,1,bit-1) printf("%d %d\n",i<<1,i<<1|1);
	rep(i,1,x) printf("%d %d\n",p-1,p-1);
	rep(i,1,y-x) printf("%d %d\n",p,p);
	rep(i,1,p-(bit+y)-1) printf("1 1\n");
}
int main()
{
	freopen("drunkard.in","r",stdin);
	freopen("drunkard.out","w",stdout);
	while(scanf("%d%d",&x,&y) && x) work();
}
