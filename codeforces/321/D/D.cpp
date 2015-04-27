//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 02/11/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF int(2e9)
#define LLINF (LL)(8e18)
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
LL Pow(LL a,LL b,LL Mod){LL ans=1;a%=Mod;for(;b;b>>=1) ans=b&1?(ans*a%Mod):ans,a=a*a%Mod;return ans;}
const int N=40;
int n,ans,val[N][N],a[N];
inline int calc(int x,int c){return x*(c?-1:1);}
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n) rep(j,1,n) scanf("%d",&val[i][j]);
	int x=(n+1)>>1;
	rep(_,0,(1<<x)-1)
	{
		int sum=0;
		rep(i,0,x-1) a[i+1]=(_&(1<<i))>0;
		rep(i,1,x-1) a[i+x]=a[x]^a[i];
		rep(i,1,n) sum+=calc(val[i][x],a[i]);
		rep(i,1,x-1)
		{
			int s1=calc(val[x][i],0)+calc(val[x][i+x],a[x]);
			rep(j,1,x-1)
			s1+=max( calc(val[j][i],0)+calc(val[j][i+x],a[j])+calc(val[j+x][i],0)+calc(val[j+x][i+x],a[j+x]),
					 calc(val[j][i],1)+calc(val[j][i+x],a[j]^1)+calc(val[j+x][i],1)+calc(val[j+x][i+x],a[j+x]^1));
			int s2=calc(val[x][i],1)+calc(val[x][i+x],a[x]^1);
			rep(j,1,x-1)
			s2+=max( calc(val[j][i],0)+calc(val[j][i+x],a[j])+calc(val[j+x][i],1)+calc(val[j+x][i+x],a[j+x]^1),
					 calc(val[j][i],1)+calc(val[j][i+x],a[j]^1)+calc(val[j+x][i],0)+calc(val[j+x][i+x],a[j+x]));
			sum+=max(s1,s2);
		}
		ans=max(ans,sum);
	}
	printf("%d\n",ans);
}

