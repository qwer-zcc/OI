/*
    Author: Zhouxing Shi
    Created on Nov3, 2014
*/
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define drep(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define pb(x) push_back(x)
#define mp(x, y) (make_pair(x, y))
#define clr(x) memset(x, 0, sizeof(x))
#define xx first
#define yy second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int inf = ~0U >> 1;
const ll INF = ~0ULL >> 1;;
const double pi = acos(-1.0);
template <class T> inline T sqr(T a) { return a * a; }
template <class T> inline void read(T &n)
{
    char c;
	for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar()); n = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int Pow(int base, int n, int mo)
{
	if (n == 0) return 1;
	if (n == 1) return base;
	int tmp = Pow(base, n >> 1, mo);
	tmp = (ll)tmp * tmp % mo;
	if (n & 1) tmp = (ll)tmp * base % mo;
	return tmp;
}
struct point
{
	int x, y;
	point(){}
	point(int _x, int _y) : x(_x), y(_y) {}
} ;

//***************************

const int N = 1800;
const int A = 4;
const int B = 7;
//const int dx[4] = {1, -1, 0, 0};
//const int dy[4] = {0, 0, 1, -1};
const int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
const int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};
int n, m;
int G[N][N], vis[N][N], mark[N][N], vis2[N][N], vis3[N][N];
vector<int> ans;
vector<pii> E;
queue<pii> Q;

int outside(int x, int y)
{
	rep(k, 0, 7)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx > 0 && ny > 0 && nx <= n && ny <= m && G[nx][ny] == 0) return 1;
	}
	return 0;
}

int outside2(int x, int y)
{
	rep(k, 0, 7)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx > 0 && ny > 0 && nx <= n && ny <= m && (!G[nx][ny] || mark[nx][ny]) ) return 1;
	}
	return 0;
}

void BFS3(int Sx, int Sy)
{
	Q.push(mp(Sx, Sy));
	vis3[Sx][Sy] = 1;
	while (Q.size())
	{
		pii u = Q.front();
		Q.pop();
		int x = u.xx;
		int y = u.yy;
		rep(k, 0, 7)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx > 0 && ny > 0 && nx <= n && ny <= m && mark[nx][ny] && !vis2[nx][ny] && !vis3[nx][ny])
			{
				vis3[nx][ny] = 1;
				Q.push(mp(nx, ny));
			}
		}
	}
	
}

int Index;
void BFS(int Sx, int Sy)
{
	Q.push(mp(Sx, Sy));
	vis[Sx][Sy] = ++Index;
	E.clear();
	E.pb(mp(Sx, Sy));
	while (Q.size())
	{
		pii u = Q.front();
		Q.pop();
		int x = u.xx;
		int y = u.yy;
		rep(k, 0, 7)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx > 0 && ny > 0 && nx <= n && ny <= m && G[nx][ny] && !vis[nx][ny])
			{
				vis[nx][ny] = Index;
				Q.push(mp(nx, ny));
				E.pb(mp(nx, ny));
			}
		}
	}
	
	REP(i, 0, E.size())
		if (outside(E[i].xx, E[i].yy))
			Q.push(E[i]), mark[E[i].xx][E[i].yy] = 1;
	while (Q.size())
	{
		pii u = Q.front();
		Q.pop();
		if (mark[u.xx][u.yy] == A) continue;
		int x = u.xx;
		int y = u.yy;
		rep(k, 0, 7)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx > 0 && ny > 0 && nx <= n && ny <= m && G[nx][ny] && !mark[nx][ny])
			{
				mark[nx][ny] = mark[x][y] + 1;
				Q.push(mp(nx, ny));
			}
		}
	}
	REP(i, 0, E.size())
		if ((!mark[E[i].xx][E[i].yy]) && outside2(E[i].xx, E[i].yy)) 
		{
			Q.push(E[i]);
			vis2[E[i].xx][E[i].yy] = 1;
		}
	while (Q.size())
	{
		pii u = Q.front();
		Q.pop();
		if (vis2[u.xx][u.yy] == B) continue;
		int x = u.xx;
		int y = u.yy;
		rep(k, 0, 7)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx > 0 && ny > 0 && nx <= n && ny <= m && mark[nx][ny] && !vis2[nx][ny])
			{
				vis2[nx][ny] = vis2[x][y] + 1;
				Q.push(mp(nx, ny));
			}
		}
	}
	int cnt = 0;
	REP(i, 0, E.size())
		if (mark[E[i].xx][E[i].yy] && !vis2[E[i].xx][E[i].yy] && !vis3[E[i].xx][E[i].yy])
			BFS3(E[i].xx, E[i].yy), cnt++;//, cout<<"New hair: " << E[i].yy<<" " << E[i].xx<<endl;
	ans.pb(cnt);
	
//	cout << cnt << endl;
}


int main()
{
	freopen("01.in.txt", "r", stdin);
	freopen("test", "w", stdout);
	
	scanf("%d%d", &n, &m);
	rep(i, 1, n) rep(j, 1, m) scanf("%d", &G[i][j]);
	
	rep(i, 1, n) rep(j, 1, m)
		if (G[i][j] && !vis[i][j]) 
		{
			BFS(i, j);
		}
	
	sort(ans.begin(), ans.end());
	
	printf("%d\n", ans.size());
	REP(i, 0, ans.size()) printf("%d ", ans[i]);
	puts("");
	
	rep(i, 1, n) 
	{
		rep(j, 1, m) printf("%d", bool(mark[i][j] && !vis2[i][j]));
		puts("");	
	}
	
	return 0;
}
