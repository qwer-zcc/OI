/*
    Author: Zhouxing Shi
    Date: July 9, 2014
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
#include <complex>
#include <iostream>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define drep(i, a, b) for (int i = (a); i >= (b); --i)
#define pb(x) push_back(x)
#define ins(x) insert(x)
#define ps(x) push(x)
#define clr(x) memset(x, 0, sizeof(x))
#define mp(x, y) (make_pair(x, y))
#define xx first
#define yy second

using namespace std;

typedef long long llu;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef complex<double> cdb;
const int inf = ~0U >> 1;
const llu INF = (llu)1e18;
const double pi = acos(-1.0);
template <class T> inline T sqr(T a) { return a * a; }
template <class T> inline T min(T a, T b, T c) { return min(min(a, b), c); }
template <class T> inline T max(T a, T b, T c) { return max(max(a, b), c); }
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

//***************************

map <string, int> hash;
map <int, string> str;
double dp[510][510][150];
vector <pii> E[510];
vector <int> opt[510][510];

double sf[2][320][510], expe[2][320], Dec[320][3], Inc[320], G[500][500], g1[600], g2[500];
int A[500], B[500], T[500], C, N, R;
string s, s1, s2, s3;

int H(string s) 
{ 
	if (hash[s]) return hash[s];
	else { str[++C] = s; return hash[s] = C;}
}


void run()
{	
	double x;
	cin >> N;
	rep(i, 1, N) rep(j, 1, N) rep(k, 1, C) dp[i][j][k] = -1e100;
	rep(i, 1, N) rep(j, 1, N) opt[i][j].clear();
	rep(i, 1, N)
		for (cin >> s; s != "END"; cin >> s)
			cin >> x, dp[i][i][hash[s]] = log(x), opt[i][i].pb(hash[s]);
			
	rep(step, 2, N)
	{
		rep(i, 1, N - step + 1)
		{
			int j = i + step - 1;
			rep(k, i, j - 1)
			{
				for (int it = 0; it < opt[i][k].size(); ++it)
				{
					int col = opt[i][k][it]; double f = dp[i][k][col];
					for (int p = 0; p < E[col].size(); ++p)
					{
						if (dp[k + 1][j][E[col][p].xx] < -1e50) continue;
						if (dp[i][j][E[col][p].yy] < -1e50)
							dp[i][j][E[col][p].yy] = f + dp[k + 1][j][E[col][p].xx],
							opt[i][j].pb(E[col][p].yy);
						else dp[i][j][E[col][p].yy] = max(dp[i][j][E[col][p].yy], f + dp[k + 1][j][E[col][p].xx]);
					}
				}
			}
		}
	}
	
	int pos = 0;
	double best = -1e30;
	
	if (!opt[1][N].size())
	{
		cout << "GAMEOVER" << endl;
		return;
	}
	
	rep(i, 1, C)
		if (dp[1][N][i] > -1e80)
		{
			if (dp[1][N][i] > best)
			{
				best = dp[1][N][i];
				pos = i;
			}
		}
	
	cout << str[pos] << endl;
			
			
}

int cases;

int main()
{
	freopen("A.in", "r", stdin);
	//freopen("out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin >> R;
	rep(i, 1, R)
	{
		cin >> s1 >> s2 >> s3;
		A[i] = H(s1); B[i] = H(s2); T[i] = H(s3);
		E[A[i]].pb(mp(B[i], T[i]));
		E[B[i]].pb(mp(A[i], T[i]));
	}
	str[0] = "GAMEOVER";
	cin >> cases;
	while (cases--) run();
    return 0;
}
