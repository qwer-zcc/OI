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
struct lj{int id,c;}pos[100];
inline int cmp1(const lj &a,const lj &b){return a.id<b.id;}
inline int cmp2(const lj &a,const lj &b){return a.c>b.c;}
char s[120000];
map<int,int> cnt;
void work()
{
	cnt.clear();
	int all=0,n;LL ans=0;
	scanf("%s",s+1);n=strlen(s+1);
	rep(i,0,26) pos[i].id=i,pos[i].c=0;
	rep(i,1,n)
	{
		sort(pos,pos+26,cmp1);
		pos[s[i]-'a'].c=i;
		sort(pos,pos+26,cmp2);
		int cur=0;
		rep(j,0,25)
			if (pos[j].c)
			{
				cur+=1<<(pos[j].id);
				if (!cnt.count(cur)) all++;
				if (i-pos[j+1].c>cnt[cur])
				{
					ans+=(LL)(i-pos[j+1].c-cnt[cur])*(j+1);
					cnt[cur]=i-pos[j+1].c;
				}
			}
	}
	printf("%d %lld\n",all,ans);
}
int main()
{
	freopen("jingles.in","r",stdin);
	freopen("jingles.out","w",stdout);
	int cs;
	scanf("%d",&cs);
	while (cs--) work();
}
