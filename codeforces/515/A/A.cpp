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
int n;
char s[1000];
int val[1000];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n)
		for(char j='0';j<=s[i];j++)
		{
			if (j=='0') val[0]++;
			else if (j=='1') val[1]++;
			else if (j=='2') val[2]++;
			else if (j=='3') val[3]++;
			else if (j=='4') val[2]+=2;
			else if (j=='5') val[5]++;
			else if (j=='6') val[2]++,val[3]++;
			else if (j=='7') val[7]++;
			else if (j=='8') val[2]+=3;
			else if (j=='9') val[3]+=2;
		}
	drep(i,9,2)
		while (val[i])
		{
			printf("%d",i);
			rep(k,1,i){
			char j='0'+k;
			if (j=='0') val[0]--;
			else if (j=='1') val[1]--;
			else if (j=='2') val[2]--;
			else if (j=='3') val[3]--;
			else if (j=='4') val[2]-=2;
			else if (j=='5') val[5]--;
			else if (j=='6') val[2]--,val[3]--;
			else if (j=='7') val[7]--;
			else if (j=='8') val[2]-=3;
			else if (j=='9') val[3]-=2;}
		}
	puts("");
}
