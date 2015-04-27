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
void work()
{
	int ans=0,p=0,q=0;
	cin>>s;
	for(int i=0;i<s.size();i++) if (s[i]=='*') p++;else q++;
	if (q<p+1)
		rep(i,1,p+1-q) s='1'+s,ans++;
	int cnt=0,pre=(int)(s.size())-1;
	for(int i=0;i<s.size();i++)
	{
		if (s[i]>='1' && s[i]<='9') cnt++;
		if (s[i]=='*')
		{
			cnt--;
			if (cnt<=0)
			{
				cnt+=2;ans++;
				for(;pre>=0;pre--)
					if (s[pre]>='0' && s[pre]<='9')
					{
						swap(s[pre],s[i]);
						break;
					}
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	//freopen("K.in","r",stdin);
	int cs;
	scanf("%d",&cs);
	while (cs--) work();
}
