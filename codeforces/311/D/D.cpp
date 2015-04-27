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
void build(int w,int l,int r)
{
	t[w].l=l;t[w].r=r;
	if (l==r)
	{
		t[w].a[0]=1;
		rep(i,1,47) t[w].a[i]=(t[w].a[i-1]*3)%Mod;
		return;
	}
	int mid=l+r>>1;
	build(w<<1,l,mid);build(w<<1|1,mid+1,r);
	update(w);
}
void add(int w,int l,int r)
{
	if (t[w].l==l && t[w].r==r)
	{
		
	}
}
int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&w[i]);
	build(1,1,n);
	scanf("%d",&m);
	rep(i,1,m)
	{
		scanf("%d",&ty);
		if (ty==1)
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",ask(1,l,r));
		}
		else
		{
			scanf("%d%d",&l,&r);
			add(1,l,r);
		}
	}
}

