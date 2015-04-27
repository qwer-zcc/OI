//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 02/11/2014                 |
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
const int N=2010;
vector<int> E[N],F[N];
int n,k,x;
LD ans,C[N][N];
const LD eps=1e-7;
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d%d",&n,&k);
	rep(i,1,n) rep(j,i+1,n)
	{
		scanf("%d",&x);
		if (x!=-1) E[i].pb(j),E[j].pb(i),F[i].pb(x),F[j].pb(x);
	}
	C[0][0]=1;
	rep(i,1,n)
	{
		C[i][0]=1;
		rep(j,1,n) C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	rep(i,1,n)
	if (E[i].size()>=k)
	{
		for (int j=0;j<F[i].size();j++)
		ans+=(LD)F[i][j]*(LD)(C[E[i].size()-1][k-1]/C[n][k]);
	}
	printf("%I64d\n",(LL)(ans+eps));
}

