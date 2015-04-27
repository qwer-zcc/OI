//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 02/11/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF ((~0U>>1)-3)
#define LLINF (~0ULL>>1)
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
int x,y,l;
pair<int,int> P[10000];
char s[100000];
int main()
{
	//freopen("A.in","r",stdin);
	scanf("%d%d",&x,&y);
	if (!x && !y) {puts("Yes");return 0;}
	scanf("%s",s+1);l=strlen(s+1);
	rep(i,1,l)
	{
		P[i]=P[i-1];
		if (s[i]=='U') P[i].second++;
		else if (s[i]=='D') P[i].second--;
		else if (s[i]=='L') P[i].first--;
		else P[i].first++;
	}
	int Nx=P[l].first,Ny=P[l].second;
	if (Nx==0 && Ny==0)
	{
		rep(i,1,l)
		if (P[i].first==x && P[i].second==y) {puts("Yes");return 0;}
		puts("No");
		return 0;
	}
	if (Nx==0)
	{
		rep(i,1,l)
		if (P[i].first==x && (y-P[i].second)/Ny>=0 && (y-P[i].second)%Ny==0)
		{
			puts("Yes");return 0;
		}
		puts("No");
		return 0;
	}
	if (Ny==0)
	{
		rep(i,1,l)
		if ((x-P[i].first)/Nx>=0 && (x-P[i].first)%Nx==0 && P[i].second==y)
		{
			puts("Yes");return 0;
		}
		puts("No");
		return 0;
	}
		rep(i,1,l){
		if ((x-P[i].first)/Nx>=0 && (x-P[i].first)%Nx==0 && (y-P[i].second)/Ny>=0 && (y-P[i].second)%Ny==0 && (x-P[i].first)/Nx==(y-P[i].second)/Ny)
		{
			puts("Yes");return 0;
		}}
		puts("No");
	
}

