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
const int N=320000;
struct lj
{
    int l,r,t;
    lj() {}
    lj(int _l,int _r,int _t) : l(_l),r(_r),t(_t) {}
} P[N],Ed[N];
vector<pair<int,int> > Add[N],Del[N];
set<pair<int,int> >S;
int n,m,q[N],hash[N],hl,El;
LL F[N],G[N];
int cmp1(const lj &a,const lj &b){return a.l<b.l;}
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d%d",&m,&n);
	rep(i,1,n) scanf("%d%d%d",&P[i].l,&P[i].r,&P[i].t);
	rep(i,1,m) scanf("%d",&q[i]);
	sort(P+1,P+n+1,cmp1);
	rep(i,1,n) hash[++hl]=P[i].l,hash[++hl]=P[i].r;
	sort(hash+1,hash+hl+1);
	hl=unique(hash+1,hash+hl+1)-hash-1;
	rep(i,1,n) Add[lower_bound(hash+1,hash+hl+1,P[i].l)-hash].pb(mp(P[i].t,i)),Del[lower_bound(hash+1,hash+hl+1,P[i].r)-hash].pb(mp(P[i].t,i));
	rep(i,1,hl)
	{
		if (S.size()) Ed[++El]=lj(hash[i-1],hash[i],S.begin()->first);
		for (int j=0;j<Add[i].size();j++) S.insert(Add[i][j]);
		for (int j=0;j<Del[i].size();j++) S.erase(Del[i][j]);
	}
	rep(i,1,El)
	{
		int x=lower_bound(q+1,q+m+1,Ed[i].t-Ed[i].l)-q,y;
		if (x<=m) F[x]+=(LL)Ed[i].r-Ed[i].l;
		x=lower_bound(q+1,q+m+1,Ed[i].t-Ed[i].r)-q;
		y=lower_bound(q+1,q+m+1,Ed[i].t-Ed[i].l)-q-1;
		if (x<=y)
		{
			F[x]+=(LL)Ed[i].r-Ed[i].t;
			F[y+1]-=(LL)Ed[i].r-Ed[i].t;
			G[x]++;
			G[y+1]--;	
		}
	}
	LL s1=0,s2=0;
	rep(i,1,m)
	{
		s1+=F[i];
		s2+=G[i];
		printf("%lld\n",s1+s2*(LL)q[i]);
	}
}

