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
const int N=420000;
int n,cnt,sa[N],Rank[N],s[N];
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&sa[i]),Rank[sa[i]]=i;
	s[sa[1]]=0;
	rep(i,2,n)
		if (Rank[sa[i]+1]<Rank[sa[i-1]+1]) s[sa[i]]=++cnt;
		else s[sa[i]]=cnt;
	if (cnt>1) puts("Error");
	else {rep(i,1,n) printf("%d",s[i]);puts("");}
}
