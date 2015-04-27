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
    int l,r,x;
    point() {}
    point(int _l,int _r,int _x) : l(_l),r(_r),x(_x) {}
} ;
vector<point> E[8000];
int n,m,vis[1200000],TIM,R[300000],L[300000];
int main()
{
	//freopen("B.in","r",stdin);
	read(n);read(m);
	int ty,t,l,r,x;
	rep(i,1,200000)
	{
		if (log2(i)==int(log2(i))) L[i]=i+int(log2(i));
		else L[i]=i+int(log2(i))+1;
		if (log2(i)==int(log2(i))) R[i]=i+int(log2(i))+1;
		else R[i]=i+int(log2(i))+1;
	}
	rep(i,1,m)
	{
		read(ty);
		if (ty==1)
		{
			read(t);read(l);read(r);read(x);
			E[t].pb(point(l,r,x));
		}
		else
		{
			read(t);read(l);r=l;int ans=0;
			++TIM;
			rep(j,t,n)
			{
				for (int k=0;k<E[j].size();k++)
				{
					int left=E[j][k].l,right=E[j][k].r;
					if (!(right<l || left>r))
					{
						if (vis[E[j][k].x]!=TIM) ans++;
						vis[E[j][k].x]=TIM;
					}
				}
				l=L[l];r=R[r];
			}
			printf("%d\n",ans);
		}
	}
}

