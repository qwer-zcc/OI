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
const int N=10000;
char s[N];
int n,vis[N],sg[N],ok[N];
int calc()
{
	int c=0,ans=0;
	rep(i,1,n)
	{
		if (ok[i]) c++;
		else if (c) ans^=sg[c],c=0;
	}
	if (c) ans^=sg[c];
	return ans;
}
int main()
{
	//freopen("E.in","r",stdin);
	scanf("%s",s+1);n=strlen(s+1);
	rep(i,1,n)
	{
		rep(j,0,n+1) vis[j]=0;
		rep(j,1,i) vis[sg[max(j-2,0)]^sg[max(i-j-1,0)]]=1;
		rep(j,0,n+1)
		if (!vis[j]) {sg[i]=j;break;}
	}
	rep(i,2,n-1)
	if (s[i-1]==s[i+1]) ok[i]=1;
	if (!calc()) {puts("Second");return 0;}
	puts("First");
	rep(i,1,n)
	if (ok[i])
	{
		int x=ok[i-1],y=ok[i],z=ok[i+1];
		ok[i-1]=ok[i]=ok[i+1]=0;
		if (!calc()) {printf("%d\n",i);break;}
		ok[i-1]=x,ok[i]=y,ok[i+1]=z;
	}
}

