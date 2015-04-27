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
const int N=120000;
vector<int> E[N],F[N];
set<pair<int,int> >Set;
set<pair<int,int> , greater<pair<int,int> > >Big;
set<pair<int,int> >::iterator It;
set<int> S[N];
queue<int> Q[N];
int size[N],m_sub[N],n,cnt,to[N],An[N],num[N];
LL ans;
void Center(int x,int Fa)
{
	size[x]=1;
	for (int i=0;i<E[x].size();i++)
	if (E[x][i]!=Fa)
	{
		Center(E[x][i],x);
		size[x]+=size[E[x][i]];
		m_sub[x]=max(m_sub[x],size[E[x][i]]);
	}
	m_sub[x]=max(m_sub[x],n-size[x]);
}
void dfs(int w,int fa,int an)
{
	An[w]=an;if (an!=0) S[an].insert(w),Q[an].push(w);size[w]=1;
	for (int i=0;i<E[w].size();i++)
	if (E[w][i]!=fa)
	{
		if (an==0) dfs(E[w][i],w,++cnt);
		else dfs(E[w][i],w,an);
		size[w]+=size[E[w][i]];
		ans+=(LL)F[w][i]*size[E[w][i]]*2LL;
	}
}
void Link(int x,int y)
{
	int p=*S[y].begin();
	to[x]=*S[y].begin();
	Set.erase(mp(*S[y].begin(),y));
	Big.erase(mp(num[y],y));
	if (x!=p) Big.erase(mp(num[An[x]],An[x]));
	S[y].erase(S[y].begin());
	num[An[x]]--;num[y]--;
	if (S[y].size()) Set.insert(mp(*S[y].begin(),y));
	Big.insert(mp(num[y],y));
	if (x!=p) Big.insert(mp(num[An[x]],An[x]));
}
void work(int ct)
{
	//printf("ct = %d\n",ct);
	dfs(ct,0,0);
	S[0].insert(ct);
	rep(i,1,cnt) Set.insert(mp(*S[i].begin(),i));
	Set.insert(mp(ct,0));
	rep(i,0,cnt) Big.insert(mp(S[i].size()*2,i)),num[i]=S[i].size()*2;
	int Now=n*2+2;
	rep(i,1,n)
	{
		Now-=2;
		if (Set.size()==1)
		{
			Link(i,Set.begin()->second);
			continue;
		}
		if (Big.begin()->first*2==Now && Big.begin()->second!=An[i] && Big.begin()->second!=0)
		{
			Link(i,Big.begin()->second);
			continue;
		}
		It=Set.begin();
		if (i!=ct && It->second==An[i]) It++;
		Link(i,It->second);
	}
	printf("%lld\n",ans);
	rep(i,1,n) printf("%d ",to[i]);puts("");
}
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d",&n);int x,y,z;
	rep(i,1,n-1)
	{
		scanf("%d%d%d",&x,&y,&z);
		E[x].pb(y);E[y].pb(x);
		F[x].pb(z);F[y].pb(z);
	}
	Center(1,0);
	rep(i,1,n) if (m_sub[i]<=n/2) {work(i);break;}
}
