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
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
const int MAXN = 200010;

int n, c, d;
bool vis[MAXN];
vector<int> edges[MAXN];
vector<int> selected;

int dfs(int u){
	vis[u] = 1;
	int ma = 0;
	int mi = 0;
	for (int i=0;i<edges[u].size();i++)
	if(!vis[edges[u][i]]){
		int a = dfs(edges[u][i])-1;
		ma = max(a, ma);
		mi = min(a, mi);
	}
	int r;
	if(ma + mi <= 0){
		r = mi;
	}else{
		r = ma;
	}
	if(r <= -d){
		selected.push_back(u);
		++c;
		return d+1;
	}
	return r;
}

bool check(int lim){
	c = 0; d = lim;
	selected.clear();
	FWD(i,1,n+1) vis[i] = 0;
	if(dfs(1) <= 0){
		++c;
		selected.push_back(1);
		//printf("buduje w %d\n", 1);
	}
	return c < 3;
}

int main(){
	freopen("B.in","r",stdin);
	int z; scanf("%d", &z); while(z--){
		scanf("%d", &n);
		FWD(i,1,n+1) edges[i].clear();
		FWD(i,1,n){
			int u, v;
			scanf("%d %d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		//check(2); continue;
		int lo = -1;
		int hi = n;
		while(hi-lo > 1){
			if(check((lo+hi)/2))
				hi = (lo+hi)/2;
			else
				lo = (lo+hi)/2;
		}
		check(hi);
		printf("%d", hi);
		if(selected.size() == 1){
			selected.push_back(selected[0] == 1 ? 2 : 1);
		}
		for (int u=0;u<selected.size();u++) printf(" %d",selected[u]);puts("");
	}
	return 0;
}
