#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define INF int(1e8)
#define LL long long
#define D double
#define LD long double
#define pb push_back
#define mp make_pair
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
const int N=300;
int n,bit[N];
char s[10];
pair<int,int> P[N];
inline int Col(char x)
{
	if (x=='R') return 0;
	else if (x=='G') return 1;
	else if (x=='B') return 2;
	else if (x=='Y') return 3;
	else return 4;
}
inline int Num(char x) {return x-'1';}
inline int check(int x,int y)
{
	vector<int> v;v.clear();
	rep(i,0,4)
	{
		if (x&(1<<i)) v.pb(i);
		if (y&(1<<i)) v.pb(i+5);
	}
	int p=0;
	rep(i,1,n)
	{
		bit[i]=0;
		for (int j=0;j<v.size();j++)
		{
			if (v[j]<5 && (P[i].first==v[j])) bit[i]|=1<<v[j];
			if (v[j]>4 && (P[i].second==v[j]-5)) bit[i]|=1<<v[j];
		}
	}
	sort(bit+1,bit+n+1);
	rep(i,1,n-1) if (bit[i]==bit[i+1]) return 0;
	return 1;
}
int main()
{
	//freopen("A.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n)
	{
		scanf("%s",s);
		P[i]=mp(Col(s[0]),Num(s[1]));
	}
	sort(P+1,P+n+1);
	n=unique(P+1,P+n+1)-P-1;
		int ans=INF,cnt=0;
	rep(i,0,(1<<5)-1) rep(j,0,(1<<5)-1)
	if (check(i,j))
	{
		cnt=0;
		rep(k,0,4)
		{
			if (i&(1<<k)) cnt++;
			if (j&(1<<k)) cnt++;
		}
		ans=min(ans,cnt);
	}
	printf("%d\n",ans);
}
