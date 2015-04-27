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
const int N=1200000;
struct lj{int c,left,right,l,r;}t[N<<2];
int m,x,y,n;
char s[N];
void update(int w)
{
	t[w].c=t[w<<1].c+t[w<<1|1].c;
	t[w].c+=min(t[w<<1].right,t[w<<1|1].left);
	t[w].left=t[w<<1].left+(t[w<<1].right>=t[w<<1|1].left?0:t[w<<1|1].left-t[w<<1].right);
	t[w].right=t[w<<1|1].right+(t[w<<1|1].left>=t[w<<1].right?0:t[w<<1].right-t[w<<1|1].left);
}
void build(int w,int l,int r)
{
	t[w].l=l;t[w].r=r;
	if (l==r)
	{
		if (s[l]==')') t[w].left=1;
		else t[w].right=1;
		return;
	}
	int mid=l+r>>1;
	build(w<<1,l,mid);build(w<<1|1,mid+1,r);
	update(w);
}
lj ask(int w,int l,int r)
{
	if (t[w].l==l && t[w].r==r) return t[w];
	int mid=t[w].l+t[w].r>>1;
	if (r<=mid) return ask(w<<1,l,r);
	else if (l>mid) return ask(w<<1|1,l,r);
	else
	{
		lj x=ask(w<<1,l,mid),y=ask(w<<1|1,mid+1,r);
		lj z;
		z.c=x.c+y.c;
		z.c+=min(x.right,y.left);
		z.left=x.left+(x.right>=y.left?0:y.left-x.right);
		z.right=y.right+(y.left>=x.right?0:x.right-y.left);
		return z;
	}
}
int main()
{
	//freopen("C.in","r",stdin);
	scanf("%s",s+1);n=strlen(s+1);
	build(1,1,n);
	read(m);
	rep(i,1,m)
	{
		read(x);read(y);
		printf("%d\n",ask(1,x,y).c*2);
	}
}

