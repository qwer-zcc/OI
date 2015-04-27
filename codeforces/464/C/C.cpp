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
const int N=120000,Mod=1000000007;
char S[N],s[N];
string ch[N];
int Len[N],To[N],n;
int Chen(int a,int b){return (LL)a*b%(LL)Mod;}
inline int Pow(int a,int k)
{
	int ans=1,b=a;
	while (k)
	{
		if (k&1) ans=(LL)ans*b%(LL)Mod;
		b=(LL)b*b%(LL)Mod;k>>=1;
	}
	return ans;
}
int main()
{
	//freopen("C.in","r",stdin);
	scanf("%s",S);
	scanf("%d",&n);
	rep(i,0,9) Len[i]=1,To[i]=i;
	rep(i,1,n) cin>>ch[i];
	drep(i,n,1)
	{
		int l=-1;
		for (int j=0;j<ch[i].size();j++) s[++l]=ch[i][j];
		int len=0,to=0;
		rep(j,3,l) to=(Chen(to,Pow(10,Len[s[j]-'0']))+To[s[j]-'0'])%Mod,len=(len+Len[s[j]-'0'])%(Mod-1);
		Len[s[0]-'0']=len;
		To[s[0]-'0']=to;
	}
	int l=strlen(S)-1,ans=0;
	rep(i,0,l) ans=(Chen(ans,Pow(10,Len[S[i]-'0']))+To[S[i]-'0'])%Mod;
	printf("%d\n",ans);
}

