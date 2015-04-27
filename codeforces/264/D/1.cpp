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
const int N=1100000;
char a[N],b[N];
int n,m,nxt[N],pos[10],mnb[N],mna[N],lna[N],sum[10][N];
LL ans;
int ch(char x)
{
	if (x=='R') return 0;
	else if (x=='G') return 1;
	else return 2;
}
int get(char x,char y)
{
	return ch(x)*3+ch(y);
}
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%s%s",a+1,b+1);n=strlen(a+1),m=strlen(b+1);
	drep(i,m,1)
	{
		nxt[i]=pos[ch(b[i])];
		pos[ch(b[i])]=i;
	}
	int now=1;
	rep(i,1,m)
	{
		while (now<n && a[now]!=b[i]) now++;
		mnb[i]=now;
		if (now<n) now++;
	}
	now=1;
	rep(i,1,n)
	{
		while (now<m && b[now]!=a[i]) now++;
		mna[i]=now;
		if (now<m) now++;
	}
	now=1;
	rep(i,1,n)
	{
		while (now<=m && mnb[now]<i) now++;
		lna[i]=now;
	}
	rep(i,2,m) sum[get(b[i-1],b[i])][i]=1;
	rep(i,1,8)
	rep(j,1,m) sum[i][j]+=sum[i][j-1];
	
	ans+=(LL)(mna[1]-lna[1]+1);
	rep(i,2,n)
	{
		ans+=(LL)(mna[i]-lna[i]+1);
		if (a[i]==a[i-1]) continue;
		ans-=(LL)(sum[get(a[i],a[i-1])][mna[i]]-sum[get(a[i],a[i-1])][lna[i]-1]);
	}
	printf("%I64d\n",ans);
}

