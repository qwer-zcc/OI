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
const int N=310000;
int pre[N],nl[N],nr[N],val[N],pos[N],n;
LL solve(int l,int r)
{
	if (l>r) return 0;
	if (l==r) return 1;
	int mid=(l+r)>>1;
	LL ans=solve(l,mid-1)+solve(mid+1,r);
	int vl=val[mid],vr=val[mid];
	rep(i,l,r) nl[i]=nr[i]=0;
	nl[mid]=mid;nr[mid]=mid;
	drep(i,mid-1,l)
	{
		nl[i]=nl[i+1];nr[i]=nr[i+1];
		while (vl-1>=val[i] && vl>=val[mid]-r+l-1) vl--,nl[i]=min(nl[i],pos[vl]),nr[i]=max(nr[i],pos[vl]);
		while (vr+1<=val[i] && vr<=val[mid]+r-l+1) vr++,nl[i]=min(nl[i],pos[vr]),nr[i]=max(nr[i],pos[vr]);
	}
	vl=val[mid];vr=val[mid];
	rep(i,mid+1,r)
	{
		nl[i]=nl[i-1];nr[i]=nr[i-1];
		while (vl-1>=val[i] && vl>=val[mid]-r+l-1) vl--,nl[i]=min(nl[i],pos[vl]),nr[i]=max(nr[i],pos[vl]);
		while (vr+1<=val[i] && vr<=val[mid]+r-l+1) vr++,nl[i]=min(nl[i],pos[vr]),nr[i]=max(nr[i],pos[vr]);
	}
	rep(i,l,r) pre[i]=0;
	rep(i,mid,r) pre[i]=pre[i-1]+(nr[i]==i);
	int R=mid;
	drep(i,mid,l)
	{
		if (nl[i]!=i) continue;
		while (R<=r && nl[R]>=i) R++;R--;
		if (R>=nr[i]) ans+=(LL)(pre[R]-pre[nr[i]-1]);
	}
	//printf("%d %d %lld\n",l,r,ans);
	return ans;
}
int main()
{
	freopen("F.in","r",stdin);
	scanf("%d",&n);int x,y;
	rep(i,1,n) scanf("%d%d",&x,&y),val[x]=y,pos[y]=x;
	printf("%lld\n",solve(1,n));
}
