//|     By   qwer_zcc                   |
//|     Date 30/09/2014                 |
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
#define INF (~0U>>1)-1
#define LLINF ~0ULL>>1
#define LL long long
#define uLL unsigned long long
#define uint unsigned int
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
const int N=1200000;
pair<int,int> P[N],Q[N];
int n,t[N*20],L[N*20],R[N*20],cnt,root[N];
void add(int &p,int q,int l,int u,int v)
{
	if (!p) t[p=++cnt]=t[q];
	t[p]++;
	if (u==v) return;
	int mid=u+v>>1;
	if (l<=mid) R[p]=R[q],add(L[p],L[q],l,u,mid);
	else L[p]=L[q],add(R[p],R[q],l,mid+1,v);
}
int ask(int p,int q,int l,int r,int u,int v)
{
	if (l==u && r==v) return t[q]-t[p];
	int mid=u+v>>1;
	if (r<=mid) return ask(L[p],L[q],l,r,u,mid);
	else if (l>mid) return ask(R[p],R[q],l,r,mid+1,v);
	else return ask(L[p],L[q],l,mid,u,mid)+ask(R[p],R[q],mid+1,r,mid+1,v);
}
int f(int a,int b) {return (a+b-1)%n+1;}
int m,a,b,c,d;
int main()
{
	//freopen("C.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a),P[a].first=i;
	rep(i,1,n) scanf("%d",&a),P[a].second=i;
	sort(P+1,P+n+1);
	rep(i,1,n) add(root[P[i].first],root[P[i].first-1],P[i].second,1,n);
	scanf("%d",&m);int last=-1;
	rep(i,1,m)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);last++;
		int A=f(a,last),B=f(b,last),C=f(c,last),D=f(d,last);
		a=min(A,B);b=max(A,B);c=min(C,D);d=max(C,D);
		printf("%d\n",last=ask(root[a-1],root[b],c,d,1,n));
	}
}

