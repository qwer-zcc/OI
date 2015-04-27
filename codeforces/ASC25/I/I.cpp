#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define INF int(1e8)
#define LL long long
#define D double
#define LD long double
#define pb push_back
#define mp make_pair
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
const int N=220000;
struct lj{int x,y,id[4];}P[N];
set<pair<int,int> > E[4][N];
int n,ans;
struct Hash
{
	int a[N];
	int ty,al;
	void insert(int x) {a[++al]=x;ty=1;}
	int Get_id(int x)
	{
		if (ty==1)
		{
			sort(a+1,a+al+1);
			al=unique(a+1,a+al+1)-a-1;
			ty=0;
		}
		return lower_bound(a+1,a+al+1,x)-a;
	}
}H[4];
int main()
{
	freopen("queen2.in","r",stdin);
	freopen("queen2.out","w",stdout);
	scanf("%d",&n);int x,y;
	rep(i,1,n)
	{
		scanf("%d%d",&x,&y);
		H[0].insert(x);H[1].insert(y);
		H[2].insert(x+y);H[3].insert(x-y);
		P[i].x=x;P[i].y=y;
	}
	rep(i,0,3) H[i].insert(0);
	rep(i,0,3) P[0].id[i]=H[i].Get_id(0);
	rep(i,1,n)
	{
		P[i].id[0]=H[0].Get_id(P[i].x);
		P[i].id[1]=H[1].Get_id(P[i].y);
		P[i].id[2]=H[2].Get_id(P[i].x+P[i].y);
		P[i].id[3]=H[3].Get_id(P[i].x-P[i].y);
	}
	rep(i,0,n) rep(j,0,3) E[j][P[i].id[j]].insert(mp(P[i].x,P[i].y));
	rep(i,1,n)
	{
		int flag=0;
		rep(j,0,3)
			if (P[i-1].id[j]==P[i].id[j])
			{
				int x=P[i].x,y=P[i].y,xx=P[i-1].x,yy=P[i-1].y;
				if (P[i-1].x<x || (P[i-1].x==x && P[i-1].y<y)) x=P[i-1].x,y=P[i-1].y,xx=P[i].x,yy=P[i].y;
				set<pair<int,int> >::iterator It=E[j][P[i].id[j]].upper_bound(mp(x,y));
				if (It->first==xx && It->second==yy) ans++,flag=1;
				break;
			}
		rep(j,0,3) E[j][P[i-1].id[j]].erase(mp(P[i-1].x,P[i-1].y));
		if (!flag) break;
	}
	printf("%d\n",ans);
}
