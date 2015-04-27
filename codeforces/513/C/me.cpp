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
int n,k,l[100],r[100];
D ans;
void solve(int x,int c)
{
	D sum=0;
	rep(i,1,n)
	if (i!=x)
	{
		if ((x<i && r[i]>=c)||(x>i && r[i]>c))
		{
			int p=min(r[i]-c+1,r[i]-l[i]+1)-(x>i && l[i]<=c);
			D q=(D)p/(D)(r[i]-l[i]+1);
			rep(j,1,n)
				if (i!=j && x!=j)
				{
					if (l[j]<=c)
					{
						p=min(c-l[j]+1,r[j]-l[j]+1)-(x<j && r[j]>=c);
						q=q*(D)p/(D)(r[j]-l[j]+1);
					}
					else q=0;
				}
			sum+=q*c;
		}
	}
	ans+=sum/(D)(r[x]-l[x]+1);
}
int main()
{
	//freopen("C.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d%d",&l[i],&r[i]);
	rep(i,1,n)
		rep(j,l[i],r[i]) solve(i,j);
	printf("%.12lf\n",ans);
}
