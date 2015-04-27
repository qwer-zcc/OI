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
int n,m,l;
LL ans;
int calc(int i,int x,int y,int z)
{
	return (x+z*i)/(i+y)+1;
}
int find(int i,int x,int y,int z,int c,int T)
{
	//return i;
	if (z-c-1==0) return i;
	int I=(y*z-x)/(z-c-1)-y;
	while (I<T && calc(I,x,y,z)<=c) I++;
	while (I>i && calc(I,x,y,z)>c) I--;
	printf("%d %d\n",i,I);
	return I;
}
int main()
{
	scanf("%d%d",&n,&m);l=n+1;
	rep(j,m+1,n-m)
	{
		rep(i,m+1,n-m)
		{
			int x=j*(j*2-l*3)+l*l,y=l-j,z=l+j;
			int c=(x+z*i)/(i+y)+1;
			int I=find(i,x,y,z,c,n-m);
			I=min(I,n-m);
			int Min=max(c,m+1);
			if (Min<=n-m) ans+=(LL)(n-m-Min+1)*(I-i+1);
			else break;
			i=I;
		}
	}
	printf("%lld\n",ans*3LL);
}

/*
5 5
4 5 5
3 4 5
3 5
4
*/
