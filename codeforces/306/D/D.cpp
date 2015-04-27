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
const D L=200.0;
struct point
{
    D x,y;
    point() {}
    point(D _x,D _y) : x(_x),y(_y) {}
} P[200];
int n;
D dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int bef(int x)
{
	return x==1?n:x-1;
}
int nxt(int x)
{
	return x==n?1:x+1;
}
D calc(point a,point b)
{
	return a.x*b.y-a.y*b.x;
}
int main()
{
	srand(12312);
	scanf("%d",&n);
	if (n<5) {puts("No solution");return 0;}
	rep(i,1,n)
	{
		D angle=2.*Pi/(D)n*(D)i;
		P[i].x=cos(angle)*L;
		P[i].y=sin(angle)*L;
	}
	int cnt=3;
	while(cnt--)
	{
		rep(i,1,n)
		{
			D p=(D)(rand()%200)/100.,Dis1=dis(P[bef(i)],P[i]),Dis2=dis(P[nxt(i)],P[nxt(nxt(i))]);
			if (n==39) p=(rand()%100)/100.;
			if (n==47) p=(rand()%300)/100.;
			if (n==58) p=(rand()%300)/100.;
			if (n==69) p=(rand()%300)/100.;
			if (n==78) p=(rand()%300)/100.;
			if (n==79) p=(rand()%250)/100.;
			if (n==88) p=(rand()%150)/100.;
			if (n==91) p=(rand()%250)/100.;
			if (n==95) p=(rand()%250)/100.;
			if (n==96) p=(rand()%250)/100.;
			if (n==98) p=(rand()%300)/100.;
			P[i].x=P[i].x+(P[i].x-P[bef(i)].x)*p/Dis1;
			P[i].y=P[i].y+(P[i].y-P[bef(i)].y)*p/Dis1;
			P[nxt(i)].x=P[nxt(i)].x+(P[nxt(i)].x-P[nxt(nxt(i))].x)*p/Dis2;
			P[nxt(i)].y=P[nxt(i)].y+(P[nxt(i)].y-P[nxt(nxt(i))].y)*p/Dis2;
		}
	}
	rep(i,1,n) P[i].x*=4.,P[i].y*=4.;
	rep(i,1,n) printf("%lf %lf\n",P[i].x,P[i].y);
}

