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
const int N=600000;
int val[N],n,nxt[N],pre[N],id[N];
LL ans;
inline int cmp(const int &a,const int &b) {return val[a]<val[b];}
int main()
{
	//freopen("C.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&val[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	rep(i,1,n-1) nxt[i]=i+1;
	rep(i,2,n) pre[i]=i-1;
	rep(_,1,n-2)
	{
		int x=id[_];
		if (!pre[x] || !nxt[x]) ans+=(LL)val[x];
		else ans+=(LL)min(val[pre[x]],val[nxt[x]]);
		nxt[pre[x]]=nxt[x];
		pre[nxt[x]]=pre[x];
	}
	printf("%lld\n",ans);
}
