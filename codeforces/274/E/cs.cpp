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
#include <windows.h>
map<pair<int,int> ,int > Hash;
int main()
{
	freopen("E.in","w",stdout);
	srand(GetTickCount());
	int n=5,m=5,k=1;
	printf("%d %d %d\n",n,m,k);
	rep(i,1,k)
	{
		int p=rand()%n+1,q=rand()%m+1;
		Hash[mp(p,q)]=1;
		printf("%d %d\n",p,q);
	}
	int p=rand()%n+1,q=rand()%m+1;
	while (Hash[mp(p,q)]) p=rand()%n+1,q=rand()%m+1;
	printf("%d %d ",p,q);
	int ty=rand()%4;
	if (!ty) puts("NE");
	else if (ty==1) puts("NW");
	else if (ty==2) puts("SE");
	else puts("SW");
}

