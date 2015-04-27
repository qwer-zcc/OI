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
const int N=410000;
struct lj{int x,y;}P[N];
int delta,n,ty[N],vis[N],ans[N],T;
int cmp(lj a,lj b){return a.x<b.x || (a.x==b.x && a.y<b.y);}
void check()
{
	M(vis);
	rep(i,1,T) P[ans[i]].x+=P[ans[i]+1].x,P[ans[i]].y+=P[ans[i]+1].y,vis[ans[i]+1]=1;
	int p=0,q=0;
	rep(i,1,n)
	if (!vis[i])
	{
		if (P[i].x>P[i].y) p++;else q++;
	}
	printf("p = %d  q = %d\n",p,q);
	if (p>q) puts("ok"); else puts("fail");
}
void work(int TTL,int TTR)
{
	int sum=0,L=INF,R=0;
	rep(i,TTL,TTR)
	if (!ty[i]) sum++,L=min(L,i),R=max(R,i);
	else
	{
		if (sum==0)continue;
		if (sum&1)
		{
			if (ty[L-1]==1 && !vis[L-1])
			{
				if (P[L-1].x+P[L].x>P[L-1].y+P[L].y) for(int _=L-1;delta>0 && _+1<=R;_+=2) ans[delta]=_,delta--,vis[_]=vis[_+1]=1;
				else if (P[i-1].x+P[i].x>P[i-1].y+P[i].y) for(int _=L;delta>0 && _+1<=i;_+=2) ans[delta]=_,delta--,vis[_]=vis[_+1]=1;
				else for(int _=L;delta>0 && _+1<=R;_+=2) ans[delta]=_,delta--,vis[_]=vis[_+1]=1;
			}
			else
			{
				if (P[i-1].x+P[i].x>P[i-1].y+P[i].y) for (int _=L;delta>0 && _+1<=i;_+=2) ans[delta]=_,delta--,vis[_]=vis[_+1]=1;
				else for (int _=L;delta>0 && _+1<=R;_+=2) ans[delta]=_,delta--,vis[_]=vis[_+1]=1;
			}
		}
		else
		{
			if (ty[L-1]==1 && !vis[L-1])
			{
				if (P[L-1].x+P[L].x>P[L-1].y+P[L].y && P[i-1].x+P[i].x>P[i-1].y+P[i].y) for(int _=L-1;delta>0 && _+1<=i;_+=2) ans[delta]=_,delta--,vis[_]=vis[_+1]=1;
				else for(int _=L;delta>0 && _+1<=R;_+=2) ans[delta]=_,delta--,vis[_]=vis[_+1]=1;
			}
			else
			{
				for (int _=L;delta>0 && _+1<=R;_+=2) ans[delta]=_,delta--,vis[_]=vis[_+1]=1;
			}
		}
		sum=0;L=INF,R=0;
	}
}
int main()
{
	freopen("E.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n)
	{
		scanf("%d%d",&P[i].x,&P[i].y);
		if (P[i].x>P[i].y) delta--,ty[i]=1;
		else if (P[i].x==P[i].y) ty[i]=2;
		else delta++;
	}
	delta++;
	if (delta<=0) {puts("0");return 0;}
	T=delta;
	
	ty[n+1]=2;
	int L=1;
	rep(i,1,n+1)
	if (ty[i]==2)
	{
		if (L<=i-1) work(L,i-1);
		L=i+1;
	}
	else L=i;
	
	
	if (delta) {puts("-1");return 0;}
	printf("%d\n",T);
	rep(i,1,T) printf("%d %d\n",ans[i],ans[i]+1);
	check();
}

