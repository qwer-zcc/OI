//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 30/10/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF ((~0U>>1)-3)
#define LLINF ((~0ULL>>1)-3)
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
const int N=210000;
int n,m,h,b[N],a[N],hash[N],ans;
struct lj{int l,r,c,flag;}t[N<<2];
void build(int w,int l,int r)
{
	t[w].l=l;t[w].r=r;
	if (l==r) {t[w].c=hash[l];return;}
	int mid=l+r>>1;
	build(w<<1,l,mid);build(w<<1|1,mid+1,r);
	t[w].c=min(t[w<<1].c,t[w<<1|1].c);
}
void push(int w)
{
	t[w<<1].c+=t[w].flag;
	t[w<<1|1].c+=t[w].flag;
	t[w<<1].flag+=t[w].flag;
	t[w<<1|1].flag+=t[w].flag;
	t[w].flag=0;
}
void add(int w,int l,int r,int c)
{
	if (l>r) return;
	if (t[w].l==l && t[w].r==r) {t[w].flag+=c;t[w].c+=c;return;}
	if (t[w].flag) push(w);
	int mid=t[w].l+t[w].r>>1;
	if (r<=mid) add(w<<1,l,r,c);
	else if (l>mid) add(w<<1|1,l,r,c);
	else add(w<<1,l,mid,c),add(w<<1|1,mid+1,r,c);
	t[w].c=min(t[w<<1].c,t[w<<1|1].c);
}
int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d%d%d",&n,&m,&h);
	rep(i,1,m) scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	rep(i,1,m) hash[lower_bound(b+1,b+m+1,b[i])-b]++;
	drep(i,m,1) hash[i]+=hash[i+1];
	build(1,1,m+1);
	rep(i,1,n) scanf("%d",&a[i]),a[i]=lower_bound(b+1,b+m+1,h-a[i])-b;
	rep(i,1,m-1) add(1,1,a[i],-1);
	rep(i,m,n)
	{
		add(1,1,a[i],-1);
		add(1,1,a[i-m],1);
		ans+=t[1].c>=0;
	}
	printf("%d\n",ans);
}

