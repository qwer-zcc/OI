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
#define INF 1000000000
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
int ans;
map<int,int>Hash[3000000];
struct lj{int x,y;}P[120000];
int gs[3000000];
int n;
inline int cmp(lj a,lj b){return a.x<b.x||(a.x==b.x && a.y<b.y);}
int main()
{
	freopen("D.in","r",stdin);
	scanf("%d",&n);int Len=int(sqrt(n));
	rep(i,1,n) scanf("%d%d",&P[i].x,&P[i].y),P[i].x+=1000011,P[i].y+=1000011;
	sort(P+1,P+n+1,cmp);
	P[0].x=P[n+1].x=-INF;int l=0,r=0;
	//printf(" %d\n",Len);
	rep(i,1,n+1)
	{
		if (P[i].x!=P[i-1].x)
		{
			if (l)
			{
				if (r-l+1<=Len)
				{
					rep(j,l,r) rep(k,j+1,r)
					if (P[j].y!=P[k].y && Hash[P[j].x-(P[k].y-P[j].y)][P[j].y] && Hash[P[k].x-(P[k].y-P[j].y)][P[k].y]) ans++;
				}
				else
				{
					rep(j,l,r) gs[P[j].y]++;
					int kk=2;
					rep(j,1,l-1)
					rep(k,j+1,l-1)
					if (P[j].x==P[k].x)
					{
						if (P[j].x+P[k].y-P[j].y==P[l].x)
						ans+=gs[P[j].y]*gs[P[k].y];
						else if (P[j].x+P[k].y-P[j].y>P[l].x) break;
					}
					else break;
					rep(j,l,r) gs[P[j].y]--;
				}
				rep(j,l,r) Hash[P[j].x][P[j].y]=1;
			}
			l=r=i;
		}
		else r++;
	}
	printf("%d\n",ans);
}
