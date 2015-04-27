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
#define LD long double
#define pb push_back
#define mp make_pair
#define Pi M_PI
#define clr(a) memset(a,0,sizeof(a));
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
const int N=120000;
char s[N],t[N];
int n,ans=0;
int main()
{
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	int l=1,r=n;
	while (s[l]==t[l]) l++;
	while (s[r]==t[r]) r--;
	if (l==r) {puts("2");return 0;}
	int flag=1;
	rep(i,l,r-1) if (s[i]!=t[i+1]) flag=0;
	if (flag) ans++;
	flag=1;
	rep(i,l+1,r) if (s[i]!=t[i-1]) flag=0;
	if (flag) ans++;
	printf("%d\n",ans);
}
