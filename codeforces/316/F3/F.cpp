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
/*
	Blue 0
	Yellow 1
	Green 2
	Red 3
*/
const int Range=4;
const int Range2=7;
const int eps=0;
const int N=2000;
const int U[8]={0,0,1,-1,1,1,-1,-1};
const int V[8]={1,-1,0,0,1,-1,1,-1};
queue<pair<int,int> >Q;
int sun,Sun[N][N],n,m,dt[N][N],rg[N][N],vis[N][N],ans[N];
int In(int x,int a,int b)
{
	return x>=a && x<=b;
}
void Fill_Sun(int Sx,int Sy)
{
	Q.push(mp(Sx,Sy));Sun[Sx][Sy]=sun;
	while (Q.size())
	{
		pair<int,int> c=Q.front();Q.pop();
		rep(i,0,7)
		{
			int x=c.first+U[i],y=c.second+V[i];
			if (In(x,1,n) && In(y,1,m) && !Sun[x][y] && dt[x][y]==1)
			{
				Sun[x][y]=sun;
				Q.push(mp(x,y));
			}
		}
	}
}
void Sign_Sun()
{
	rep(i,1,n) rep(j,1,m)
	if (!Sun[i][j] && dt[i][j]==1) ++sun,Fill_Sun(i,j);
}
void Sign_Green()
{
	rep(i,1,n)
	{
		if (dt[i][1]==0) Q.push(mp(i,1)),rg[i][1]=Range,vis[i][1]=1;
		if (dt[i][m]==0) Q.push(mp(i,m)),rg[i][m]=Range,vis[i][m]=1;
	}
	rep(i,1,m)
	{
		if (dt[1][i]==0) Q.push(mp(1,i)),rg[1][i]=Range,vis[1][i]=1;
		if (dt[n][i]==0) Q.push(mp(n,i)),rg[n][i]=Range,vis[n][i]=1;
	}
	while (Q.size())
	{
		pair<int,int> c=Q.front();Q.pop();
		if (rg[c.first][c.second]==0) continue;
		rep(i,0,7)
		{
			int x=c.first+U[i],y=c.second+V[i];
			if (In(x,1,n) && In(y,1,m))
			{
				if (dt[x][y]==0 && !vis[x][y]) Q.push(mp(x,y)),rg[x][y]=Range,vis[x][y]=1;
				if (dt[x][y]==1 && rg[x][y]<rg[c.first][c.second]-1)
					Q.push(mp(x,y)),vis[x][y]=1,rg[x][y]=rg[c.first][c.second]-1;
			}
		}
	}
	rep(i,1,n) rep(j,1,m)
	if (vis[i][j]==1 && dt[i][j]==1) dt[i][j]=2;
}
void Sign_Red()
{
	rep(i,1,n) rep(j,1,m)
	{
		rg[i][j]=0;vis[i][j]=0;
		if (dt[i][j]==1) Q.push(mp(i,j)),rg[i][j]=Range2,vis[i][j]=1;
	}
	while (Q.size())
	{
		pair<int,int> c=Q.front();Q.pop();
		if (rg[c.first][c.second]==0) continue;
		rep(i,0,7)
		{
			int x=c.first+U[i],y=c.second+V[i];
			if (In(x,1,n) && In(y,1,m))
			{
				if (dt[x][y]==1 && !vis[x][y]) Q.push(mp(x,y)),rg[x][y]=Range2,vis[x][y]=1;
				if (dt[x][y]==2 && rg[x][y]<rg[c.first][c.second]-1)
					Q.push(mp(x,y)),vis[x][y]=1,rg[x][y]=rg[c.first][c.second]-1;
			}
		}
	}
	rep(i,1,n) rep(j,1,n)
	if (vis[i][j]==1 && dt[i][j]==2) dt[i][j]=3;
}
int gs;
void Remark(int x,int y)
{
	gs++;
	dt[x][y]=3;
	rep(i,0,7)
	if (In(x+U[i],1,n) && In(y+V[i],1,m) && dt[x+U[i]][y+V[i]]==2) Remark(x+U[i],y+V[i]);
}
void Get_Answer()
{
	rep(i,1,n) rep(j,1,n)
	if (dt[i][j]==2)
	{
		gs=0;
		Remark(i,j);
		if (gs>eps) ans[Sun[i][j]]++;
	}
}
void Print()
{
	printf("%d\n",sun);
	sort(ans+1,ans+sun+1);
	rep(i,1,sun) printf("%d ",ans[i]);
}
int main()
{
	//freopen("01.in.txt","r",stdin);
	//freopen("me.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,1,m) scanf("%d",&dt[i][j]);
	n=max(n,m);m=max(n,m);
	Sign_Sun();
	Sign_Green();
	Sign_Red();
	/*
	rep(i,1,n) {
		rep(j,1,n)
		if (dt[i][j]==2) printf("1");else printf("0");
		puts("");
	}*/
	Get_Answer();
	Print();
}
