//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 14/08/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
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
int vis[N],a[N],n,opt[N],to[N],ok[N];
int nxt(int c){return ((c<<1)+opt[c])%n;}
void sc()
{
	int last=0;
	for (int i=0;((i<<1)+opt[i])%n!=0;i=((i<<1)+opt[i])%n) printf("%d ",last=i);
	printf("%d ",((last<<1)+opt[last])%n);
	puts("0");
}
void dfs(int c)
{
	if (vis[((c<<1)+opt[c]^1)%n]||ok[c])
	{
		c=nxt(c);
		if (c==0) {sc();exit(0);}
		dfs(c);
	}
	opt[c]^=1;opt[to[c]]^=1;ok[c]=ok[to[c]]=1;
	int C=nxt(c);
	while (!vis[C]) vis[C]=1,C=nxt(C);
	dfs(nxt(c));
}
int main()
{
	scanf("%d",&n);
	if (n&1) {puts("-1");return 0;}
	vis[0]=1;
	rep(i,0,n-1) to[i]=(i+n/2)%n,opt[i]=i>=n/2;
	dfs(0);
}

