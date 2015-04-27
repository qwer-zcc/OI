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
const int N=120000;
struct point
{
    LL x,y;int id;
    point() {}
    point(int _x,int _y) : x(_x),y(_y) {}
} P[N];
int a,b,c,d,n,t[N],ans,dp[N],vis[N];
LL hash[N],hx[N];
inline int cmp(const point &a,const point &b) {return a.x<b.x||(a.x==b.x && a.y<b.y);}
int add(int x,int c)
{
	for (int i=x;i<=n;i+=i&(-i)) t[i]=max(t[i],c);
}
int ask(int x)
{
	int ans=0;
	for (int i=x;i;i-=i&(-i)) ans=max(ans,t[i]);
	return ans;
}
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d",&n);int x,y;
	scanf("%d/%d %d/%d",&a,&b,&c,&d);
	rep(i,1,n)
	{
		scanf("%d%d",&x,&y);
		P[i].x=(LL)d*y-(LL)c*x;
		P[i].y=(LL)a*x-(LL)b*y;
		if ((LL)a*d-(LL)b*c<0) P[i].x=-P[i].x,P[i].y=-P[i].y;
		//printf("!!! %lld %lld     %d %d\n",P[i].x,P[i].y,x,y);
		if (P[i].x<=0 || P[i].y<=0) P[i].id=1;
	}
	sort(P+1,P+n+1,cmp);
	rep(i,1,n) hash[i]=P[i].x;
	sort(hash+1,hash+n+1);
	rep(i,1,n) hx[i]=hash[i];
	rep(i,1,n) P[i].x=(LL)(lower_bound(hash+1,hash+n+1,P[i].x)-hash);
	rep(i,1,n) hash[i]=P[i].y;
	sort(hash+1,hash+n+1);
	rep(i,1,n) P[i].y=(LL)(lower_bound(hash+1,hash+n+1,P[i].y)-hash);
	rep(i,1,n)
	if (!P[i].id)
	{
		//printf("%lld %lld   %lld %lld\n",P[i].x,P[i].y,hx[P[i].x],hash[P[i].y]);
		dp[i]=ask(P[i].y-1)+1;
		if (P[i].x!=P[i+1].x)
		{
			int j=i;
			while (P[j].x==P[i].x) add(P[j].y,dp[j]),j--;
		}
		//add(P[i].y,dp[i]);
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
}

