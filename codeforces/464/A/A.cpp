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
char s[2000];
int n,p;
int main()
{
	scanf("%d%d",&n,&p);n--;
	scanf("%s",s);
	drep(i,n,0) rep(ch,s[i]+1,p+'a'-1)
	if ((i<1 || ch!=s[i-1]) && (i<2 || ch!=s[i-2]))
	{
		rep(j,0,i-1) printf("%c",s[j]);
		printf("%c",ch);
		s[i]=ch;
		rep(j,i+1,n)
		{
			int flag=0;
			rep(ch,'a',p+'a'-1)
			if ((j<1 || ch!=s[j-1]) && (j<2 || ch!=s[j-2]))
			{
				s[j]=ch;printf("%c",ch);flag=1;
				break;
			}
			if (!flag) {puts("NO");exit(0);}
		}
		exit(0);
	}
	puts("NO");
}

