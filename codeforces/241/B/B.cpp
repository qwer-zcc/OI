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
#define Dep 30
const int Mod=1000000007;
const int N=100010;
LL m;
int is[N*31],num[N*31],son[N*31][2],cnt=1,n,val[N],sum[16*81000][32];
void Add(int rt,int x,int Ddep)
{
	drep(i,Ddep,0) sum[rt][Ddep-i+1]+=(x>>i)&1;
}
void add(int x)
{
	int rt=1;
	drep(i,Dep,0)
	{
		int a=(x>>i)&1;
		Add(rt,x,i);
		if (!son[rt][a]) son[rt][a]=++cnt;
		rt=son[rt][a];
		if (i==0) is[rt]++;
		num[rt]++;
	}
}
LL Num(int x,int c)
{
	int rt=1;
	LL ans=0;
	drep(i,Dep,0)
	{
		int a=(x>>i)&1,b=(c>>i)&1;
		if (!a && !b) ans+=(LL)num[son[rt][1]],rt=son[rt][0];
		else if (!a && b) rt=son[rt][1];
		else if (a && !b) ans+=(LL)num[son[rt][0]],rt=son[rt][1];
		else if (a && b) rt=son[rt][0];
	}
	return ans;
}
LL Ask_num(int mid)
{
	LL ans=0;
	rep(i,1,n) ans+=Num(val[i],mid);
	return ans/2;
}
LL bl(int rt,int x,int Ddep)
{
	if (!rt) return 0;
	LL ans=0;
	drep(i,Ddep,0)
	{
		if ((x>>i)&1) ans+=(LL)(num[rt]-sum[rt][Ddep-i+1])*(LL)(1<<i);
		else ans+=(LL)sum[rt][Ddep-i+1]*(LL)(1<<i);
	}
	return ans;
}
LL Sum(int x,int c)
{
	int rt=1,now=0;
	LL ans=0;
	drep(i,Dep,0)
	{
		int a=(x>>i)&1,b=(c>>i)&1;
		if (a) x-=1<<i;
		if (!a && !b) ans+=(LL)(now+(1<<i))*(LL)num[son[rt][1]]+(LL)bl(son[rt][1],x,i-1),rt=son[rt][0];
		else if (!a && b) rt=son[rt][1],now+=(1<<i);
		else if (a && !b) ans+=(LL)(now+(1<<i))*(LL)num[son[rt][0]]+(LL)bl(son[rt][0],x,i-1),rt=son[rt][1];
		else if (a && b) rt=son[rt][0],now+=(1<<i);
	}
	return ans;
}
LL Ask_sum(int mid)
{
	LL ans=0;
	rep(i,1,n) ans=ans+Sum(val[i],mid);
	return ans/2;
}
int main()
{
	//freopen("B.in","r",stdin);
	scanf("%d%lld",&n,&m);
	rep(i,1,n) scanf("%d",&val[i]),add(val[i]);
	int l=0,r=2000000000,ax=r;
	while (l<=r)
	{
		int mid=int(((LL)l+r)/2LL);
		if (Ask_num(mid)>=m) l=mid+1;else ax=min(ax,mid),r=mid-1;
	}
	printf("%lld\n",((LL)Ask_sum(ax)+(LL)(m-Ask_num(ax))*(LL)ax)%(LL)Mod);
}

