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
const int N=2010;
int n,X1,Y1,X2,Y2;
LL w[N][N],s[N][N],s1=-1,s2=-1;
int main()
{
	read(n);
	rep(i,1,n) rep(j,1,n) read(w[i][j]);
	rep(i,1,n)
	{
		int p=1,q=i;LL sum=w[p][q];
		while (p+1<=n && q-1>0) p++,q--,sum+=w[p][q];
		p=1,q=i;s[p][q]+=sum;
		while (p+1<=n && q-1>0) p++,q--,s[p][q]+=sum;
	}
	rep(i,2,n)
	{
		int p=i,q=n;LL sum=w[p][q];
		while (p+1<=n && q-1>0) p++,q--,sum+=w[p][q];
		p=i,q=n;s[p][q]+=sum;
		while (p+1<=n && q-1>0) p++,q--,s[p][q]+=sum;
	}
	rep(i,1,n)
	{
		int p=1,q=i;LL sum=w[p][q];
		while (p+1<=n && q+1<=n) p++,q++,sum+=w[p][q];
		p=1;q=i;s[p][q]+=sum;
		while (p+1<=n && q+1<=n) p++,q++,s[p][q]+=sum;
	}
	rep(i,2,n)
	{
		int p=i,q=1;LL sum=w[p][q];
		while (p+1<=n && q+1<=n) p++,q++,sum+=w[p][q];
		p=i;q=1;s[p][q]+=sum;
		while (p+1<=n && q+1<=n) p++,q++,s[p][q]+=sum;
	}
	rep(i,1,n) rep(j,1,n)
	{
		if ((i+j)&1)
		{
			if (s[i][j]-w[i][j]>s1)
			{
				s1=s[i][j]-w[i][j];
				X1=i,Y1=j;
			}
		}
		else
		{
			if (s[i][j]-w[i][j]>s2)
			{
				s2=s[i][j]-w[i][j];
				X2=i,Y2=j;
			}
		}
	}
	cout<<s1+s2<<endl;
	printf("%d %d %d %d\n",X1,Y1,X2,Y2);
}

