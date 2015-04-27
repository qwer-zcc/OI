//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 02/11/2014                 |
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
const int N=120000;
struct lj{int l,r,x,wz;}T[N];
int ans[N],n,Len,m,colnum,col[N],w[N],Lcol[N],flag1[N],flag2[N],flag3[N],Acol[N],Bcol[N],failnum;
inline int g_k(int x){return x%Len==0?x/Len:x/Len+1;}
inline int cmp(const lj a,const lj b){return (a.x<b.x)||(a.x==b.x && a.r<b.r);}
#define debug if (T[p].l==8 && T[p].r==9) 
void query(int p)
{
	int lastfail=failnum;
	drep(x,min(T[p].x*Len,T[p].r),T[p].l)
	{
		col[w[x]]++;if (col[w[x]]>1) Lcol[w[x]]++;
		if (col[w[x]]==1) colnum++;
		if (col[w[x]]==1) flag1[w[x]]=1,Acol[w[x]]=x;
		else if (col[w[x]]==2) flag2[w[x]]=1,Bcol[w[x]]=Acol[w[x]]-x;
		else if (Bcol[w[x]]!=-1)
		{
			if (x!=Acol[w[x]]-Bcol[w[x]]*Lcol[w[x]]) flag3[w[x]]=Bcol[w[x]],Bcol[w[x]]=-1,failnum++;
		}
	}
	ans[T[p].wz]=colnum+(failnum<colnum?0:1);
	failnum=lastfail;
	rep(x,T[p].l,min(T[p].x*Len,T[p].r))
	{
		col[w[x]]--;Lcol[w[x]]=0;
		if (col[w[x]]==0) colnum--;
		if (flag1[w[x]]) Acol[w[x]]=0;
		else if (flag2[w[x]]) Bcol[w[x]]=0;
		else if (flag3[w[x]]) Bcol[w[x]]=flag3[w[x]];
		flag1[w[x]]=flag2[w[x]]=flag3[w[x]]=0;
	}
}
void add(int x)
{
	col[w[x]]++;
	if (col[w[x]]==1) colnum++;
	if (col[w[x]]==1) Acol[w[x]]=x;
	else if (col[w[x]]==2) Bcol[w[x]]=x-Acol[w[x]];
	else if (Bcol[w[x]]!=-1) if (x!=Acol[w[x]]+Bcol[w[x]]*(col[w[x]]-1)) Bcol[w[x]]=-1,failnum++;
}
int main()
{
	//freopen("D.in","r",stdin);
	read(n);
	rep(i,1,n) read(w[i]);
	read(m);
	Len=int(sqrt(n))*2;
	rep(i,1,m) read(T[i].l),read(T[i].r),T[i].wz=i,T[i].x=g_k(T[i].l);
	sort(T+1,T+m+1,cmp);
	rep(i,1,m)
	{
		rep(k,1,n) Acol[k]=Bcol[k]=col[k]=0;colnum=0;failnum=0;
		int j=i+1,now=T[i].x*Len+1;
		rep(k,now,T[i].r) add(k);
		query(i);
		now=max(now,T[i].r+1);
		while (T[j].x==T[i].x)
		{
			rep(k,now,T[j].r) add(k);
			query(j);
			now=max(now,T[j].r+1);j++;
		}
		i=j-1;
	}
	rep(i,1,m) printf("%d\n",ans[i]);
}

