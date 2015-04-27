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
const int N=120000;
int pos[N],wh[N],id,n;
set<int> one,two,three,Free;
inline void allocate(int x)
{
	printf("A %d\n",x);
	pos[id]=x;wh[x]=id;
}
inline void done()
{
	puts("D");
}
inline void move(int x,int y)
{
	printf("M %d %d\n",x,y);
	pos[wh[x]]=y;
	wh[y]=wh[x];
	wh[x]=0;
}
void Insert1()
{
	if (!one.size() && !two.size())
	{
		one.insert(1);
		allocate(1);
		return;
	}
	if (!one.size())
	{
		one.insert(*(--two.end())+2);
		allocate(*(--one.end()));
	}
	if (!two.size())
	{
		one.insert(*(--one.end())+1);
		allocate(*(--one.end()));
	}
	rep(_,1,2)
		if (Free.size() && one.size())
		{
			move(*(--one.end()),*(Free.begin()));
			one.insert(*(Free.begin()));
			one.erase((--one.end()));
			Free.erase(Free.begin());
		}
	if (Free.size())
	{
		one.insert(*(Free.begin()));
		allocate(*(Free.begin()));
		Free.erase(Free.begin());
	}
	else
	{
		one.insert(*(--one.end())+1);
		allocate(*(--one.end()));
	}
}
void Insert2()
{
	
}
void Insert3()
{
}
void Erase1()
{
}
void Erase2()
{
}
void Erase3()
{
}
int main()
{
	scanf("%d",&n);int x;
	while (scanf("%d",&x))
	{
		++id;
		if (x==0) break;
		if (x==1) Insert1();
		if (x==2) Insert2();
		if (x==3) Insert3();
		if (x==-1) Erase1();
		if (x==-2) Erase2();
		if (x==-3) Erase3();
		//fflush(stdout);
	}
}
