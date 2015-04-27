//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 05/07/2014                 |
//+-------------------------------------+
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
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
#define dep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define Chen(a,b,c) int((LL)(a)*(LL)(b)%(LL)(c))
#define pb push_back
#define mp make_pair
#define ins insert
#define ps push
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
inline void read(int &x)
{
	char ch;
	while ((ch=getchar()) && !(ch>='0' && ch<='9'));x=ch-'0';
	while ((ch=getchar()) && (ch>='0' && ch<='9')) x=x*10+ch-'0';
}
struct point
{
	int x,y;
	point() {}
	point(int _x,int _y) : x(_x),y(_y) {}
} ;
char s[10000];
int w[10000],il=0,k;
int main()
{
	scanf("%s",s+1);s[0]='?';int l=strlen(s)-1;
	scanf("%d",&k);int Max=0;
	rep(i,0,25) scanf("%d",&w[i]),Max=max(Max,w[i]);
	LL ans=0,sum=0;
	rep(i,1,l)
	{
		sum+=(LL)(w[s[i]-'a']-Max);
		if (sum<ans)
		{
			ans=sum;
			il=i;
		}
	}
	ans=0;
	rep(i,1,il) ans+=(LL)w[s[i]-'a']*(i);
	rep(i,1,k) ans+=(LL)Max*(il+i);
	rep(i,il+1,l) ans+=(LL)w[s[i]-'a']*(LL)(i+k);
	printf("%lld\n",ans);
}

