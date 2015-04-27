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
int cs,n,maxb,t,hash[110000],w[110000],f[110000];
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d%d%d%d",&cs,&n,&maxb,&t);
	while (cs--)
	{
		int cnt=0,ans=0;M(hash);M(f);
		rep(i,1,n)
		{
			scanf("%d",&w[i]);
			if (!hash[w[i]]) hash[w[i]]=1,cnt++;
		}
		if (t>=cnt) {printf("%d\n",cnt);continue;}
		rep(i,1,n*t)
		{
			rep(j,w[(i-1)%n+1],maxb)
			if (f[j]<f[w[(i-1)%n+1]-1]+1) f[j]=f[w[(i-1)%n+1]-1]+1,ans=max(ans,f[j]);
			else break;
			if (ans==maxb) break;
		}
		printf("%d\n",ans);
	}
}

