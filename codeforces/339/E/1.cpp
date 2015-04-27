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
int n,val[2000],l,r,pos[2000];
int main()
{
	freopen("E.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&val[i]);
	rep(i,1,n) val[i]=i;
	rep(i,1,n) pos[val[i]]=i;
	while (scanf("%d%d",&l,&r)!=EOF)
	{
		rep(i,l,(l+r)>>1) swap(val[i],val[l+r-i]);
		rep(i,l,r) pos[val[i]]=i;
		int flag=1;
		rep(i,1,n)
		if (val[i]!=i) {flag=0;break;}
		if (flag) puts("YES");
	}
	rep(i,1,n) printf("%d ",val[i]);puts("");
}

