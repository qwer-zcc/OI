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
#include <stack>
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
struct Tri
{
	double x,y,id;
	Tri(){}
	Tri(double _x,double _y,int _id) : x(_x),y(_y),id(_id) {}
	int operator < (Tri a) {return x<a.x||(x==a.x && y<a.y);}
};
struct vec
{
	double x,y;
	vec(){}
	vec(Tri a,Tri b) : x(b.x-a.x),y(b.y-a.y) {}
	double operator *(vec a) {return x*a.y-y*a.x;}
};
inline int cmp(const lj &a,const lj &b) {return (a.y-Tmp.y)*(b.x-Tmp.x)<(b.y-Tmp.y)*(a.x-Tmp.x);}
vector<Tri> convex(vector<Tri> a)
{
	sort(a.begin(),a.end());
	Tmp=a[0];
	sort(a.begin(),a.end(),cmp);
	tl=2;tmp[1]=a[0],tmp[2]=a[1];
	for (int i=2;i<a.size();i++)
	{
		while (tl>1 && vec(tmp[tl-1],tmp[tl])*vec(tmp[tl],a[i])) tl--;
		tmp[++tl]=a[i];
	}
	vector<Tri> ans;
	rep(i,1,tl) ans.pb(tmp[i]);
	return ans;
}
int main()
{
	scanf("%d",&n);if (n==3) {puts("6");return 0;}
	rep(i,1,n) scanf("%lf%lf",&x,&y),all.pb(Tri(x,y,i));
	con1=Convex(all);
	for (int i=0;i<con1.size();i++) vis[con1[i].id]=1;
	vector<int> tmp;
	for (int i=0;i<all.size();i++)
		if (!vis[all[i].id]) tmp.pb(all[i]);
	con2=Convex(tmp);
	ans=(LL)(n-con1.size())*con1.size();

}
