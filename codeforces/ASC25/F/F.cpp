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
/*
   0   00
   1   01
   2   10
   3   11
*/
struct lj
{
	int a[4];
	void init(){rep(i,0,3) a[i]=0;}
};
char s[120000];
int cnt;
lj solve()
{
	char ch=s[++cnt];lj ans;ans.init();
	if (ch=='S')
	{
		lj a=solve(),b=solve();
		ans.a[0]=max(a.a[0]+b.a[0],a.a[1]+b.a[2]-1);
		ans.a[1]=max(a.a[0]+b.a[1],a.a[1]+b.a[3]-1);
		ans.a[2]=max(a.a[2]+b.a[0],a.a[3]+b.a[2]-1);
		ans.a[3]=max(a.a[2]+b.a[1],a.a[3]+b.a[3]-1);
	}
	else if (ch=='P')
	{
		lj a=solve(),b=solve();
		ans.a[0]=a.a[0]+b.a[0];
		ans.a[1]=a.a[1]+b.a[1]-1;
		ans.a[2]=a.a[2]+b.a[2]-1;
		ans.a[3]=a.a[3]+b.a[3]-2;
	}
	else ans.a[1]=ans.a[2]=ans.a[3]=1;
	return ans;
}
int main()
{
	freopen("independent.in","r",stdin);
	freopen("independent.out","w",stdout);
	scanf("%s",s+1);cnt=0;
	lj x=solve();
	printf("%d\n",max(x.a[0],max(x.a[1],max(x.a[2],x.a[3]))));
}
