//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 02/11/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF int(1e8)
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
LL Pow(LL a,LL b,LL Mod){LL ans=1;a%=Mod;for(;b;b>>=1) ans=b&1?(ans*a%Mod):ans,a=a*a%Mod;return ans;}
const int N=3010;
queue<int> Q;
vector<int> E[N];
int n,Tree[N],dis[N],vis[N],rd[N],Ring[N],Rcnt;
D Ans[N][N];
void dfs(int w,int Fa,int id)
{
	if (Fa) Tree[w]=id;
	for (int i=0;i<E[w].size();i++)
	if (!Ring[E[w][i]] && E[w][i]!=Fa) dfs(E[w][i],w,id);
}
void spfa(int S)
{
	rep(i,1,n) dis[i]=INF,vis[i]=0;
	dis[S]=1;Q.push(S);
	while (Q.size())
	{
		int x=Q.front();Q.pop();vis[x]=0;
		for (int i=0;i<E[x].size();i++)
		if (dis[E[x][i]]>dis[x]+1)
		{
			dis[E[x][i]]=dis[x]+1;
			if (!vis[E[x][i]]) Q.push(E[x][i]),vis[E[x][i]]=1;
		}
	}
}
int Dis_Min(int x,int y)
{
	if (x>y) swap(x,y);
	return min(y-x+1,Rcnt-y+1+x);
}
int Dis_Max(int x,int y)
{
	if (x>y) swap(x,y);
	return max(y-x+1,Rcnt-y+1+x);
}
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d",&n);int x,y;
	rep(i,1,n) scanf("%d%d",&x,&y),x++,y++,rd[x]++,rd[y]++,E[x].pb(y),E[y].pb(x);
	rep(i,1,n) if (rd[i]==1) Q.push(i);
	while (Q.size())
	{
		int x=Q.front();Q.pop();Tree[x]=1;
		for (int i=0;i<E[x].size();i++)
		{
			rd[E[x][i]]--;
			if (rd[E[x][i]]==1) Q.push(E[x][i]);
		}
	}
	int R1=0,Rn;
	rep(i,1,n)
	if (!Tree[i]) {R1=i;Ring[i]=++Rcnt;break;}
	Rn=R1;
	while (1)
	{
		int flag=0;
		for (int i=0;i<E[Rn].size();i++)
		if (!Tree[E[Rn][i]] && !Ring[E[Rn][i]])
		{
			flag=1;
			Ring[E[Rn][i]]=++Rcnt;
			Rn=E[Rn][i];
			break;
		}
		if (!flag) break;
	}
	
	//rep(i,1,n) printf("%d ",Tree[i]);puts("");
	//rep(i,1,n) printf("%d ",Ring[i]);puts("");
	rep(i,1,n)
	if (!Tree[i]) dfs(i,0,i);
	//rep(i,1,n) printf("%d ",Tree[i]);puts("");
	D ans=n;
	//spfa(1);
	//rep(i,1,n) printf("%d ",dis[i]);puts("");
	//return 0;
	rep(i,1,n)
	//if (Tree[i])
	{
		spfa(i);
		rep(j,1,n)
		if (j!=i)
		{
			D aans=ans;
			if ((Tree[i] && Tree[i]==Tree[j]) || (Tree[i]==j) || (Tree[j]==i)) ans+=1./dis[j];
			else
			{
				if (Ring[i] && Ring[j])
				{
					//if (i==1 && j==3) printf("%d %d %d\n",Dis_Min(Ring[i],Ring[j]),Dis_Max(Ring[i],Ring[j]),Rcnt);
					ans+=1./Dis_Min(Ring[i],Ring[j])+1./Dis_Max(Ring[i],Ring[j])-1./Rcnt;
				}
				else if (Ring[i])
				{
					ans+=1./dis[j];
					ans+=1./(dis[j]-Dis_Min(Ring[i],Ring[Tree[j]])+Dis_Max(Ring[i],Ring[Tree[j]]));
					ans-=1./(dis[j]-Dis_Min(Ring[i],Ring[Tree[j]])+Rcnt);
				}
				else if (Ring[j])
				{
					ans+=1./dis[j];
					ans+=1./(dis[j]-Dis_Min(Ring[j],Ring[Tree[i]])+Dis_Max(Ring[j],Ring[Tree[i]]));
					ans-=1./(dis[j]-Dis_Min(Ring[j],Ring[Tree[i]])+Rcnt);
				}
				else
				{
					ans+=1./dis[j];
					ans+=1./(dis[j]-Dis_Min(Ring[Tree[j]],Ring[Tree[i]])+Dis_Max(Ring[Tree[j]],Ring[Tree[i]]));
					ans-=1./(dis[j]-Dis_Min(Ring[Tree[j]],Ring[Tree[i]])+Rcnt);
				}
			}
			Ans[i][j]=ans-aans;
			
			//printf("%d %d %lf\n",i,j,Ans[i][j]);
		}
	}
	/*rep(i,1,n)
	{
		rep(j,1,n) printf("%.3lf ",Ans[i][j]);
		puts("");
	}*/
	printf("%.10lf\n",ans);
}
