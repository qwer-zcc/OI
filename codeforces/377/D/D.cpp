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
const int N=310000;
struct lj{int l,r,v;}P[N];
struct tree{int flag,c,wz;}t[N<<2];
vector<pair<int,int> > Add[N],Del[N];
int n,m;
void push(int w,int u,int v)
{
	int mid=u+v>>1;
	t[w<<1].flag+=t[w].flag;
	t[w<<1].c+=t[w].flag;
	if (!t[w<<1].wz) t[w<<1].wz=u;
	t[w<<1|1].flag+=t[w].flag;
	t[w<<1|1].c+=t[w].flag;
	if (!t[w<<1|1].wz) t[w<<1|1].wz=mid+1;
	t[w].flag=0;
}
void add(int w,int l,int r,int c,int u=1,int v=m)
{
	if (u==l && v==r)
	{
		t[w].flag+=c;
		t[w].c+=c;
		if (!t[w].wz) t[w].wz=u;
		return;
	}
	if (t[w].flag && u!=v) push(w,u,v);
	int mid=u+v>>1;
	if (r<=mid) add(w<<1,l,r,c,u,mid);
	else if (l>mid) add(w<<1|1,l,r,c,mid+1,v);
	else add(w<<1,l,mid,c,u,mid),add(w<<1|1,mid+1,r,c,mid+1,v);
	if (t[w<<1].c>t[w<<1|1].c) t[w].c=t[w<<1].c,t[w].wz=t[w<<1].wz;
	else t[w].c=t[w<<1|1].c,t[w].wz=t[w<<1|1].wz;
}
int Max,al,ar,len,ans[N];
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n)
	{
		scanf("%d%d%d",&P[i].l,&P[i].v,&P[i].r);
		Add[P[i].v].pb(mp(P[i].l,P[i].v)),Del[P[i].r].pb(mp(P[i].l,P[i].v));
		m=max(m,P[i].r);
	}
	rep(i,1,m)
	{
		for (int j=0;j<Add[i].size();j++) add(1,Add[i][j].first,Add[i][j].second,1);
		if (t[1].c>Max) Max=t[1].c,al=i,ar=t[1].wz;
		for (int j=0;j<Del[i].size();j++) add(1,Del[i][j].first,Del[i][j].second,-1);
	}
	swap(al,ar);
	rep(i,1,n)
	if (P[i].l<=al && al<=P[i].v && P[i].v<=ar && ar<=P[i].r) ans[++len]=i;
	printf("%d\n",len);
	rep(i,1,len) printf("%d ",ans[i]);
}

