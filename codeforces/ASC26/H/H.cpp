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
	scanf("%d%d%d%d",&a,&b,&c,&d);
	dp[0][0][0][0][0]=1;
	rep(i,0,1000)
	{
		int cur=i&1,nxt=!cur;
		rep(i,0,a) rep(j,0,b) rep(k,0,c) rep(l,0,d) dp[nxt][a][b][c]=0;
		rep(i,0,a) rep(j,0,b) rep(k,0,c) rep(l,0,d)
		{
			if (i<=j && i<=k && i<=l)
			{

			}
		}
	}
}
