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
const int N=210000;
struct point
{
    int x,y;
    point() {}
    point(int _x,int _y) : x(_x),y(_y) {}
} P[N];
struct lj{int c,l,r;}t[15000000];
int n,cnt,a[20],Sx[N],Sy[N],hash[N],root[N],vis[N],val[N],hx[N],hy[N];
int cmp(point a,point b){return a.x<b.x||(a.x==b.x && a.y<b.y);}
int change(int p,int l,int u=1,int v=n)
{
	int k=++cnt;
	t[k]=t[p];t[k].c++;
	if (u==v) return k;
	int mid=u+v>>1;
	if (l<=mid) t[k].l=change(t[p].l,l,u,mid);
	else t[k].r=change(t[p].r,l,mid+1,v);
	return k;
}
int ask(int p,int q,int l,int r,int u=1,int v=n)
{
	if (l==u && r==v) return t[q].c-t[p].c;
	int mid=u+v>>1;
	if (r<=mid) return ask(t[p].l,t[q].l,l,r,u,mid);
	else if (l>mid) return ask(t[p].r,t[q].r,l,r,mid+1,v);
	else return ask(t[p].l,t[q].l,l,mid,u,mid)+ask(t[p].r,t[q].r,mid+1,r,mid+1,v);
}
#define a1 a[1]
#define a2 a[2]
#define a3 a[3]
#define a4 a[4]
#define a5 a[5]
#define a6 a[6]
#define a7 a[7]
#define a8 a[8]
#define a9 a[9]
void check()
{
	int S1=a1+a2+a3,S2=a1+a2+a3+a4+a5+a6;
	int T1=a1+a4+a7,T2=a1+a4+a7+a2+a5+a8;
	int x1=upper_bound(Sx+1,Sx+n+1,S1)-Sx-1,x2=upper_bound(Sx+1,Sx+n+1,S2)-Sx-1;
	int y1=upper_bound(Sy+1,Sy+n+1,T1)-Sy-1,y2=upper_bound(Sy+1,Sy+n+1,T2)-Sy-1;
	if (ask(root[0],root[x1],1,y1)!=a1) return;
	if (ask(root[0],root[x1],y1+1,y2)!=a2) return;
	if (ask(root[0],root[x1],y2+1,n)!=a3) return;
	if (ask(root[x1],root[x2],1,y1)!=a4) return;
	if (ask(root[x1],root[x2],y1+1,y2)!=a5) return;
	if (ask(root[x1],root[x2],y2+1,n)!=a6) return;
	if (ask(root[x2],root[n],1,y1)!=a7) return;
	if (ask(root[x2],root[n],y1+1,y2)!=a8) return;
	if (ask(root[x2],root[n],y2+1,n)!=a9) return;
	printf("%lf %lf\n",0.5+hx[x1],0.5+hx[x2]);
	printf("%lf %lf\n",0.5+hy[y1],0.5+hy[y2]);
	exit(0);
}
void dfs(int w)
{
	if (w>9) {check();return;}
	rep(i,1,9)
	if (!vis[i])
	{
		a[w]=val[i];vis[i]=1;
		dfs(w+1);
		vis[i]=0;
	}
}
int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d",&n);int nn;
	rep(i,1,n) scanf("%d%d",&P[i].x,&P[i].y);
	rep(i,1,n) hash[i]=P[i].x,hx[i]=hash[i];
	sort(hash+1,hash+n+1);
	nn=unique(hash+1,hash+n+1)-hash-1;
	rep(i,1,nn) hx[i]=hash[i];
	rep(i,1,n) P[i].x=lower_bound(hash+1,hash+nn+1,P[i].x)-hash;
	rep(i,1,n) hash[i]=P[i].y;
	sort(hash+1,hash+n+1);
	nn=unique(hash+1,hash+n+1)-hash-1;
	rep(i,1,nn) hy[i]=hash[i];
	rep(i,1,n) P[i].y=lower_bound(hash+1,hash+nn+1,P[i].y)-hash;
	sort(P+1,P+n+1,cmp);
	rep(i,1,n)
	{
		rep(j,P[i-1].x+1,P[i].x-1) root[j]=++cnt,t[root[j]]=t[root[j-1]];
		root[P[i].x]=change(root[P[i-1].x],P[i].y);
	}
	rep(j,P[n].x+1,n) root[j]=++cnt,t[root[j]]=t[root[j-1]];
	rep(i,1,n) Sx[P[i].x]++,Sy[P[i].y]++;
	rep(i,2,n) Sx[i]+=Sx[i-1],Sy[i]+=Sy[i-1];
	rep(i,1,9) scanf("%d",&val[i]);
	dfs(1);
	puts("-1");
}

