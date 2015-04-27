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
set<int> s1,s2;
set<int>::iterator It;
multiset<int,greater<int> > p,q;
multiset<int,greater<int> >::iterator It2;
int n,m,k,x;
char s[10];
int main()
{
	//freopen("A.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	s1.insert(0);s1.insert(n);
	s2.insert(0);s2.insert(m);
	p.insert(n);q.insert(m);
	rep(i,1,k)
	{
		scanf("%s%d",s,&x);
		if (s[0]=='V')
		{
			s1.insert(x);
			It=s1.find(x);
			It--;int l=*It;
			It++;It++;
			int r=*It;
			It2=p.find(r-l);
			p.erase(It2);
			p.insert(x-l);p.insert(r-x);
		}
		else
		{
			s2.insert(x);
			It=s2.find(x);
			It--;int l=*It;
			It++;It++;
			int r=*It;
			It2=q.find(r-l);
			q.erase(It2);
			q.insert(x-l);q.insert(r-x);
		}
		printf("%lld\n",(LL)(*p.begin())*(LL)(*q.begin()));
	}
}
