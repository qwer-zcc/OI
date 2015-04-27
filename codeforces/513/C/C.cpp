#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k; 
int f[408][58], l[10], r[10]; 
bool vis[58]; long double ans;

void Calc(int x, int d) {
	long double rep = 0.0;
	for (int i = 1; i <= n; i++)
		if (x != i && ((x < i && r[i] >= d) || (x > i && r[i] > d))) {
			int o = min(r[i] - d + 1, r[i] - l[i] + 1);
			if (x > i && l[i] <= d) o--;
			long double pp = (long double)o / (r[i] - l[i] + 1);
			for (int j= 1; j <= n; j++) 
				if (i != j && x != j) 
				{
				if (l[j] > d) pp = 0.0;
				else {
					o = min(d - l[j] + 1, r[j] - l[j] + 1);
					if (x < j && r[j] >= d) o--;
					pp *= (long double)o / (r[j] - l[j] + 1);
				}
			}
			rep += pp * d; 
		}
		ans += rep / (r[x] - l[x] + 1);
}

int main() {
	freopen("C.in","r",stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d%d", l + i, r + i);
	for (int i = 1; i <= n; i++)
		for (int j = l[i]; j <= r[i]; j++) 
			Calc(i, j);
	printf("%.14lf\n", (double)ans);
}
