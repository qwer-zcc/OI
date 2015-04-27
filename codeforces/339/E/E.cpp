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
const int N=2000;
stack<pair<int,int> >Ans;
int val[N],pos[N],n;
void change(int l,int r)
{
	rep(i,l,(l+r)>>1) swap(val[i],val[l+r-i]);
	rep(i,l,r) pos[val[i]]=i;
}
void sc()
{
	printf("%d\n",Ans.size());
	while (Ans.size())
	{
		printf("%d %d\n",Ans.top().first,Ans.top().second);
		Ans.pop();
	}
	exit(0);
}
int check()
{
	rep(i,1,n)
	if (val[i]!=i) return 0;
	return 1;
}
void dfs(int l,int r,int c)
{
	if (l>r && check()) {sc();return;}
	if (c==0) {if (check()) sc();return;}
	if (val[l]==l && val[r]==r) {dfs(l+1,r-1,c);return;}
	if (val[l]==l) {dfs(l+1,r,c);return;}
	if (val[r]==r) {dfs(l,r-1,c);return;}
	if (val[l]==r && val[r]==l)
	{
		change(l,r);
		Ans.push(mp(l,r));
		dfs(l+1,r-1,c-1);
		change(l,r);
		Ans.pop();
		return;
	}
	int T=pos[l];
	Ans.push(mp(l,pos[l]));
	change(l,pos[l]);
	dfs(l+1,r,c-1);
	change(l,T);
	Ans.pop();
	
	T=pos[r];
	Ans.push(mp(pos[r],r));
	change(pos[r],r);
	dfs(l,r-1,c-1);
	change(T,r);
	Ans.pop();
	
	T=min(pos[l],pos[r]);int S=max(pos[l],pos[r]);
	Ans.push(mp(T,S));
	change(T,S);
	dfs(l,r,c-1);
	change(T,S);
	Ans.pop();
}
int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&val[i]),pos[val[i]]=i;
	dfs(1,n,3);
}

