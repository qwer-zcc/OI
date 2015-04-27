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
#include <stack>
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
string s;
int l;	
vector<int> Pair(vector<int> a,vector<int> b)
{
	vector<int> ans;
	rep(i,0,6) ans.pb(0);
	rep(i,0,6) rep(j,0,6-i) ans[i+j]+=a[i]*b[j];
	return ans;
}
vector<int> List(vector<int> a)
{
	vector<int> ans;
	rep(i,0,6) ans.pb(0);ans[0]=1;
	rep(i,1,6) rep(j,1,i) ans[i]+=ans[i-j]*a[j];
	return ans;
}
vector<int> solve()
{
	if (s[l]=='B')
	{
		vector<int> ans;
		rep(i,0,6) ans.pb(0);
		ans[1]=1;
		return ans;
	}
	else if (s[l]=='L')
	{
		l+=2;
		vector<int> ans=List(solve());
		l++;
		return ans;
	}
	else if (s[l]=='P')
	{
		l+=2;vector<int> x=solve();
		l+=2;vector<int> y=solve();
		l++;
		return Pair(x,y);
	}
	return vector<int>();
}
const int limit[7]={1,1,2,5,14,42,140};
int al,vis[2][2][3][6][15][43][141];
pair<vector<int>,string> all[310000];
vector<int> newvec()
{
	vector<int> a;
	rep(i,0,6) a.pb(0);
	return a;
}
void add(vector<int> a,string s)
{
	rep(i,0,6) if (a[i]>limit[i]) return;
	if (vis[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]]) return;
	vis[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]]=++al;
	all[al]=mp(a,s);
}
string table[21]={"P(P(L(P(B,L(L(B)))),L(P(P(B,P(B,B)),P(L(B),P(B,B))))),L(P(P(P(B,L(B)),P(L(B),P(B,L(B)))),P(P(B,L(B)),P(L(B),P(B,L(B)))))))",
"P(L(P(P(B,L(L(B))),L(P(P(B,B),P(B,B))))),L(P(P(P(B,L(B)),P(L(B),P(B,L(B)))),P(P(B,L(B)),P(L(B),P(B,L(B)))))))",
"P(P(L(L(B)),L(P(P(B,B),P(B,P(B,B))))),L(P(P(L(L(B)),P(B,L(L(B)))),P(P(B,L(L(B))),P(L(B),P(B,L(B)))))))",
"P(L(P(P(B,B),P(B,P(B,B)))),L(P(B,L(P(B,L(L(B)))))))",
"P(L(P(P(B,P(B,B)),P(L(B),P(B,B)))),L(P(B,L(P(B,L(L(B)))))))",
"L(P(L(P(B,L(L(B)))),P(B,L(P(P(B,B),P(B,B))))))",
"P(L(P(P(P(B,B),P(B,L(B))),P(P(B,L(B)),P(B,L(B))))),L(P(B,L(P(B,L(L(B)))))))",
"P(L(P(P(P(B,L(B)),P(B,L(B))),P(P(B,L(B)),P(L(B),P(B,B))))),L(P(B,L(P(B,L(L(B)))))))",
"P(L(P(B,L(P(B,L(L(B)))))),L(P(P(P(B,L(B)),P(L(B),P(B,B))),P(P(B,L(B)),P(L(B),P(B,L(B)))))))",
"P(L(P(B,L(P(B,L(L(B)))))),L(P(P(P(B,L(B)),P(L(B),P(B,L(B)))),P(P(L(B),P(B,B)),P(L(B),P(B,L(B)))))))",
"P(P(P(L(B),L(P(B,P(B,B)))),L(L(P(P(B,B),L(L(B)))))),L(P(P(L(L(B)),P(B,L(L(B)))),P(P(B,L(L(B))),P(L(B),P(B,L(B)))))))",
"P(P(P(L(P(B,P(B,B))),L(P(L(B),P(B,B)))),P(L(B),L(P(P(B,B),P(B,B))))),L(P(P(L(L(B)),P(B,L(L(B)))),P(P(L(B),P(B,L(B))),P(L(B),P(B,L(B)))))))",
"P(L(P(P(L(L(B)),P(B,L(L(B)))),P(P(L(B),P(B,L(B))),P(L(B),P(B,L(B)))))),P(L(L(P(P(B,B),P(B,L(B))))),P(P(L(B),L(P(B,B))),L(P(P(B,B),P(B,L(B)))))))",
"P(P(L(P(B,L(P(B,B)))),P(L(L(P(B,B))),L(P(B,P(B,B))))),L(P(P(L(L(B)),P(B,L(L(B)))),P(P(L(B),P(B,L(B))),P(L(B),P(B,L(B)))))))",
"P(P(P(L(B),L(P(B,P(B,B)))),L(P(L(P(B,B)),P(P(B,B),L(L(B)))))),L(P(P(L(L(B)),P(B,L(L(B)))),P(P(B,L(L(B))),P(L(L(B)),P(B,L(B)))))))",
"P(L(P(P(L(L(B)),P(B,L(L(B)))),P(P(L(B),P(B,L(B))),P(L(B),P(B,L(B)))))),P(L(P(L(L(B)),P(B,P(B,B)))),P(L(P(B,P(B,B))),P(L(B),L(L(P(B,B)))))))",
"P(P(P(L(P(B,P(B,B))),L(P(P(B,B),P(B,B)))),P(P(L(B),L(P(B,B))),L(P(P(B,B),P(B,L(B)))))),L(P(P(L(P(B,B)),P(L(L(B)),P(B,L(B)))),P(P(L(B),P(B,L(B))),P(L(L(B)),P(B,L(B)))))))",
"P(P(L(L(P(P(B,B),P(B,L(B))))),P(L(P(B,P(B,B))),P(L(B),L(L(P(B,B)))))),L(P(P(P(L(B),P(B,L(B))),P(L(L(B)),P(B,L(B)))),P(P(L(B),L(P(B,B))),P(P(B,L(B)),L(P(B,B)))))))",
"P(P(P(L(P(B,P(B,B))),L(P(P(B,B),P(B,B)))),P(P(L(B),L(P(B,B))),L(P(P(B,B),P(B,L(B)))))),L(P(P(L(L(B)),P(B,L(L(B)))),P(P(L(B),P(B,L(B))),P(L(L(B)),P(B,L(B)))))))",
"P(L(P(P(L(P(B,B)),P(L(L(B)),P(B,L(B)))),P(P(L(B),P(B,L(B))),P(L(L(B)),P(B,L(B)))))),P(L(L(P(P(B,B),P(B,L(B))))),P(L(P(B,P(B,B))),P(L(B),L(L(P(B,B)))))))",
"P(P(P(L(L(P(B,B))),L(P(B,P(B,B)))),P(L(B),L(P(P(B,B),P(B,L(B)))))),L(P(P(L(L(B)),P(B,L(L(B)))),P(P(L(B),P(B,L(B))),P(L(L(B)),P(B,L(B)))))))"};
int main()
{
	freopen("catalan.in","r",stdin);
	freopen("catalan.out","w",stdout);
	//freopen("C.in","r",stdin);
	/*
	cin>>s;
	l=0;
	vector<int> ans=solve();
	rep(i,0,6) printf("%d ",ans[i]);puts("");
	return 0;
	*/
	/*
	all[al=1]=mp(newvec(),"B");all[1].first[1]=1;
	for(int i=1;i<=al;i++)
	{
		add(List(all[i].first),"L("+all[i].second+")");
		rep(j,1,i) add(Pair(all[j].first,all[i].first),"P("+all[j].second+","+all[i].second+")");
		int flag=1;
		rep(j,0,20) if (!vis[1][1][2][5][14][42][120+j]) {flag=0;break;}
		if (flag) break;
	}
	rep(j,0,20) cout<<"\""+all[vis[1][1][2][5][14][42][120+j]].second+"\""<<endl;
	//cout<<all[vis[1][1][2][5][14][42][125]].second<<endl;
	*/
	int n;
	while (scanf("%d",&n)!=EOF && n) cout<<table[n-120]<<endl;
}
