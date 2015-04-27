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
const int N=110000;
int t[N],n,m,l,r,T;
int ask(int x)
{
	int ans=0;
	for (int i=x;i;i-=i&(-i)) ans+=t[i];
	return ans;
}
void add(int x,int c)
{
	for (int i=x;i<=n;i+=i&(-i)) t[i]+=c;
}
void change(int x)
{
	if (T==0)
	{
		if (x<=(r-l)/2)
		{
			rep(i,1,x) add(l+x+i,ask(l+x-i+1)-ask(l+x-i));
			//rep(i,l+1+x,l+x+x) add(i,ask(i-x)-ask(i-x-1));
			l+=x;
		}
		else
		{
			rep(i,1,r-l-x) add(l+x-i+1,ask(l+x+i)-ask(l+x+i-1));
			r=l+x;
			T^=1;
		}
	}
	else
	{
		x=r-l-x;
		if (x<=(r-l)/2)
		{
			rep(i,1,x) add(l+x+i,ask(l+x-i+1)-ask(l+x-i));
			//rep(i,l+1+x,l+x+x) add(i,ask(i-x)-ask(i-x-1));
			l+=x;
			T^=1;
		}
		else
		{
			rep(i,1,r-l-x) add(l+x-i+1,ask(l+x+i)-ask(l+x+i-1));
			r=l+x;
		}
	}
}
void ask(int L,int R)
{
	if (T==0) printf("%d\n",ask(l+R)-ask(l+L));
	else printf("%d\n",ask(r-L)-ask(r-R));
}
int main()
{
	freopen("C.in","r",stdin);
	//freopen("me.out","w",stdout);
	scanf("%d%d",&n,&m);r=n;int ty,x,L,R;
	rep(i,1,n) add(i,1);
	rep(i,1,m)
	{
		scanf("%d",&ty);
		if (ty==1) scanf("%d",&x),change(x);
		else scanf("%d%d",&L,&R),ask(L,R);
	}
}

