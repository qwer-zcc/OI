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
const int U[4]={0,0,1,-1};
const int V[4]={1,-1,0,0};
const int N=2100;
int n,m,dt[N][N],vis[N][N];
char s[N];
queue<pair<int,int> > Q;
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n)
	{
		scanf("%s",s+1);
		rep(j,1,m) dt[i][j]=(s[j]=='*');
	}
	rep(i,0,m+1) dt[0][i]=dt[n+1][i]=1;
	rep(i,0,n+1) dt[i][0]=dt[i][m+1]=1;
	rep(i,1,n) rep(j,1,m)
	if (!dt[i][j])
	{
		rep(k,0,3)
			if (!dt[i+U[k]][j+V[k]]) vis[i][j]++;
	}
	rep(i,1,n) rep(j,1,m)
		if (vis[i][j]==1) Q.push(mp(i,j));
	while (Q.size())
	{
		int x=Q.front().first,y=Q.front().second;Q.pop();int xx=x,yy=y;
		if (!dt[x-1][y])
		{
			xx--;
			dt[xx][yy]=4;
			dt[x][y]=5;
		}
		else if (!dt[x+1][y])
		{
			xx++;
			dt[xx][yy]=5;
			dt[x][y]=4;
		}
		else if (!dt[x][y-1])
		{
			yy--;
			dt[xx][yy]=2;
			dt[x][y]=3;
		}
		else if (!dt[x][y+1])
		{
			yy++;
			dt[xx][yy]=3;
			dt[x][y]=2;
		}
		rep(k,0,3)
		if (!(xx+U[k]==x && yy+V[k]==y) && !dt[xx+U[k]][yy+V[k]])
		{
			vis[xx+U[k]][yy+V[k]]--;
			if (vis[xx+U[k]][yy+V[k]]==1) Q.push(mp(xx+U[k],yy+V[k]));

		}
	}
	rep(i,1,n) rep(j,1,m)
		if (!dt[i][j]) {puts("Not unique");return 0;}
	rep(i,1,n)
	{
		rep(j,1,m)
			if (dt[i][j]==0) printf(".");
			else if (dt[i][j]==1) printf("*");
			else if (dt[i][j]==2) printf("<");
			else if (dt[i][j]==3) printf(">");
			else if (dt[i][j]==4) printf("^");
			else if (dt[i][j]==5) printf("v");
		puts("");
	}
}
