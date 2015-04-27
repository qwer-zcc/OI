/*
	Author: Zhouxing Shi
	Date: May6, 2014
	Description:
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>
#include <ctime>
#include <map>
#include <cmath>
#include <string>
#include <stack>
#include <iostream>
#include <complex>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define drep(i, a, b) for (int i = (a); i >= (b); --i)
#define repv(i, a) for (int i = 0; i < a.size(); ++i)
#define pb(x) push_back(x)
#define ins(x) insert(x)
#define ps(x) push(x)
#define clr() clear()
#define mp(x, y) (make_pair(x, y))

using namespace std;

typedef long long llu;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef complex<double> cdb;
const int inf = ~0U >> 1;

//***************************

struct point 
{
	int x, y;
} a[120000];

bool cmp(const point &a, const point &b)
{
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

map <int, int> hash[2000000];
int N, cnt[2000000], ans;

int main()
{
	freopen("D.in","r",stdin);
	scanf("%d", &N); int sq = int(sqrt(N));
	rep(i, 1, N) scanf("%d%d", &a[i].x, &a[i].y);
	sort(a + 1, a + N + 1, cmp);
	rep(i, 1, N)
	{
		int j = i;
		while (j <= N && a[i].x == a[j].x) j++;
		if (j - i <= sq)
		{
			rep(k1, i, j - 1)
				rep(k2, k1 + 1, j - 1)
					if (hash[a[k1].y][a[k1].x - (a[k2].y - a[k1].y)] && hash[a[k2].y][a[k1].x - (a[k2].y - a[k1].y)])
						ans++;
		}
		else
		{
			rep(k, i, j - 1) cnt[a[k].y]++;
			rep(k1, 1, i - 1)
				rep(k2, k1 + 1, i - 1)
				{
					if (a[k1].x != a[k2].x) break;
					if (a[k2].y - a[k1].y != a[i].x - a[k1].x) continue;
					ans += cnt[a[k1].y] * cnt[a[k2].y];
				}
			rep(k, i, j - 1) cnt[a[k].y]--;
		}
		rep(k, i, j - 1) 
			hash[a[k].y][a[k].x]++;
		i = j - 1;
		//printf("%d\n",ans);
	}
	printf("%d\n", ans);
 	return 0;
}
