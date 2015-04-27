//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 14/08/2014                 |
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
const int N=120000;
map<int,int> hash;
int n,a,b;
int val[N],A[N],B[N],vis[N];
void tp()
{
	rep(i,1,n) if (!hash[a-val[i]]) {puts("NO");exit(0);}
	puts("YES");
	rep(i,1,n) printf("0 ");
	exit(0);
}
int main()
{
	//freopen("B.in","r",stdin);
	scanf("%d%d%d",&n,&a,&b);
	rep(i,1,n) scanf("%d",&val[i]),hash[val[i]]=i;
	if (a==b) tp();
	rep(i,1,n) vis[i]=-1;
	rep(j,1,n)
	if (vis[j]==-1)
	{
		int al=0,bl=0;
		int x=a-val[j],ty=0;
		while (hash[x])
		{
			A[++al]=hash[x];
			ty^=1;
			if (ty==1) x=b-x;
			else x=a-x;
		}
		int ty1=ty;
		x=b-val[j],ty=1;
		while (hash[x])
		{
			B[++bl]=hash[x];
			ty^=1;
			if (ty==1) x=b-x;
			else x=a-x;
		}
		if (al==0 && bl==0) {puts("NO");return 0;}
		if (al==1 && bl==0) {vis[j]=vis[A[1]]=0;continue;}
		if (al==0 && bl==1) {vis[j]=vis[B[1]]=1;continue;}
		if ((bl+al)&1)
		{
			if (ty1==0)
			{
				rep(i,1,al) vis[A[i]]=1;
				rep(i,1,bl) vis[B[i]]=1;
				vis[j]=1;
			}
			else
			{
				rep(i,1,al) vis[A[i]]=0;
				rep(i,1,bl) vis[B[i]]=0;
				vis[j]=0;
			}
			continue;
		}
		puts("NO");
		return 0;
	}
	puts("YES");
	rep(i,1,n-1) printf("%d ",vis[i]);printf("%d\n",vis[n]);
}

