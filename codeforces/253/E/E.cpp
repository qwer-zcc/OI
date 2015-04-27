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
const int N=110000;
struct lj{int p,t,s;}P[N];
set<pair<int,int> > S;
priority_queue<pair<int,pair<int,int> > > Q;
int unk,n;
LL Ans[N],T;
map<int,bool> vis;
LL check(int mid)
{
	LL now=0;
	P[unk].p=mid;
	rep(i,1,n) S.insert(mp(P[i].t,i));
	while (1)
	{
		if (Q.size())
		{
			pair<int,pair<int,int> >a=Q.top();Q.pop();
			if (S.size() && S.begin()->first<=now+a.second.second-1)
			{
				int c=S.begin()->second;
				Q.push(mp(P[c].p,mp(c,P[c].s)));
				Q.push(mp(a.first,mp(a.second.first,a.second.second-(P[c].t-now))));
				S.erase(S.begin());
				now=P[c].t;
				continue;
			}
			Ans[a.second.first]=now+(LL)a.second.second;
			now=now+(LL)a.second.second;
			continue;
		}
		if (S.size())
		{
			int c=S.begin()->second;
			Q.push(mp(P[c].p,mp(c,P[c].s)));
			S.erase(S.begin());
			now=P[c].t;
		}
		else break;
	}
	return Ans[unk];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	//freopen("E.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n)
	{
		scanf("%d%d%d",&P[i].t,&P[i].s,&P[i].p);
		if (P[i].p!=-1) vis[P[i].p]=1;
		else unk=i;
	}
	scanf("%lld",&T);
	int l=1,r=1000000000,mid,ans;
	while (l<=r)
	{
		mid=l+r>>1;
		if (check(mid)>T) l=mid+1;else r=mid-1,ans=mid;
	}
	int an=-1;
	rep(i,0,n+1)
	if (ans+i>=1 && ans+i<=1000000000 && !vis[ans+i]) {an=ans+i;break;}
	if (an!=-1 && check(an)==T)
	{
		printf("%d\n",an);
		rep(j,1,n) printf("%lld ",Ans[j]);
		return 0;
	}
	ans=-1;
	drep(i,-1,-n-1)
	if (ans+i>=1 && ans+i<=1000000000 && !vis[ans+i]) {an=ans+i;break;}
	if (an!=-1 && check(an)==T)
	{
		printf("%d\n",an);
		rep(j,1,n) printf("%lld ",Ans[j]);
		return 0;
	}
}

