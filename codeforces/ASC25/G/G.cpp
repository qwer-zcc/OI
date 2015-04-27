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
struct point
{
	int x,y,z;
	point(){}
	point(int _x,int _y,int _z) : x(_x),y(_y),z(_z) {}
};
int id[10][10][10],a,b,c,vis[1000],ans[1000],al,limit;
point pos[1000];
set<int> E[1000];
int Get_id(int x,int y,int z) {return (x-1)*b*c+(y-1)*c+z;}
int Valid(int o1,int o2,int o3)
{
	int a[3];a[0]=a[1]=a[2]=0;
	a[abs(o1)]=a[abs(o2)]=a[abs(o3)]=1;
	return a[0] && a[1] && a[2];
}
int In(int x,int y,int z) {return x>=1 && x<=a && y>=1 && y<=b && z>=1 && z<=c;}
int dfs(int p)
{
	pair<int,int> can[200];int cl=0;
	vis[p]=1;ans[++al]=p;
	if (al==a*b*c) return 1;
	for (set<int>::iterator It=E[p].begin();It!=E[p].end();It++)
		E[*It].erase(p);
	for (set<int>::iterator It=E[p].begin();It!=E[p].end();It++)
		can[++cl]=mp(E[*It].size(),*It);
	sort(can+1,can+cl+1);
	rep(i,1,cl)
		if (!vis[can[i].second]) if (dfs(can[i].second)) return 1;
	al--;
	vis[p]=0;
	for (set<int>::iterator It=E[p].begin();It!=E[p].end();It++)
		E[*It].insert(p);
	return 0;
}
int main()
{
	freopen("knight.in","r",stdin);
	freopen("knight.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	if (a==3 && b==3 && c==3) {puts("NO");return 0;}
	rep(i,1,a) rep(j,1,b) rep(k,1,c) id[i][j][k]=Get_id(i,j,k),pos[id[i][j][k]]=point(i,j,k);
	rep(i,1,a) rep(j,1,b) rep(k,1,c)
		rep(o1,-2,2) rep(o2,-2,2) rep(o3,-2,2)
		if (Valid(o1,o2,o3) && In(i+o1,j+o2,k+o3))
		{
			E[id[i][j][k]].insert(id[i+o1][j+o2][k+o3]);
		}
	int ok=dfs(1);
	if (!ok) puts("NO");
	else
	{
		puts("YES");
		rep(i,1,al) printf("%d %d %d\n",pos[ans[i]].x,pos[ans[i]].y,pos[ans[i]].z);
	}
}
