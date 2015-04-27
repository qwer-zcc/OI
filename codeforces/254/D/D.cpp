//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 02/11/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF (~0U>>1)-3
#define LLINF ~0ULL>>1
#define LL long long
#define uLL unsigned long long
#define uint unsigned int
#define D double
#define LD long double
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define pb push_back
#define mp make_pair
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
template<class T> void read(T &x)
{
    char ch;
    while ((ch=getchar()) && !isdigit(ch));x=ch-'0';
    while ((ch=getchar()) && isdigit(ch)) x=x*10+ch-'0';
}
const int N=1010;
struct Bitset
{
	int a[10];
	void insert(int x)
	{
		a[x>>5]|=1<<(x-((x>>5)<<5));
	}
	void sc()
	{
		rep(i,0,5)
		{
			rep(j,0,31) printf("%d",(a[i]&(1<<j))>0);
		}
		puts("");
	}
}bits[N*N],Full;
const int u[4]={0,0,1,-1};
const int v[4]={1,-1,0,0};
int TIM,dt[N][N],Rid[N][N],id[N][N],vis[N*N],dis[N][N],Sx,Sy,n,m,d,cnt,Rcnt,ti,All[N*N];
pair<int,int> pos[N*N];
queue<int> Q;
bool operator ==(Bitset a,Bitset b)
{
	rep(i,0,9)
	if (a.a[i]!=b.a[i]) return 0;
	return 1;
}
Bitset operator |(Bitset a,Bitset b)
{
	rep(i,0,9) a.a[i]|=b.a[i];
	return a;
}
void Get_Place(int x,int y,int c)
{
	dis[x][y]=c;
	if (dt[x][y]!=2)
	{
		bits[id[x][y]].insert(Rid[Sx][Sy]),Q.push(id[x][y]);
		if (!vis[id[x][y]]) All[++ti]=id[x][y],vis[id[x][y]]=1;
	}
	if (c==0) return;
	rep(i,0,3)
	if (dis[x+u[i]][y+v[i]]<c-1 && dt[x+u[i]][y+v[i]]!=2) Get_Place(x+u[i],y+v[i],c-1);
}
char s[N];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	//freopen("D.in","r",stdin);
	scanf("%d%d%d",&n,&m,&d);
	rep(i,1,n)
	{
		scanf("%s",s+1);
		rep(j,1,m) dt[i][j]=s[j]=='.'?0:(s[j]=='R'?1:2);
	}
	rep(i,1,n) rep(j,1,m)
	if (dt[i][j]==0) id[i][j]=++cnt,pos[cnt]=mp(i,j);
	else if (dt[i][j]==1) id[i][j]=++cnt,pos[cnt]=mp(i,j),Rid[i][j]=Rcnt++;
	if (Rcnt>290) {puts("-1");return 0;}
	rep(i,1,n) rep(j,1,m)
	if (dt[i][j]==1)
	{
		rep(_,-10,10) rep(__,-10,10)
		if (i+_>=1 && i+_<=n && j+__>=1 && j+__<=m) dis[i+_][j+__]=-1;
		while (Q.size()) Q.pop();
		++TIM,Sx=i,Sy=j;
		Get_Place(i,j,d);
	}
	rep(i,0,Rcnt-1) Full.insert(i);
	while (Q.size())
	{
		int x=Q.front();Q.pop();
		rep(i,1,ti)
		if ((bits[x]|bits[All[i]])==Full)
		{
			if (x==All[i])
			{
				printf("%d %d ",pos[x].first,pos[x].second);
				rep(j,1,cnt)
				if (j!=x) {printf("%d %d\n",pos[j].first,pos[j].second);break;}
				exit(0);
			}
			printf("%d %d %d %d\n",pos[x].first,pos[x].second,pos[All[i]].first,pos[All[i]].second);
			exit(0);
		}
	}
	puts("-1");
}

