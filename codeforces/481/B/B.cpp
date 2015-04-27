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
#define pb push
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
set<pair<int,int>,greater<pair<int,int> > > S;
set<pair<int,int>,greater<pair<int,int> > >::iterator It;
queue<int> Q[2000];
int n,k,x,col[2000],TT[2000];
pair<int,int> ans[2000];
int pd()
{
	rep(i,1,n) while (Q[i].size()) Q[i].pop();
	rep(i,1,n) ans[i]=mp(0,0);
	S.clear();
	rep(i,1,n) col[i]=0;
	rep(i,1,n)
	{
		if (TT[i]==-1) Q[0].pb(i);
		else col[TT[i]]++,Q[TT[i]].pb(i);
	}
	rep(i,1,n)if (col[i])  S.insert(mp(col[i],i));
	while (S.size()>=2)
	{
		pair<int,int> a=*S.begin();S.erase(S.begin());
		if (a.first>=n/k)
		{
			rep(i,1,n/k)
			{
				int c=Q[a.second].front();Q[a.second].pop();
				ans[c]=mp(a.second,a.second);
			}
			if (a.first!=n/k) S.insert(mp(Q[a.second].size(),a.second));
			continue;
		}
		else
		{
			pair<int,int> b=*S.begin();S.erase(S.begin());
			if (a.first+b.first>=n/k)
			{
				rep(i,1,a.first)
				{
					int c=Q[a.second].front();Q[a.second].pop();
					ans[c]=mp(a.second,b.second);
				}
				rep(i,1,n/k-a.first)
				{
					int c=Q[b.second].front();Q[b.second].pop();
					ans[c]=mp(b.second,a.second);
				}
				if (a.first+b.first!=n/k) S.insert(mp(Q[b.second].size(),b.second));
			}
			else
			{
				if (a.first+b.first+Q[0].size()>=n/k)
				{
					rep(i,1,a.first)
					{
						int c=Q[a.second].front();Q[a.second].pop();
						ans[c]=mp(a.second,b.second);
					}
					rep(i,1,b.first)
					{
						int c=Q[b.second].front();Q[b.second].pop();
						ans[c]=mp(b.second,a.second);
					}
					rep(i,1,n/k-a.first-b.first)
					{
						int c=Q[0].front();Q[0].pop();
						ans[c]=mp(a.second,b.second);
					}
				}
				else return 0;
			}
		}
	}
	if (S.size())
	{
		pair<int,int> a=*S.begin();S.erase(S.begin());
		rep(i,1,a.first)
		{
			int c=Q[a.second].front();Q[a.second].pop();
			ans[c]=mp(a.second,a.second);
		}
		while (Q[0].size())
		{
			int c=Q[0].front();Q[0].pop();
			ans[c]=mp(a.second,a.second);
		}
	}
	while (Q[0].size())
	{
		int c=Q[0].front();Q[0].pop();
		ans[c]=mp(1,1);
	}
	puts("Yes");
	rep(i,1,n) printf("%d %d\n",ans[i].first,ans[i].second);
	exit(0);
	return 1;
}
int main()
{
	//freopen("B.in","r",stdin);
	scanf("%d%d",&n,&k);
	rep(i,1,n)
	{
		scanf("%d",&TT[i]);
		if (TT[i]==-1) Q[0].pb(i);
		else col[TT[i]]++,Q[TT[i]].pb(i);
	}
	rep(i,1,n)if (col[i])  S.insert(mp(col[i],i));
	while (S.size()>=2)
	{
		pair<int,int> a=*S.begin();S.erase(S.begin());
		if (a.first>=n/k)
		{
			rep(i,1,n/k)
			{
				int c=Q[a.second].front();Q[a.second].pop();
				ans[c]=mp(a.second,a.second);
			}
			if (a.first!=n/k) S.insert(mp(Q[a.second].size(),a.second));
			continue;
		}
		else
		{
			It=S.end();It--;
			pair<int,int> b=*It;S.erase(It);
			if (a.first+b.first>=n/k)
			{
				rep(i,1,a.first)
				{
					int c=Q[a.second].front();Q[a.second].pop();
					ans[c]=mp(a.second,b.second);
				}
				rep(i,1,n/k-a.first)
				{
					int c=Q[b.second].front();Q[b.second].pop();
					ans[c]=mp(b.second,a.second);
				}
				if (a.first+b.first!=n/k) S.insert(mp(Q[b.second].size(),b.second));
			}
			else
			{
				if (a.first+b.first+Q[0].size()>=n/k)
				{
					rep(i,1,a.first)
					{
						int c=Q[a.second].front();Q[a.second].pop();
						ans[c]=mp(a.second,b.second);
					}
					rep(i,1,b.first)
					{
						int c=Q[b.second].front();Q[b.second].pop();
						ans[c]=mp(b.second,a.second);
					}
					rep(i,1,n/k-a.first-b.first)
					{
						int c=Q[0].front();Q[0].pop();
						ans[c]=mp(a.second,b.second);
					}
				}
				else {if (!pd()) puts("No");return 0;}
			}
		}
	}
	if (S.size())
	{
		pair<int,int> a=*S.begin();S.erase(S.begin());
		rep(i,1,a.first)
		{
			int c=Q[a.second].front();Q[a.second].pop();
			ans[c]=mp(a.second,a.second);
		}
		while (Q[0].size())
		{
			int c=Q[0].front();Q[0].pop();
			ans[c]=mp(a.second,a.second);
		}
	}
	while (Q[0].size())
	{
		int c=Q[0].front();Q[0].pop();
		ans[c]=mp(1,1);
	}
	puts("Yes");
	rep(i,1,n) printf("%d %d\n",ans[i].first,ans[i].second);
}

