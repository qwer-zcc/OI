//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 14/08/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF ~0U>>1
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
const int N=210000,Mod=1000000007;
struct lj{int a[6],l,r,flag;}t[N<<3];
int Pow[N],val[N],In[6][N],n,m;
const int A[6][6]={
	{1,0,0,0,0,0},
	{1,1,0,0,0,0},
	{1,2,1,0,0,0},
	{1,3,3,1,0,0},
	{1,4,6,4,1,0},
	{1,5,10,10,5,1}};
int ADD(int a,int b){return (a+b)%Mod;}
int Chen(int a,int b){return int((LL)a*(LL)b%(LL)Mod);}
int Sum(int w,int ty,int dlt)
{
	if (!w) return 0;
	dlt--;
	Pow[0]=1;
	rep(i,1,5) Pow[i]=Chen(Pow[i-1],dlt);
	int ans=0;
	rep(i,0,ty) ans=ADD(ans,Chen(Chen(t[w].a[i],A[ty][i]),Pow[ty-i]));
	return ans;
}
void update(int w)
{
	int l=w<<1,r=l|1,dlt=t[r].l-t[l].l+1;
	t[w].a[0]=ADD(t[l].a[0],t[r].a[0]);
	t[w].a[1]=ADD(t[l].a[1],Sum(r,1,dlt));
	t[w].a[2]=ADD(t[l].a[2],Sum(r,2,dlt));
	t[w].a[3]=ADD(t[l].a[3],Sum(r,3,dlt));
	t[w].a[4]=ADD(t[l].a[4],Sum(r,4,dlt));
	t[w].a[5]=ADD(t[l].a[5],Sum(r,5,dlt));
}
void build(int w,int l,int r)
{
	t[w].l=l;t[w].r=r;t[w].flag=-1;
	if (l==r)
	{
		t[w].a[0]=t[w].a[1]=t[w].a[2]=t[w].a[3]=t[w].a[4]=t[w].a[5]=val[l];
		return;
	}
	int mid=l+r>>1;
	build(w<<1,l,mid);build(w<<1|1,mid+1,r);
	update(w);
}
void Add(int w,int c)
{
	rep(i,0,5) t[w].a[i]=Chen(c,In[i][t[w].r-t[w].l+1]);
	t[w].flag=c;
}
void push(int w)
{
	if (t[w].flag!=-1)
	{
		Add(w<<1,t[w].flag);
		Add(w<<1|1,t[w].flag);
		t[w].flag=-1;
	}
}
void change(int w,int l,int r,int c)
{
	push(w);
	if (t[w].l==l && t[w].r==r) {Add(w,c);return;}
	int mid=t[w].l+t[w].r>>1;
	if (r<=mid) change(w<<1,l,r,c);
	else if (l>mid) change(w<<1|1,l,r,c);
	else change(w<<1,l,mid,c),change(w<<1|1,mid+1,r,c);
	update(w);
}
int ask(int w,int l,int r,int c,int P)
{
	push(w);
	if (t[w].l==l && t[w].r==r) return Sum(w,c,P);
	int mid=t[w].l+t[w].r>>1;
	if (r<=mid) return ask(w<<1,l,r,c,P);
	else if (l>mid) return ask(w<<1|1,l,r,c,P);
	else return ADD(ask(w<<1,l,mid,c,P),ask(w<<1|1,mid+1,r,c,P+t[w<<1|1].l-l));
}
void Init()
{
	rep(i,1,n) Pow[i]=1;
	rep(i,0,5)
	{
		rep(j,1,n)
		{
			In[i][j]=ADD(In[i][j-1],Pow[j]);
			Pow[j]=int((LL)Pow[j]*j%(LL)Mod);
		}
	}
}
int main()
{
	//freopen("E.in","r",stdin);
	read(n);read(m);char s[3];int l,r,c;
	rep(i,1,n) read(val[i]);
	Init();build(1,1,n);
	rep(i,1,m)
	{
		scanf("%s",s);read(l);read(r);read(c);
		if (s[0]=='=') change(1,l,r,c);
		else printf("%d\n",ask(1,l,r,c,1));
	}
}

