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
    int x,y,z,id;
    point() {}
    point(int _x,int _y,int _z,int _id) : x(_x),y(_y),z(_z),id(_id) {}
} ;
void add(int a,int b,int c,int id)
{
	Hash[point(a,b,c)]++;
	Hash[point(a,c,b)]++;
	Hash[point(b,a,c)]++;
	Hash[point(b,c,a)]++;
	Hash[point(c,a,b)]++;
	Hash[point(c,b,a)]++;
}
map<int,int> a,b;
int main()
{
	rep(i,1,8) scanf("%d%d%d",&P[i].x,&P[i].y,&P[i].z),add(P[i].x,P[i].y,P[i].z,i),P[i].id=i;
	rep(i,1,5) rep(j,i+1,6) rep(k,j+1,7) rep(l,k+1,8)
	if (check(i,j,k,l))
	{
		puts("YES");
		rep(p,1,8) printf("%d %d %d\n",Ans[p].x,Ans[p].y,Ans[p].z);
		exit(0);
	}
}

