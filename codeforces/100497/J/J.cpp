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
#define INF (~0U>>1)-1
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
const int N=1100000;
int son[N][27],cnt[N],Cnt=1,Min[N],n,m;
LL sum[N];
char s[N];
LL Sum()
{
	LL ans=0;
	int l=strlen(s)-1,rt=1;
	rep(i,0,l)
	{
		ans+=(LL)(cnt[rt]-cnt[son[rt][s[i]-'a']])*(i+1);
		rt=son[rt][s[i]-'a'];
		if (!rt) break;
	}
	ans+=(LL)cnt[rt]*(l+2);
	return ans;
}
void add(int I)
{
	sum[I]=Sum();
	int l=strlen(s)-1,rt=1;cnt[rt]++;
	rep(i,0,l)
	{
		if (!son[rt][s[i]-'a']) son[rt][s[i]-'a']=++Cnt,Min[Cnt]=INF;
		rt=son[rt][s[i]-'a'];cnt[rt]++;//num[rt]++;	
	}
	Min[rt]=min(Min[rt],I);
}
void work()
{
	int l=strlen(s)-1,rt=1;
	rep(i,0,l)
	{
		if (son[rt][s[i]-'a']) rt=son[rt][s[i]-'a'];
		else {printf("%I64d\n",Sum());return;}
	}
	if (Min[rt]==INF) {printf("%I64d\n",Sum());return;}
	printf("%I64d\n",sum[Min[rt]]+l+2);
}
int main()
{
	//freopen("J.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n) scanf("%s",s),add(i);
	scanf("%d",&m);
	rep(i,1,m) scanf("%s",s),work();
}

