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
const int N=1200000;
int n,r,c,f[N][22],len[N],sum[N],fail[N],ans,S;
string s[N];
int main()
{
	//freopen("B.in","r",stdin);
	scanf("%d%d%d",&n,&r,&c);
	rep(i,1,n) cin>>s[i],len[i]=s[i].size();
	rep(i,1,n) sum[i]=sum[i-1]+len[i]+1;
	rep(i,1,n)
	{
		if (len[i]>c) {f[i][0]=i,fail[i]=1;continue;}
		int l=i,r=n,mid,ans;
		while (l<=r)
		{
			int mid=l+r>>1;
			if (sum[mid]-sum[i-1]-1<=c) ans=mid,l=mid+1;else r=mid-1;
		}
		f[i][0]=ans+1;
	}
	f[n+1][0]=n+1;
	rep(j,1,21)
	rep(i,1,n+1) f[i][j]=f[f[i][j-1]][j-1];
	rep(i,1,n)
	{
		int now=i;
		rep(j,0,21)
		if (r&(1<<j)) now=f[now][j];
		if (now-i>ans) ans=now-i,S=i;
	}
	while (S!=n+1 && r)
	{
		int T=f[S][0]-1;
		if (T<S) break;
		rep(i,S,T-1) cout<<s[i]<<" ";
		cout<<s[T]<<endl;
		S=T+1;
		r--;
	}
}

