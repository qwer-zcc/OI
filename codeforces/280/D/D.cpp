//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 22/06/2014                 |
//+-------------------------------------+
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#define INF 1000000000
#define LL long long
#define uLL unsigned long long
#define uint unsigned int
#define D double
#define LD long double
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define dep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define Chen(a,b,c) int((LL)(a)*(LL)(b)%(LL)(c))
#define pb push_back
#define mp make_pair
#define ins insert
#define ps push
#define Pi M_PI
#define F(a) a=-a;
using namespace std;
template<class T> inline T abs(T &a) {return a>0?a:-a;}
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
template <class T> inline void read(T &n)
{
    char c;
    int flag = 1;
    for (c = getchar(); !(c >= '0' && c <= '9') && c != '-'; c = getchar()); 
	if (c == '-') flag = -1, c = '0';
	n = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
    n *= flag;
}
const int N=200010;
struct lj
{
	int sum,c,maxsum,minsum,lmaxs,lmins,rmaxs,rmins,lmaxwz,lminwz,rmaxwz,rminwz,l,r,flag;
	pair<pair<int,int>,int> maxwz,minwz;
}t[N<<2];
int val[N],n,m;
inline void NEGATE(int w)
{
	F(t[w].sum);F(t[w].c);
	swap(t[w].maxsum,t[w].minsum);
	F(t[w].maxsum);
	F(t[w].minsum);
	swap(t[w].lmaxs,t[w].lmins);
	F(t[w].lmaxs);
	F(t[w].lmins);
	swap(t[w].rmaxs,t[w].rmins);
	F(t[w].rmaxs);
	F(t[w].rmins);
	swap(t[w].lmaxwz,t[w].lminwz);
	swap(t[w].rmaxwz,t[w].rminwz);
	swap(t[w].maxwz,t[w].minwz);
	F(t[w].maxwz.second);
	F(t[w].minwz.second);
}


inline void update(int w)
{
	int l=w<<1,r=w<<1|1;
	// sum
	t[w].sum=t[w<<1].sum+t[w<<1|1].sum+t[w].c;
	
	// maxsum maxwz
	
	if (t[l].rmaxs+t[r].lmaxs>max(t[l].maxwz.second,t[r].maxwz.second))
	{
		t[w].maxsum=t[l].rmaxs+t[r].lmaxs;
		t[w].maxwz=mp(mp(t[l].rmaxwz,t[r].lmaxwz),t[w].maxsum);
	}
	else
	{
		if (t[l].maxwz.second>t[r].maxwz.second) t[w].maxsum=t[l].maxwz.second,t[w].maxwz=t[l].maxwz;
		else t[w].maxsum=t[r].maxwz.second,t[w].maxwz=t[r].maxwz;
	}
	
	// minsum minwz
	if (t[l].rmins+t[r].lmins<min(t[l].minwz.second,t[r].minwz.second))
	{
		t[w].minsum=t[l].rmins+t[r].lmins;
		t[w].minwz=mp(mp(t[l].rminwz,t[r].lminwz),t[w].minsum);
	}
	else
	{
		if (t[l].minwz.second<t[r].minwz.second) t[w].minsum=t[l].minwz.second,t[w].minwz=t[l].minwz;
		else t[w].minsum=t[r].minwz.second,t[w].minwz=t[r].minwz;
	}

	// lmaxs lmaxwz
	if (t[l].sum+t[r].lmaxs>t[l].lmaxs)
	{
		t[w].lmaxs=t[l].sum+t[r].lmaxs;
		t[w].lmaxwz=t[r].lmaxwz;
	}
	else
	{
		t[w].lmaxs=t[l].lmaxs;
		t[w].lmaxwz=t[l].lmaxwz;
	}
	
	// lmins lminwz
	if (t[l].sum+t[r].lmins<t[l].lmins)
	{
		t[w].lmins=t[l].sum+t[r].lmins;
		t[w].lminwz=t[r].lminwz;
	}
	else
	{
		t[w].lmins=t[l].lmins;
		t[w].lminwz=t[l].lminwz;
	}
	
	// rmaxs rmaxwz
	if (t[r].sum+t[l].rmaxs>t[r].rmaxs)
	{
		t[w].rmaxs=t[r].sum+t[l].rmaxs;
		t[w].rmaxwz=t[l].rmaxwz;
	}
	else
	{
		t[w].rmaxs=t[r].rmaxs;
		t[w].rmaxwz=t[r].rmaxwz;
	}
	
	// rmins rminwz
	if (t[r].sum+t[l].rmins<t[r].rmins)
	{
		t[w].rmins=t[r].sum+t[l].rmins;
		t[w].rminwz=t[l].rminwz;
	}
	else
	{
		t[w].rmins=t[r].rmins;
		t[w].rminwz=t[r].rminwz;
	}
}
void build(int w,int l,int r)
{
	t[w].l=l;t[w].r=r;
	if (l==r)
	{
		t[w].sum=t[w].c=val[l];
		t[w].maxsum=t[w].lmaxs=t[w].rmaxs=t[w].minsum=t[w].lmins=t[w].rmins=val[l];
		t[w].lmaxwz=t[w].rmaxwz=t[w].lminwz=t[w].rminwz=l;
		t[w].maxwz=t[w].minwz=mp(mp(l,r),val[l]);
		t[w].flag=0;
		return;
	}
	int mid=l+r>>1;
	build(w<<1,l,mid);build(w<<1|1,mid+1,r);
	update(w);
}
inline void push(int w)
{
	if (t[w].flag)
	{
		NEGATE(w<<1);t[w<<1].flag^=1;
		NEGATE(w<<1|1);t[w<<1|1].flag^=1;
		t[w].flag=0;
	}
}
void Negate(int w,int l,int r)
{
	if (t[w].l==l && t[w].r==r)
	{
		t[w].flag^=1;
		NEGATE(w);
		return;
	}
	push(w);
	int mid=t[w].l+t[w].r>>1;
	if (r<=mid) Negate(w<<1,l,r);
	else if (l>mid) Negate(w<<1|1,l,r);
	else Negate(w<<1,l,mid),Negate(w<<1|1,mid+1,r);
	update(w);
}
pair<int,int> ask_rmax(int w,int l,int r)
{
	//printf("    %d %d   %d %d\n",t[w].l,t[w].r,l,r);
	push(w);
	if (t[w].l==l && t[w].r==r) return mp(t[w].rmaxs,t[w].rmaxwz);
	int mid=t[w].l+t[w].r>>1;
	if (l>mid) return ask_rmax(w<<1|1,l,r);
	else
	{
		pair<int,int> p=ask_rmax(w<<1,l,mid),q=ask_rmax(w<<1|1,mid+1,r);
		if (p.first+t[w<<1|1].sum>q.first) return mp(p.first+t[w<<1|1].sum,p.second);
		else return q;
	}
}
pair<int,int> ask_lmax(int w,int l,int r)
{
	push(w);
	if (t[w].l==l && t[w].r==r) return mp(t[w].lmaxs,t[w].lmaxwz);
	int mid=t[w].l+t[w].r>>1;
	if (r<=mid) return ask_lmax(w<<1,l,r);
	else
	{
		pair<int,int> p=ask_lmax(w<<1,l,mid),q=ask_lmax(w<<1|1,mid+1,r);
		if (q.first+t[w<<1].sum>p.first) return mp(q.first+t[w<<1].sum,q.second);
		else return p;
	}
}
pair<pair<int,int>,int> ask(int w,int l,int r)
{
	//printf("%d %d     %d %d\n",t[w].l,t[w].r,l,r);
	if (l==t[w].l && r==t[w].r) return t[w].maxwz;
	push(w);
	int mid=t[w].l+t[w].r>>1;
	if (r<=mid) return ask(w<<1,l,r);
	else if (l>mid) return ask(w<<1|1,l,r);
	else
	{
		int bc;
		pair<pair<int,int>,int> p=ask(w<<1,l,mid),q=ask(w<<1|1,mid+1,r),s;
		pair<int,int> Rmax=ask_rmax(w<<1,l,mid),Lmax=ask_lmax(w<<1|1,mid+1,r);
		//printf("%d %d %d\n",l,mid,r);
		//printf("%d %d\n",Rmax.first,Lmax.first);
		if ((bc=Rmax.first+Lmax.first)>max(p.second,q.second))
			return mp( mp(Rmax.second,Lmax.second),bc);
		if (p.second>q.second) return p;
		else return q;
	}
}
void change(int w,int l,int k)
{
	if (t[w].l==t[w].r)
	{
		t[w].c=t[w].sum=k;
		t[w].maxsum=t[w].lmaxs=t[w].rmaxs=t[w].minsum=t[w].lmins=t[w].rmins=k;
		t[w].lmaxwz=t[w].rmaxwz=t[w].lminwz=t[w].rminwz=t[w].l;
		t[w].maxwz=t[w].minwz=mp(mp(t[w].l,t[w].r),k);
		t[w].flag=0;
		return;
	}
	push(w);
	int mid=t[w].l+t[w].r>>1;
	if (l<=mid) change(w<<1,l,k);
	else change(w<<1|1,l,k);
	update(w);
}
pair<pair<int,int>,int> DL[100];
void ASK(int l,int r,int k)
{
	int ans=0,dl=0;
	rep(i,1,k)
	{
		pair<pair<int,int>,int> wz=ask(1,l,r);
		if (wz.second<0) break;
		Negate(1,wz.first.first,wz.first.second);
		ans+=wz.second;
		//printf("%d %d\n",wz.first.first,wz.first.second);
		
		//break;
		
		DL[++dl]=wz;
	}
	dep(i,dl,1) Negate(1,DL[i].first.first,DL[i].first.second);
	printf("%d\n",ans);
	//exit(0);
}
int main()
{
	read(n);
	rep(i,1,n) read(val[i]);
	build(1,1,n);
	read(m);int ty,l,r,k;
	rep(i,1,m)
	{
		read(ty);
		if (ty==1)
		{
			read(l);read(r);read(k);
			ASK(l,r,k);
		}
		else
		{
			read(l);read(k);
			change(1,l,k);
		}
	}
}
