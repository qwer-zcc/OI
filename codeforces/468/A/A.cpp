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
int n;
void add(int x,int y)
{
	printf("%d + %d = %d\n",x,y,x+y);
}
void del(int x,int y)
{
	printf("%d - %d = %d\n",x,y,x-y);
}
void mul(int x,int y)
{
	printf("%d * %d = %d\n",x,y,x*y);
}
void sol(int l,int r)
{
	int c=24;
	rep(_,l,r)
	{
		int i=_-l+1;
		if (i%4==1) add(c,i+l-1),c+=i+l-1;
		else if (i%4==2) del(c,i+l-1),c-=i+l-1;
		else if (i%4==3) del(c,i+l-1),c-=i+l-1;
		else add(c,i+l-1),c+=i+l-1;
	}
}
void work(int n)
{
	puts("YES");
	if (n%4==0)
	{
		mul(1,2);
		mul(2,3);
		mul(6,4);
		sol(5,n);
	}
	else if (n%4==1)
	{
		mul(4,5);
		add(20,2);
		add(22,3);
		del(25,1);
		sol(6,n);
	}
	else if (n%4==2)
	{
		mul(4,6);
		add(24,5);
		del(29,2);
		del(27,3);
		mul(24,1);
		sol(7,n);
	}
	else
	{
		mul(4,6);
		add(24,7);
		add(31,2);
		del(33,5);
		del(28,3);
		del(25,1);
		sol(8,n);
	}
}
int main()
{
	//freopen("me.out","w",stdout);
	scanf("%d",&n);
	if (n==1 || n==2 || n==3) {puts("NO");return 0;}
	work(n);
}

