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
#include <cassert>
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
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
const int N=200;
char a[N],b[N];
int n,m,nxt[N][N],len[N],Sum[N],Len[N];
LL Mod,Left[N][N][N],Right[N][N],mid[N][N],tmp[N][N],cur[N][N];
LL Pow(LL a,LL k,LL Mod){LL b=1;for(;k;k>>=1,a=a*a%Mod)b=b*a%Mod;return b;}
void solve(int x)
{
	rep(i,1,len[x]) if (nxt[x][i]>9) solve(nxt[x][i]-9);
	memset(cur,0,sizeof(cur));
	int l=1,sum=0;
	//calc Left
	rep(i,1,len[x])
	{
		if (nxt[x][i]<10)
		{
			sum=(sum*10+nxt[x][i])%n;l=(l*10)%n;
			Left[x][sum][l]++;
		}
		else
		{
			int y=nxt[x][i]-9,c=Pow(10,Len[y],n);
			rep(j,0,n-1) rep(k,0,n-1)
				Left[x][(sum*k+j)%n][(k*l)%n]=(Left[x][(sum*k+j)%n][(k*l)%n]+Left[y][j][k])%Mod;
			sum=(sum*c+Sum[y])%n;l=l*c%Mod;
		}

	}
	Sum[x]=sum;
	rep(i,1,len[x])
	{
		if (nxt[x][i]<10) Len[x]=(Len[x]+1)%n;
		else Len[x]=(Len[x]+Len[nxt[x][i]-9])%n;
	}

	//calc Right
	l=1,sum=0;
	drep(i,len[x],1)
	{
		if (nxt[x][i]<10)
		{
			if (nxt[x][i]>0) Right[x][sum=(sum+nxt[x][i]*l)%n]++;
			l=(l*10)%n;
		}
		else
		{
			int y=nxt[x][i]-9;
			rep(j,0,n-1) Right[x][(sum+j*l)%n]=(Right[x][(sum+j*l)%n]+Right[y][j])%Mod;
			sum=(sum+Sum[y])%n;
			l=l*Pow(10,Len[y],n)%n;
		}
	}
	

	//calc mid
	//cur[0][10%n]++;
	drep(i,len[x],1)
	{
		if (nxt[x][i]<10)
		{
			//if (nxt[x][i]>0) mid[x][nxt[x][i]%n]++;
			rep(j,0,n-1) rep(k,0,n-1) tmp[j][k]=0;
			tmp[nxt[x][i]%n][10%n]=1;
			rep(j,0,n-1) rep(k,0,n-1) tmp[(j+nxt[x][i]*k)%n][k*10%n]+=cur[j][k];
			rep(j,0,n-1) rep(k,0,n-1) cur[j][k]=tmp[j][k]%Mod;
			rep(j,0,n-1) rep(k,0,n-1) mid[x][j]=(mid[x][j]+cur[j][k])%Mod;
		}
		else
		{
			int y=nxt[x][i]-9;
			rep(j,0,n-1) mid[x][j]=(mid[x][j]+mid[y][j])%Mod;
			rep(j,0,n-1) rep(k,0,n-1) rep(l,0,n-1)
				mid[x][(k*l+j)%n]=(mid[x][(k*l+j)%n]+cur[j][k]*Right[y][l])%Mod;
			rep(j,0,n-1) rep(k,0,n-1) tmp[j][k]=Left[y][j][k];
			int c=Pow(10,Len[y],n);
			rep(j,0,n-1) rep(k,0,n-1) tmp[(j+Sum[y]*k)%n][k*c%c]+=cur[j][k];
			rep(j,0,n-1) rep(k,0,n-1) cur[j][k]=tmp[j][k]%Mod;
		}
	}
}
char s[1000];
int main()
{
	freopen("B.in","r",stdin);
	scanf("%d%lld",&n,&Mod);
	scanf("%d",&m);
	rep(i,1,m)
	{
		scanf("%s",s);int l=strlen(s),x=s[0]-'A'+1;
		len[x]=l-3;
		rep(j,3,l-1)
		{
			if (s[j]>='0' && s[j]<='9') nxt[x][j-2]=s[j]-'0';
			else if (s[j]>='A' && s[j]<='Z') nxt[x][j-2]=s[j]-'A'+10;
			else assert(0);
		}
	}
	solve(1);
	printf("%lld\n",mid[1][0]);
}
