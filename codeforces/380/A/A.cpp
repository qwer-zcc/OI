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
struct lj{int x,l;}P[N];
map<LL,int> hash;
LL num[N];
int n,m;
int ask(LL x)
{
	if (hash[x]) return hash[x];
	int c=lower_bound(num+1,num+m+1,x)-num,t=(x-num[c-1])%(LL)P[c].l;
	if (t==0) t+=P[c].l;
	return ask(t);
}
int main()
{
	//freopen("A.in","r",stdin);
	scanf("%d",&m);int ty;
	rep(i,1,m)
	{
		scanf("%d",&ty);
		if (ty==1)
		{
			scanf("%d",&P[i].x);
			hash[num[i-1]+1]=P[i].x;
			num[i]=num[i-1]+1;
		}
		else
		{
			scanf("%d%d",&P[i].l,&P[i].x);
			num[i]=num[i-1]+(LL)P[i].l*P[i].x;
		}
	}
	scanf("%d",&n);LL x;
	rep(i,1,n)
	{
		scanf("%I64d",&x);
		printf("%d ",ask(x));
	}
}

