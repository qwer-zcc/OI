//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 05/07/2014                 |
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
#define INF 1e18
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
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
inline void read(int &x)
{
    char ch;
    while ((ch=getchar()) && !(ch>='0' && ch<='9'));x=ch-'0';
    while ((ch=getchar()) && (ch>='0' && ch<='9')) x=x*10+ch-'0';
}
struct point
{
    int x,y;
    point() {}
    point(int _x,int _y) : x(_x),y(_y) {}
} ;
#include <string>
const int N=520;
map<string,int>Hash;
int wn,cnt;
string dy[N];
string s1,s2,s3;
vector<pair<int,int> > E[N];
D P[N][N],dp[N][N][103];
vector<int> is[N][N];
void init()
{
	scanf("%d",&wn);
	rep(i,1,wn)
	{
		cin>>s1>>s2>>s3;
		int x,y,z;
		if (Hash[s1]) x=Hash[s1];
		else Hash[s1]=x=++cnt,dy[cnt]=s1;
		if (Hash[s2]) y=Hash[s2];
		else Hash[s2]=y=++cnt,dy[cnt]=s2;
		if (Hash[s3]) z=Hash[s3];
		else Hash[s3]=z=++cnt,dy[cnt]=s3;
		E[x].pb(mp(y,z));
		E[y].pb(mp(x,z));
	}
}
void work()
{
	M(P);
	int n;string s;D c;
	scanf("%d",&n);
	rep(i,1,n)
	{
		while (cin>>s)
		{
			if (s=="END") break;
			scanf("%lf",&c);
			int x;
			if (Hash[s]) x=Hash[s];
			else Hash[s]=++cnt,dy[cnt]=s;
			P[i][x]=c;
		}
	}
	D ans=-INF;int il=0;
	rep(i,1,n) rep(j,1,n) rep(k,1,cnt) dp[i][j][k]=-INF;
	rep(i,1,n) rep(j,1,n) is[i][j].clear();
	rep(Len,1,n)
	{
		rep(_,1,n-Len+1)
		{
			int l=_,r=_+Len-1;
			rep(j,l,r-1)
			{
				for (int i=0;i<is[l][j].size();i++)
				{
					int c1=is[l][j][i];
					for (int J=0;J<E[c1].size();J++)
					{
						int c2=E[c1][J].first;
						for (int k=0;k<is[j+1][r].size();k++){
						if (is[j+1][r][k]==c2)
							dp[l][r][E[c1][J].second]=max(dp[l][r][E[c1][J].second],dp[l][j][c1]+dp[j+1][r][c2]);
						}
					}
				}
			}
			if (l==r)
			{
				rep(i,1,cnt)
				if (P[l][i]>0) dp[l][r][i]=log(P[l][i]),is[l][r].pb(i);
			}
			else rep(k,1,cnt) if (dp[l][r][k]!=-INF) is[l][r].pb(k);
		}
	}
	rep(i,1,cnt)
	{
		if (dp[1][n][i]>ans) ans=dp[1][n][i],il=i;
	}
	if (!il) puts("GAMEOVER");
	else cout<<dy[il]<<endl;
}
int main()
{
	freopen("A.in","r",stdin);
	//ios::sync_with_stdio(0);
	init();
	int cs;
	scanf("%d",&cs);
	while (cs--) work();
}

