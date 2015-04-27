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
int flag[N<<2],sum[N<<2][28],n,m;
void upd(int w,int l,int r)
{
	rep(i,1,26)
	if (i!=flag[w]) sum[w][i]=0;
	sum[w][flag[w]]=r-l+1;
}
int ask(int w,int l,int r,int c,int u=1,int v=n)
{
	if (l==u && r==v) return sum[w][c];
	int mid=u+v>>1;
	if (flag[w])
	{
		flag[w<<1]=flag[w<<1|1]=flag[w];
		upd(w<<1,u,mid);
		upd(w<<1|1,mid+1,v);
		flag[w]=0;
	}
	if (r<=mid) return ask(w<<1,l,r,c,u,mid);
	else if (l>mid) return ask(w<<1|1,l,r,c,mid+1,v);
	else return ask(w<<1,l,mid,c,u,mid)+ask(w<<1|1,mid+1,r,c,mid+1,v);
}
void add(int w,int l,int r,int c,int u=1,int v=n)
{
	if (l==u && r==v) {flag[w]=c;upd(w,u,v);return;}
	int mid=u+v>>1;
	if (flag[w])
	{
		flag[w<<1]=flag[w<<1|1]=flag[w];
		upd(w<<1,u,mid);
		upd(w<<1|1,mid+1,v);
		flag[w]=0;
	}
	if (r<=mid) add(w<<1,l,r,c,u,mid);
	else if (l>mid) add(w<<1|1,l,r,c,mid+1,v);
	else add(w<<1,l,mid,c,u,mid),add(w<<1|1,mid+1,r,c,mid+1,v);
	rep(i,1,26) sum[w][i]=sum[w<<1][i]+sum[w<<1|1][i];
}
int num[N];
char s[N];
int main()
{
	//freopen("F.in","r",stdin);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);int l,r;
	scanf("%s",s);
	rep(i,0,n-1) add(1,i+1,i+1,s[i]-'a'+1);
	rep(i,1,m)
	{
		scanf("%d%d",&l,&r);
		rep(j,1,26) num[j]=ask(1,l,r,j);
		if ((r-l+1)&1)
		{
			int f=0;
			rep(j,1,26)
			if (num[j]&1)
			{
				if (f!=0) f=-1;
				else f=j;
			}
			if (f==-1) continue;
			add(1,l+(r-l+1)/2,l+(r-l+1)/2,f);
			num[f]--;
			rep(j,1,26)
			if (num[j])
			{
				add(1,l,l+num[j]/2-1,j);
				add(1,r-num[j]/2+1,r,j);
				l+=num[j]/2;r-=num[j]/2;
			}
		}
		else
		{
			int f=0;
			rep(j,1,26) if (num[j]&1) {f=1;break;}
			if (f) continue;
			rep(j,1,26)
			if (num[j])
			{
				add(1,l,l+num[j]/2-1,j);
				add(1,r-num[j]/2+1,r,j);
				l+=num[j]/2;r-=num[j]/2;
			}
		}
	}
	rep(i,1,n)
	{
		rep(j,1,26)
		if (ask(1,i,i,j)) {printf("%c",'a'+j-1);break;}
	}
}

