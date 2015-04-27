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
const int N=350;
queue<int> Q;
LL dis[N][N][2],ans;
int vis[N],n,m;
int main()
{
	freopen("trip.in","r",stdin);
	freopen("trip.out","w",stdout);
	scanf("%d%d",&n,&m);int x,y;LL z;
	rep(i,1,n) rep(j,1,n) dis[i][j][0]=dis[i][j][1]=(LL)1e16;
	rep(i,1,m) scanf("%d%d%lld",&x,&y,&z),dis[x][y][0]=min(dis[x][y][0],z),dis[x][y][1]=1,dis[y][x][0]=min(dis[y][x][0],z),dis[y][x][1]=1;
	rep(i,1,n) dis[i][i][0]=dis[i][i][1]=0;
	rep(k,1,n) rep(i,1,n) rep(j,1,n)
		if (dis[i][k][0]+dis[k][j][0]<dis[i][j][0] || (dis[i][k][0]+dis[k][j][0]==dis[i][j][0] && dis[i][k][1]+dis[k][j][1]<dis[i][j][1])) dis[i][j][0]=dis[i][k][0]+dis[k][j][0],dis[i][j][1]=dis[i][k][1]+dis[k][j][1];
	rep(i,1,n)
		rep(j,1,n) ans=ans+dis[i][j][1];
	printf("%.10lf\n",(D)ans/(D)(n*n-n));
}
