//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 30/09/2014                 |
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
int A[100000],n,s,a[100000];
int main()
{
	//freopen("G.in","r",stdin);
	scanf("%d%d",&n,&s);
	int S=n*(n-1)/2-s;
	if (S&1) {puts("-1");return 0;}
	rep(i,2,n)
	if (S>=(n-i+1)*2) a[i]=1,S-=(n-i+1)*2;
	else break;
	a[n-S/2+1]=1;
	int now=0,ans=0;
	A[1]=now;
	rep(i,2,n) now+=a[i]?-1:1,A[i]=now,ans+=now;
	if (ans==s)
	{
		rep(i,1,n) printf("%d ",A[i]);
	}
	else puts("-1");
}

