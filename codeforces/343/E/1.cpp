/*
	Author: Zhouxing Shi
	Date: May18, 2014
	Description:
*/

#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define drep(i, a, b) for (int i = (a); i >= (b); --i)
#define repv(i, a) for (int i = 0; i < a.size(); ++i)
#define pb(x) push_back(x)
#define mp(x, y) (make_pair(x, y))
#define xx first
#define yy second
#define call puts("I'm here!")

using namespace std;

typedef long long llu;
typedef pair<int, int> pii;
typedef complex<double> cdb;
const int inf = ~0U >> 1;
const llu INF = (llu)1e18;
const double pi = acos(-1.0);
template <class T> inline void read(T &n)
{
    char c;
	for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar()); n = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int pw(int base, int n, int mo)
{
	if (n == 0) return 1;
	if (n == 1) return base;
	int tmp = pw(base, n >> 1, mo);
	tmp = (llu)tmp * tmp % mo;
	if (n & 1) tmp = (llu)tmp * base % mo;
	return tmp;
}
struct point
{
	int x, y;
	point () {}
	point (int _x, int _y) : x(_x), y(_y) {}
} ;

//**************************

struct edge
{
	int x, y, w;
	edge() {}
	edge(int _x, int _y, int _w) : x(_x), y(_y), w(_w) {}
} e[2000], fle[200*200*3];

int N, M;

namespace flow
{
	const int maxn = 210, maxm = 5000;
	int C[maxm], with[maxm], f[maxm], op[maxm], nxt[maxm];
	int cur[maxn], gap[maxn], dis[maxn], head[maxn], _aug[maxn];
	int Index, aug, ans, T, S;
	queue <int> Q;
	pair<int,int>pre[maxn];
	
    void Aug()
    {
        ans += aug;
        for (int i = T; i != S; i = pre[i].xx)
            f[pre[i].yy] += aug, f[op[pre[i].yy]] -= aug;
    }	
    
	int SAP()
	{
		rep(i, 1, N) gap[i] = 0, dis[i] = N, _aug[i] = 0, cur[i] = head[i];
        ans = 0;
        aug = inf;
        dis[T] = 0;
        Q.push(T);
        while (Q.size())
        {
        	int u = Q.front(); Q.pop();
        	for (int i = head[u]; i; i = nxt[i])
        		if (!C[i] && dis[u] + 1 < dis[with[i]]) 
        		{
        			dis[with[i]] = dis[u] + 1;
        			Q.push(with[i]);
        		}
        }
        rep(i, 1, N) gap[dis[i]]++;
        int u = S;
        while (dis[S] < N)
        {
            _aug[u] = aug;
            bool flag = 1;
            for (int i = cur[u]; i; i = nxt[i])
            {
                int v = with[i];
                if (dis[v] + 1 == dis[u] && C[i] - f[i] > 0)
                {
                    cur[u] = i;
                    if (C[i] - f[i] < aug) aug = C[i] - f[i];
                    flag = 0, pre[v] = mp(u, i), u = v;
                    if (u == T) Aug(), u = S, aug = inf;
                    break;
                }
            }
            if (!flag) continue;
            if ((--gap[dis[u]]) == 0) return ans;
            dis[u] = N;
            cur[u]=head[u];
            for (int i = head[u]; i; i = nxt[i])
            {
                int v = with[i];
                if (dis[v] + 1 < dis[u] && C[i] - f[i] > 0) dis[u] = dis[v] + 1, cur[u] = i;
            }
            gap[dis[u]]++;
            if (u != S) u = pre[u].first, aug = _aug[u];
        }
        return ans;
	}
	
    inline void add(int x, int y, int c)
    {
	   	++Index;
    	with[Index] = y; nxt[Index] = head[x]; C[Index] = c; f[Index] = 0; head[x] = Index;
    	op[Index] = Index + 1;
    	++Index;
    	with[Index] = x; nxt[Index] = head[y]; C[Index] = f[Index] = 0; head[y] = Index;
    	op[Index] = Index - 1;
    }
    
	int main(int _S, int _T)
	{
		S = _S; T = _T;
		Index = 0;
		memset(head, 0, sizeof(head));
		rep(i, 1, M) add(e[i].x, e[i].y, e[i].w), add(e[i].y, e[i].x, e[i].w);
		return SAP();	
	}
}

const int mn = 300;

int n, ret, mini, f[mn], v[mn][mn];
pii opt;
bool cmp(const edge &a, const edge &b) { return a.w > b.w; }

struct Edge
{
	int y, w;
	Edge *nxt;
	Edge(){}
	Edge(int _y, int _w, Edge *_nxt) : y(_y), w(_w), nxt(_nxt) {}
} *head[mn];

int find(int x) { return (f[x] == x) ? x : (f[x] = find(f[x])); }

void add(int x, int y, int w)
{
	head[x] = new Edge(y, w, head[x]);
}

void dfs(int u, int fa)
{
	for (Edge* i = head[u]; i; i = i->nxt)
		if (i->y != fa && !v[u][i->y])
		{
			if (i->w < mini)
			{
				mini = i->w;
				opt = mp(u, i->y); 
			}
			dfs(i->y, u);
		}
}

void solve(int S)
{
	mini = inf;
	dfs(S, 0);
	if (mini == inf) printf("%d ", S);
	else
	{
		int x = opt.xx, y = opt.yy;
		v[x][y] = v[y][x] = 1;
		solve(x); solve(y);
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	rep(i, 1, M) 
		scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
	rep(i, 1, N)
		rep(j, i + 1, N)
		{
			fle[++n] = edge(i, j, flow::main(i, j));
			if (N==200) printf("%d ",fle[n].w);
			assert(fle[n].w>0);
		}
	sort(fle + 1, fle + n + 1, cmp);
	rep(i, 1, N) f[i] = i;
	rep(i, 1, n)
	{
		int x = find(fle[i].x), y = find(fle[i].y);
		if (x != y)
		{
			ret += fle[i].w;
			f[x] = y;
			add(fle[i].x, fle[i].y, fle[i].w);
			add(fle[i].y, fle[i].x, fle[i].w);
		}
	}
	printf("%d\n", ret);
	solve(1);
 	return 0;
}
