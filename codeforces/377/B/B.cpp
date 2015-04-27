//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 12/10/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF (~0U>>1)-3
#define LLINF ~0ULL>>1
#define LL long long
#define uLL unsigned long long
#define uint unsigned int
#define D double
#define LD long double
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define pb push_back
#define mp make_pair
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
template<class T> void read(T &x)
{
    char ch;
    while ((ch=getchar()) && !isdigit(ch));x=ch-'0';
    while ((ch=getchar()) && isdigit(ch)) x=x*10+ch-'0';
}
struct point
{
    int x,y;
    point() {}
    point(int _x,int _y) : x(_x),y(_y) {}
} ;
const int N=120000;
struct lj{int x,c,id;}P[N],Q[N];
int n,m,a[N],b[N],c[N],amax,bmax,cmin,Ans[N],s;
set<pair<int,int> >S;
inline int cmp(lj a,lj b){return a.x>b.x;}
int check(int mid)
{
	//gs++;
	int j=1,now=0,T=0;S.clear();
	int cost=0;
	rep(i,1,m)
	{
		while (j<=n && Q[j].x>=P[i].x) S.insert(mp(Q[j].c,Q[j].id)),j++;
		if (now>0) {now--;Ans[P[i].id]=T;continue;}
		if (!S.size()) return INF;
		cost+=S.begin()->first;
		if (cost>s) return cost;
		now=mid-1;
		T=S.begin()->second;
		Ans[P[i].id]=T;
		S.erase(S.begin());
	}
	return cost;
}
int main()
{
	//freopen("B.in","r",stdin);
	read(n);read(m);read(s);
	cmin=INF;
	rep(i,1,m) read(a[i]),amax=max(amax,a[i]);
	rep(i,1,n) read(b[i]),bmax=max(bmax,b[i]);
	rep(i,1,n)
	{
		read(c[i]);
		if (b[i]>=amax) cmin=min(cmin,c[i]);
	}
	rep(i,1,m) P[i].x=a[i],P[i].id=i;
	sort(P+1,P+m+1,cmp);
	rep(i,1,n) Q[i].x=b[i],Q[i].id=i,Q[i].c=c[i];
	sort(Q+1,Q+n+1,cmp);
	if (bmax<amax) {puts("NO");return 0;}
	if (cmin>s) {puts("NO");return 0;}
	int l=1,r=m,mid,ans;
	while(l<=r)
	{
		mid=l+r>>1;
		if (check(mid)<=s) ans=mid,r=mid-1;else l=mid+1;
	}
	check(ans);
	//printf("%d\n",gs);
	puts("YES");
	rep(i,1,m) printf("%d ",Ans[i]);
}

