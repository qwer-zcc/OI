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
const int N=80000000;
bool w[N*2+10];
char s[10][10][10];
int main()
{
	freopen("beavers.in","r",stdin);
	freopen("beavers.out","w",stdout);
	rep(i,0,4) rep(j,0,1) scanf("%s",s[i][j]);
	int cur=N+2,mood=0;
	rep(i,1,N)
	{
		char *p=s[mood][w[cur]];
		w[cur]=p[0]-'0';
		if (p[1]=='L') cur--;else cur++;
		mood=p[2]-'A';
		if (mood>5) {puts("happy beaver");return 0;}
	}
	puts("unhappy beaver");
}
