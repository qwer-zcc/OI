#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
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
const int N=200010;
bitset<N> bit[20],now;
char s1[N],s2[N];
int n,m,k,pre[N][4],ans,can[N],a[N],b[N];
int get(char x) {return x=='A'?0:(x=='G'?1:(x=='C'?2:3));}
int main()
{
	freopen("1.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",s1+1,s2+1);
	rep(i,0,(1<<4)-1) bit[i][0]=1;
	rep(i,1,n) a[i]=get(s1[i]);
	rep(i,1,m) b[i]=get(s2[i]);
	rep(i,1,m) rep(j,0,(1<<4)-1) if (j&(1<<b[i])) bit[j][i]=1;
	rep(i,1,n) {rep(j,0,3) pre[i][j]=pre[i-1][j];pre[i][a[i]]++;}
	rep(i,1,n) rep(j,0,3) if (pre[max(0,i-k-1)][j]<pre[min(n,i+k)][j]) can[i]|=1<<j;
	now[0]=1;
	rep(i,1,n)
	{
		now<<=1;now[0]=1;
		now&=bit[can[i]];
		ans+=now[m];
	}
	printf("%d\n",ans);
}
