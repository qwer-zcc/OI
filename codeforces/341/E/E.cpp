//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 30/10/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF ((~0U>>1)-3)
#define LLINF ((~0ULL>>1)-3)
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
int a[5],cnt,n,val[2000];
vector<pair<int,int> > ans;
set<int> S;
int cmp(int a,int b){return val[a]<val[b];}
void move(int x,int y){ans.pb(mp(y,x));val[x]-=val[y];val[y]<<=1;}
void solve()
{
	if (a[1]==a[2]) {move(a[2],a[1]);return;}
	if (a[2]==a[3]) {move(a[3],a[2]);return;}
	int x=val[a[2]]/val[a[1]];
	for (int i=1;i<=x;i<<=1) if (x&i) move(a[2],a[1]);else move(a[3],a[1]);
}
int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&val[i]);
	rep(i,1,n) if (val[i]) S.insert(i);
	while (1)
	{
		if (S.size()<2) {puts("-1");return 0;}
		if (S.size()<3) break;
		a[1]=*S.begin();S.erase(S.begin());
		a[2]=*S.begin();S.erase(S.begin());
		a[3]=*S.begin();S.erase(S.begin());
		sort(a+1,a+4,cmp);
		solve();
		if (val[a[1]]>0) S.insert(a[1]);
		if (val[a[2]]>0) S.insert(a[2]);
		if (val[a[3]]>0) S.insert(a[3]);
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
}

