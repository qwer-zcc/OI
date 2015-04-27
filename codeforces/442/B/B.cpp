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
const int N=200;
int n;
LD p[N],ans;
int main()
{
	scanf("%d",&n);
	rep(i,1,n) cin>>p[i];
	sort(p+1,p+n+1);
	rep(i,1,n)
	{
		LD c=1.,sum=0.;
		rep(j,i,n)
		{
			c=1.;
			rep(k,i,n)
			if (j!=k) c*=(1.-p[k]);
			c*=p[j];
			sum+=c;
		}
		ans=max(ans,sum);
	}
	printf("%.12lf\n",(double)ans);
}
