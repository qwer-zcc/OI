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
const int N=120000;
int n;
LL ans,val[N],Val[N],Right[N][2],Left[N][2];
int main()
{
	freopen("C.in","r",stdin);
	scanf("%d",&n);
	rep(i,2,n) scanf("%I64d",&val[i]);
	rep(i,2,n)
	{
		if (val[i]==0) {Left[i][0]=Left[i][1]=0;continue;}
		Left[i][1]=Left[i-1][1]+(val[i]-1)/2*2+1;
		if (val[i]>1) Left[i][0]=Left[i-1][0]+val[i]/2*2;
	}
	rep(i,1,n) Val[i]=val[i];
	//rep(i,1,n) val[i]=val[i+1];
	rep(i,2,(n+2)/2) swap(val[i],val[n-i+2]);
	rep(i,2,n) printf("%lld ",val[i]);puts("");
	rep(i,2,n)
	{
		if (val[i]==0) {Right[i][0]=Right[i][1]=0;continue;}
		Right[i][1]=Right[i-1][1]+(val[i]-1)/2*2+1;
		if (val[i]>1) Right[i][0]=Right[i-1][0]+val[i]/2*2;
	}
	rep(i,1,n)
	{
		LL t1=Left[i][0]+Right[n-i+1][0];
		if ((Val[i]&1)||(val[n-i+1]&1)) t1++;
		LL t2=Left[i][0]+Right[n-i+1][1];
		LL t3=Left[i][1]+Right[n-i+1][0];
		t1=max(t1,max(t2,t3));
		ans=max(ans,t1);
		printf("%lld   %lld %lld  %lld %lld\n",t1,Left[i][0],Left[i][1],Right[n-i+1][0],Right[n-i+1][1]);
	}
	printf("%I64d\n",ans);
}

