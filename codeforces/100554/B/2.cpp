 #include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(a,b,c) for(int a=(b);a<=(c);a++)
const int nax = 2e5 + 5;

using namespace std;

int a,b,n,glob,test;
int gleb[nax], ojc[nax];
vector<int> wyn, v[nax];

bool cmp(int i, int j) {
	return gleb[i] > gleb[j];
}

int dfs2(int x) {
	int gora = -1;
	int dol = 0;
	
	for (auto i: v[x]) if (i != ojc[x]) {
		int y = dfs2(i);
		if (y > 0)
			gora = max(gora, y-1);
		if (y < 0)
			dol = max(dol, -y);
	}
	
	if (gora >= dol) {
		if (gora == 0)
			return 0;
		return gora;
	}
	
	if (dol == glob) {
		//printf("dodaje %d %d\n",x,glob);
		wyn.pb(x);
		return glob;
	}
	else
		return -(dol+1);
}

int dfs1(int x, int f) {
	ojc[x] = f;
	for (auto i: v[x]) if (i != f) {
		gleb[x] = max(gleb[x], dfs1(i, x));
	}
	
	sort(v[x].begin(), v[x].end(), cmp);
	return gleb[x]+1;
}

bool check(int s) {
	wyn.clear();
	glob = s;
	if (dfs2(1) < 0)
		wyn.pb(1);
	return ((int)wyn.size() <= 2);
}
int main() {
	freopen("B.in","r",stdin);
	scanf("%d",&test);
	while (test--) {
		scanf("%d",&n);
		REP(i,n-1) {
			scanf("%d%d",&a,&b);
			v[a].pb(b);
			v[b].pb(a);
		}
		
		dfs1(1,0);
		
		int l = 0;
		int p = n-1;
		while (l != p) {
			int s = (l+p)/2;
			if (check(s))
				p = s;
			else
				l = s+1;
		}
		
		//if (check(1))
		//	puts("RR");
		
		check(l);
		if ((int)wyn.size() == 1)
			wyn.pb(wyn[0] == n ? 1 : wyn[0]+1);
		printf("%d\n",l);
		//printf("%d %d %d\n",l,wyn[0],wyn[1]);
		
		FOR(i,1,n) {
			gleb[i] = ojc[i] = 0;
			v[i].clear();
		}
	}
	return 0;
}
