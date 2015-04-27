//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 12/10/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF (~0U>>1)-3
#define LLINF ~0ULL>>1
#define LL long long
#define uLL unsigned long long
#define uint unsigned int
#define D double
#define LD long double
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define pb push_back
#define mp make_pair
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
map<LL,int> hash;
int n;
LL l,x,y,w[N],ax,ay;
int vx,vy;
int main()
{
	scanf("%d%lld%lld%lld",&n,&l,&x,&y);
	rep(i,1,n) scanf("%I64d",&w[i]),hash[w[i]]=1;
	rep(i,1,n-1)
	if (hash[w[i]+x]) vx=1,ax=w[i];
	rep(i,1,n-1)
	if (hash[w[i]+y]) vy=1,ay=w[i];
	if (vx && vy) {puts("0");return 0;}
	if (!vx && vy)
	{
		puts("1");
		printf("%I64d\n",w[1]+x);
		return 0;
	}
	if (vx && !vy)
	{
		puts("1");
		printf("%I64d\n",w[1]+y);
		return 0;
	}
	rep(i,1,n)
	if (w[i]+x<=l && !hash[w[i]+x] && hash[w[i]+x+y]) {puts("1");printf("%lld\n",w[i]+x);return 0;}
	else if (w[i]+y<=l && !hash[w[i]+y] && hash[w[i]+x+y]) {puts("1");printf("%lld\n",w[i]+y);return 0;}
	else if (w[i]-y>=0 && !hash[w[i]-y] && hash[w[i]-x-y]) {puts("1");printf("%lld\n",w[i]-y);return 0;}
	else if (w[i]-x>=0 && !hash[w[i]-x] && hash[w[i]-x-y]) {puts("1");printf("%lld\n",w[i]-x);return 0;}
	else if (w[i]-y>=0 && !hash[w[i]-y] && hash[w[i]+x-y]) {puts("1");printf("%lld\n",w[i]-y);return 0;}
	else if (w[i]-x>=0 && !hash[w[i]-x] && hash[w[i]-x+y]) {puts("1");printf("%lld\n",w[i]-x);return 0;}
	else if (w[i]+y<=l && !hash[w[i]+y] && hash[w[i]+y-x]) {puts("1");printf("%lld\n",w[i]+y);return 0;}
	else if (w[i]+x<=l && !hash[w[i]+x] && hash[w[i]+x-y]) {puts("1");printf("%lld\n",w[i]+x);return 0;}
	puts("2");
	printf("%lld %lld\n",x,y);
}

