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
struct Tri
{
	int x,y,z;
	Tri(){}
	Tri(int _x,int _y,int _z) : x(_x),y(_y),z(_z) {}
};
const int N=3100;
//Tri pre[N][N][2];
int cb,ci,cd,cc,dp[N][N][2],vis[N],pre[N][N][2];
char a[N],b[N];
string s;
vector<pair<int,int> > ans;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d%d%d%d",&cb,&cd,&ci,&cc);
	scanf("%s%s",a+1,b+1);int n=strlen(a+1),m=strlen(b+1);
	rep(i,0,n) rep(j,0,m) dp[i][j][0]=dp[i][j][1]=INF;
	cc=min(cc,ci+cd);
	dp[0][0][0]=0;
	rep(i,0,n) rep(j,0,m)
	if (i||j)
	{
		// 1 i-1 j 0
		// 2 i-1 j 1
		// 3 i j-1 0
		// 4 i j-1 1
		// 5 i-1 j-1 0
		// 6 i-1 j-1 1
		if (i>0)
		{
			if (dp[i-1][j][0]+ci<dp[i][j][0])
			{
				dp[i][j][0]=dp[i-1][j][0]+ci;
				pre[i][j][0]=1;
			}
			if (dp[i-1][j][1]+ci<dp[i][j][0])
			{
				dp[i][j][0]=dp[i-1][j][1]+ci;
				pre[i][j][0]=2;
			}
			if (dp[i-1][j][1]<dp[i][j][1])
			{
				dp[i][j][1]=dp[i-1][j][1];
				pre[i][j][1]=2;
			}
			if (dp[i-1][j][0]+cb<dp[i][j][1])
			{
				dp[i][j][1]=dp[i-1][j][0]+cb;
				pre[i][j][1]=1;
			}
		}
		if (j>0)
		{
			if (dp[i][j-1][0]+cd<dp[i][j][0])
			{
				dp[i][j][0]=dp[i][j-1][0]+cd;
				pre[i][j][0]=3;
			}
			if (dp[i][j-1][1]+cd<dp[i][j][0])
			{
				dp[i][j][0]=dp[i][j-1][1]+cd;
				pre[i][j][0]=4;
			}
			if (dp[i][j-1][1]+cd<dp[i][j][1])
			{
				dp[i][j][1]=dp[i][j-1][1]+cd;
				pre[i][j][1]=4;
			}
			if (dp[i][j-1][0]+cb+cd<dp[i][j][1])
			{
				dp[i][j][1]=dp[i][j-1][0]+cb+cd;
				pre[i][j][1]=3;
			}
		}
		if (i>0 && j>0 && a[i]==b[j])
		{
			if (dp[i-1][j-1][0]+cc<dp[i][j][0])
			{
				dp[i][j][0]=dp[i-1][j-1][0]+cc;
				pre[i][j][0]=5;
			}
			if (dp[i-1][j-1][1]+cc<dp[i][j][0])
			{
				dp[i][j][0]=dp[i-1][j-1][1]+cc;
				pre[i][j][0]=6;
			}
		}
	}
	printf("%d\n",min(dp[n][m][0],dp[n][m][1]));
	Tri cur;
	if (dp[n][m][0]<dp[n][m][1]) cur=Tri(n,m,0);
	else cur=Tri(n,m,1);
	while (cur.x||cur.y)
	{
		vis[cur.x]=cur.z;
		int opt=pre[cur.x][cur.y][cur.z];
		Tri p;
		if (opt==1) p=Tri(cur.x-1,cur.y,0);
		else if (opt==2) p=Tri(cur.x-1,cur.y,1);
		else if (opt==3) p=Tri(cur.x,cur.y-1,0);
		else if (opt==4) p=Tri(cur.x,cur.y-1,1);
		else if (opt==5) p=Tri(cur.x-1,cur.y-1,0);
		else if (opt==6) p=Tri(cur.x-1,cur.y-1,1);
		if (p.y==cur.y-1 && p.x==cur.x-1) s+='C';
		else if (p.y==cur.y-1) s+='I';
		else if (p.x==cur.x-1 && !cur.z) s+='D';
		cur=p;
	}
	int Begin=INF;
	vis[n+1]=0;
	rep(i,1,n+1)
		if (vis[i]) Begin=min(Begin,i);
		else if (Begin!=INF) ans.pb(mp(Begin,i-1)),Begin=INF;
	printf("%lu\n",ans.size());
	for (int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
	for (int i=s.size()-1;i>=0;i--) printf("%c",s[i]);puts("");
}
