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
#define LD long double
#define pb push_back
#define mp make_pair
#define Pi M_PI
#define clr(a) memset(a,0,sizeof(a));
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
int ans=0,vis[1000];
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		for(int j=i;j<s.size();j++)
		{
			for(int k=0;k<s.size();k++)
				vis[k]=0;
			rep(k,i,j) vis[k]=1;
			string ss="";
			for(int k=0;k<s.size();k++)
				if (!vis[k]) ss+=s[k];
			if (ss=="CODEFORCES") ans=1;
		}
	if (ans) puts("YES");else puts("NO");
}
