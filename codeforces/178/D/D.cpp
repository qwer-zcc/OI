//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 30/09/2014                 |
//+-------------------------------------+
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#define INF ~0U>>1
#define LLINF ~0ULL>>1
#define LL long long
#define uLL unsigned long long
#define uint unsigned int
#define D double
#define LD long double
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define Chen(a,b,c) int((LL)(a)*(LL)(b)%(LL)(c))
#define pb push_back
#define mp make_pair
#define ps push
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
template<class T> void read(T &x)
{
	char ch;
	while ((ch=getchar()) && !isdigit(ch));x=ch-'0';
	while ((ch=getchar()) && isdigit(ch)) x=x*10+ch-'0';
}
struct point
{
	int x,y;
	point() {}
	point(int _x,int _y) : x(_x),y(_y) {}
} ;
LL sum,a[5][5],w[100];
int n,vis[100],Cnt[100];
inline void nxt(int &x,int &y)
{
	y++;
	if (y>n) y=1,x++;
}
inline void bef(int &x,int &y)
{
	y--;
	if (y==0) x--,y=n;
}
inline void print()
{
	rep(i,1,n)
	{
		rep(j,1,n) printf("%I64d ",a[i][j]);
		puts("");
	}
	//fprintf(stderr,"%d\n",clock());
}
inline LL calc_row(int x,int y)
{
	LL ans=0;
	while (y-1>0) y--,ans+=a[x][y];
	return ans;
}
inline LL calc_col(int x,int y)
{
	LL ans=0;
	while (x-1>0) x--,ans+=a[x][y];
	return ans;
}
inline LL calc_dia(int x,int y)
{
	LL ans=0;
	if (x==n && y==n)
	{
		while (x-1>0) x--,y--,ans+=a[x][y];
		return ans;
	}
	while (x-1>0) x--,y++,ans+=a[x][y];
	return ans;
}
void dfs(int x,int y)
{
	if (x>n) {print();exit(0);}
	if (x==n && y==n)
	{
		LL s1=calc_row(x,y),s2=calc_col(x,y),s3=calc_dia(x,y);
		if (s1!=s2 || s1!=s3 || s2!=s3) return;
		rep(i,1,n*n)
		if (w[i]==sum-s1 && !vis[i])
		{
			a[x][y]=w[i];vis[i]=1;
			nxt(x,y);
			dfs(x,y);
			bef(x,y);
			a[x][y]=0;vis[i]=0;
			break;
		}
		else if (w[i]>sum-s1) break;
		return;
	}
	if (y==n)
	{
		LL s1=calc_row(x,y);
		rep(i,1,n*n)
		if (w[i]==sum-s1 && !vis[i])
		{
			a[x][y]=w[i];vis[i]=1;
			nxt(x,y);
			dfs(x,y);
			bef(x,y);
			a[x][y]=0;vis[i]=0;
			break;
		}
		else if (w[i]>sum-s1) break;
		return;
	}
	if (x==n && y==1)
	{
		LL s1=calc_col(x,y),s2=calc_dia(x,y);
		if (s1!=s2) return;
		rep(i,1,n*n)
		if (w[i]==sum-s1 && !vis[i])
		{
			a[x][y]=w[i];vis[i]=1;
			nxt(x,y);
			dfs(x,y);
			bef(x,y);
			a[x][y]=0;vis[i]=0;
			break;
		}
		else if (w[i]>sum-s1) break;
		return;
	}
	if (x==n)
	{
		LL s1=calc_col(x,y);
		rep(i,1,n*n)
		if (w[i]==sum-s1 && !vis[i])
		{
			a[x][y]=w[i];vis[i]=1;
			nxt(x,y);
			dfs(x,y);
			bef(x,y);
			a[x][y]=0;vis[i]=0;
			break;
		}
		else if (w[i]>sum-s1) break;
		return;
	}
	rep(i,1,n*n)
	if (!vis[i])
	{
		if (x==n-1)
		{
			LL s1=calc_col(x,y);
			int flag=0;
			rep(j,1,n*n)
			if (w[j]==sum-s1-w[i] && !vis[j]) {flag=1;break;}
			else if (w[j]>sum-s1-w[i]) break;
			if (!flag) continue;
		}
		if (y==n-1)
		{
			LL s1=calc_row(x,y);
			int flag=0;
			rep(j,1,n*n)
			if (w[j]==sum-s1-w[i] && !vis[j]) {flag=1;break;}
			else if (w[j]>sum-s1-w[i]) break;
			if (!flag) continue;
		}
		a[x][y]=w[i];vis[i]=1;
		nxt(x,y);
		dfs(x,y);
		bef(x,y);
		a[x][y]=0;vis[i]=0;
	}
}
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n*n) scanf("%I64d",&w[i]);
	sort(w+1,w+n*n+1);
	rep(i,1,n*n) sum+=w[i];
	sum/=n;
	printf("%I64d\n",sum);
	dfs(1,1);
}
