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
const int N=10000;
vector<int> E[N];
char s[N];
int n,rd[N],dy[N],dis[N];
queue<int> Q;
int main()
{
	freopen("H.in","r",stdin);
	scanf("%d",&n);
	scanf("%s",s+1);s[0]='?';int l=strlen(s)-1;
	dy[1]=1;
	rep(i,1,l)
	if (s[i]=='=') dy[i+1]=dy[i];
	else dy[i+1]=i+1;
	rep(i,1,l)
	if (s[i]=='>')
	{
		E[dy[i+1]].pb(dy[i]);
		rd[dy[i]]++;
	}
	else if (s[i]=='<')
	{
		E[dy[i]].pb(dy[i+1]);
		rd[dy[i+1]]++;
	}
	rep(i,1,l+1)
	if (!rd[i]) Q.push(i);
	while (Q.size())
	{
		int x=Q.front();Q.pop();
		for (int i=0;i<E[x].size();i++)
		{
			rd[E[x][i]]--;
			dis[E[x][i]]=max(dis[E[x][i]],dis[x]+1);
			if (!rd[E[x][i]]) Q.push(E[x][i]);
		}
	}
	rep(i,1,l+1)
	if (dis[dy[i]]+1>n) {puts("-1");return 0;}
	rep(i,1,l+1) printf("%c",dis[dy[i]]+'a');puts("");
}

