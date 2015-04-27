//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 12/10/2014                 |
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
struct point
{
    int x,y;
    point() {}
    point(int _x,int _y) : x(_x),y(_y) {}
} ;
const int N=400000;
map<pair<int,int>,bool>Hash;
map<int,int>VIS;
vector<int> hash[N];
int K,m,TIM,vis[N],Cnt;
int calc(int x,int y,int op1)
{
	if (op1==2) return x*y;
	else if (op1==1) return x+y;
	else if (op1==0) return x-y;
}
void add(int c,int x)
{
	if (x>=0 && vis[x]!=TIM) hash[x].pb(c),vis[x]=TIM;
}
int main()
{
	//freopen("me.out","w",stdout);
	scanf("%d%d",&K,&m);
	rep(i,0,9) rep(j,0,9) rep(k,0,9) rep(l,0,9)
	{
		++TIM;
		rep(op1,0,2) rep(op2,0,2) rep(op3,0,2)
		{
			int sum=i;
			sum=calc(sum,j,op1);
			sum=calc(sum,k,op2);
			sum=calc(sum,l,op3);
			add(i*1000+j*100+k*10+l,sum);
			sum=i*10+j;
			sum=calc(sum,k,op1);
			sum=calc(sum,l,op2);
			add(i*1000+j*100+k*10+l,sum);
			sum=i;
			sum=calc(sum,j*10+k,op1);
			sum=calc(sum,l,op2);
			add(i*1000+j*100+k*10+l,sum);
			sum=i;
			sum=calc(sum,j,op1);
			sum=calc(sum,k*10+l,op2);
			add(i*1000+j*100+k*10+l,sum);
			sum=i*100+j*10+k;
			sum=calc(sum,l,op1);
			add(i*1000+j*100+k*10+l,sum);
			sum=i;
			sum=calc(sum,j*100+k*10+l,op1);
			add(i*1000+j*100+k*10+l,sum);
			add(i*1000+j*100+k*10+l,i*1000+j*100+k*10+l);
		}
	}
	rep(i,1,K)
	if (K%i==0 && !Hash[mp(i,K/i)])
	{
		Hash[mp(i,K/i)]=1;
		for (int j=0;j<hash[i].size();j++)
		for (int k=0;k<hash[K/i].size();k++)
		if (!VIS[hash[i][j]*10000+hash[K/i][k]])
		{
			m--;
			printf("%04d%04d\n",hash[i][j],hash[K/i][k]);
			VIS[hash[i][j]*10000+hash[K/i][k]]=1;
			if (!m) return 0;
		}
	}
	rep(i,0,K)
	if (!Hash[mp(i,K-i)])
	{
		Hash[mp(i,K-i)]=1;
		for (int j=0;j<hash[i].size();j++)
		for (int k=0;k<hash[K-i].size();k++)
		if (!VIS[hash[i][j]*10000+hash[K-i][k]])
		{
			m--;
			printf("%04d%04d\n",hash[i][j],hash[K-i][k]);
			VIS[hash[i][j]*10000+hash[K-i][k]]=1;
			if (!m) return 0;
		}
	}
}

