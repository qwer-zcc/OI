//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 05/07/2014                 |
//+-------------------------------------+
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
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
#define dep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define Chen(a,b,c) int((LL)(a)*(LL)(b)%(LL)(c))
#define pb push_back
#define mp make_pair
#define ins insert
#define ps push
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
inline void read(int &x)
{
	char ch;
	while ((ch=getchar()) && !(ch>='0' && ch<='9'));x=ch-'0';
	while ((ch=getchar()) && (ch>='0' && ch<='9')) x=x*10+ch-'0';
}
struct point
{
	int x,y;
	point() {}
	point(int _x,int _y) : x(_x),y(_y) {}
} ;
char s1[1000],s2[1000];
int g1[100],g2[100];
int main()
{
	scanf("%s%s",s1,s2);int l1=strlen(s1)-1,l2=strlen(s2)-1;
	rep(i,0,l1) g1[s1[i]-'a']++;
	rep(i,0,l2) g2[s2[i]-'a']++;
	int f1=1,f2=1;
	rep(i,0,25) if (g1[i]!=g2[i]) f1=0;
	int j=0;
	rep(i,0,l2)
	{
		while (j<=l1 && s1[j]!=s2[i]) j++;
		if (j>l1) f2=0;
		j++;
	}
	if (f1) {puts("array");return 0;}
	if (f2) {puts("automaton");return 0;}
	f1=1;
	rep(i,0,25) if (g1[i]<g2[i]) f1=0;
	puts(f1?"both":"need tree");
}

