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
    int a,b;
    point() {}
    point(int _x,int _y) : a(_x),b(_y) {}
} P[10000];
int n,V[10000],Ans;
int cmp(point a,point b){return a.b<b.b||(a.b==b.b&&a.a<b.a);}
int Can(int i)
{
	rep(j,1,n)
	if (P[j].a<P[i].a&&!V[j]) return 0;
	return 1;
}
int main()
{
	freopen("1.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d%d",&P[i].a,&P[i].b);
	sort(P+1,P+n+1,cmp);
	rep(i,1,n){ rep(j,1,n)
		if (P[j].a<=P[i].b) V[j]=1;
		if (Can(i)) Ans=max(Ans,P[i].b),V[i]=1;
		else Ans=max(Ans,P[i].a);
	}
	printf("%d\n",Ans);
}

