//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 14/08/2014                 |
//+-------------------------------------+
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
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
#define Chen(a,b,c) int((LL)(a)*(LL)(b)%(LL)(c))
#define pb push_back
#define mp make_pair
#define ps push
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
const int N=2000000;
char s1[N],s2[N];
int ans[N],now[N],l1,l2,k;
int ok(int i,int j,int jp)
{
	while (i<=l2)
	{
		if (j>l1) return 0;
		if (s2[i]!=s1[j]) return 0;
		j+=k;
		i+=jp;
	}
	return j>l1;
}
int main()
{
	//freopen("E.in","r",stdin);
	gets(s1+1);gets(s2+1);s1[0]=s2[0]='?';
	l1=strlen(s1)-1,l2=strlen(s2)-1;
	scanf("%d",&k);
	rep(i,1,k) ans[i]=1;
	rep(i,1,l2)
	{
		int j=k;
		drep(I,i,1)
		{
			while (j && !ok(I,j,i)) j--;
			if (!j) {j--;break;}
			now[j]=1;
			j--;
		}
		if (j>=0)
		{
			int flag=1;
			rep(p,1,k)
			if (now[p]>ans[p]) {flag=0;break;}
			else if (now[p]<ans[p]) break;
			if (flag)
			{
				rep(p,1,k) ans[p]=now[p],now[p]=0;
				ans[0]=1;
			}
			else rep(p,1,k) now[p]=0;
		}
		else rep(p,1,k) now[p]=0;
	}
	if (ans[0])
	{
		rep(i,1,k) printf("%d",ans[i]);
		puts("");
	}
	else puts("0");
}

