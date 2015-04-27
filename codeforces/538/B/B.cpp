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
vector<int> res;
int n,a[1000],al,ans;
int main()
{
	scanf("%d",&n);
	while (n) a[++al]=n%10,ans+=n%10,n/=10;
	while (ans)
	{
		int cur=0;
		drep(i,al,1)
		{
			cur=cur*10+(a[i]>0);
			ans-=(a[i]>0);
			a[i]=max(a[i]-1,0);
		}
		res.pb(cur);
	}
	cout<<res.size()<<endl;
	for (int i=0;i<res.size();i++) printf("%d ",res[i]);
	puts("");
}
