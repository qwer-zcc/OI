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
void fail() {puts("NO");exit(0);}
LL lcm(LL x,LL y)
{
	LL gcd=__gcd(x,y);
	x/=gcd;
	if ((LD)x*(LD)y>1e13) fail();
	return x*y;
}
namespace CRT   //Chinese_Remainder_Theorem
{
	struct Equation
	{
		LL r,p;
		Equation() {}
		Equation(LL _r,LL _p) : r(_r),p(_p) {}
	}Now;
	void fail() // Can't find the answer
	{
		puts("NO");
		exit(0);
	}
	void Init()
	{
		Now=Equation(0,0);
	}
	void Ex_gcd(LL a,LL b,LL &x,LL &y)
	{
		if (!b) x=1,y=0;
		else Ex_gcd(b,a%b,y,x),y-=a/b*x;
	}
	LL Mul(LL x,LL y,LL Mod)
	{
		return (x*y-(LL)(((LD)x*y)/Mod)*Mod)%Mod;
	}
	Equation Combine(LL r1,LL p1,LL r2,LL p2)
	{
		LL G=__gcd(p1,p2),x,y,R;
		Ex_gcd(p1/G,p2/G,x,y);
		if (x<0) x+=p2/G;
		R=(r2-r1)%(p2);
		if (R<0) R+=p2;
		if (R%G!=0) fail();
		x=Mul(x,R/G,p2/G);
		LL p=p1/G*p2;
		return Equation(  (Mul(x,p1,p)+r1)%p,p  );
	}
	void insert(LL r,LL p)
	{
		r%=p;
		if (!Now.p) {Now=Equation(r,p);return;}
		if (p==1) return;
		Now=Combine(Now.r,Now.p,r,p);
	}
}
LL n,m,a[20000],Lcm;
int k;
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%I64d%I64d%d",&n,&m,&k);
	rep(i,1,k) scanf("%I64d",&a[i]),Lcm=Lcm==0?a[i]:lcm(Lcm,a[i]);
	if (Lcm>n) fail();
	CRT::Init();
	drep(i,k,1) CRT::insert(k-i,a[i]);
	LL ans=CRT::Now.r;
	while (ans<k) ans+=CRT::Now.p;
	if (ans>m) fail();
	drep(i,k,1)
	if (__gcd(ans-k+i,Lcm)!=a[i]) fail();
	puts("YES");
}

