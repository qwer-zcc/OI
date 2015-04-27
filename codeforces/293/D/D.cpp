//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 02/11/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF int(2e9)
#define LLINF (LL)(8e18)
#define LL long long
#define uLL unsigned long long
#define uint unsigned int
#define D long double
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
const int N=2200000,L=2000000;
struct lj{int x,y;}P[N];
const D eps=1e-7;
int Max[N],Min[N],n;
D ans,cnt;
void add(int X1,int Y1,int X2,int Y2)
{
	if (X1>X2) swap(X1,X2),swap(Y1,Y2);
	if (X1==X2) {Min[X1]=min(Min[X1],min(Y1,Y2)),Max[X1]=max(Max[X1],max(Y1,Y2));return;}
	D p=(D)(Y2-Y1)/(X2-X1);
	for (D c=Y1;X1<=X2;X1++,c+=p)
	{
		Min[X1]=min(Min[X1],(int)ceil(c-(eps)));
		Max[X1]=max(Max[X1],(int)floor(c+(eps)));
	}
}
void work()
{
	rep(i,0,L) Min[i]=INF,Max[i]=-INF;
	rep(i,1,n) add(P[i].x,P[i].y,P[i%n+1].x,P[i%n+1].y);
	cnt=0;
	D p0=0,p1=0,p2=0,q0=0,q1=0,q2=0;
	rep(i,0,L)
	if (Max[i]!=-INF)
	{
		cnt+=Max[i]-Min[i]+1;
		p0=Max[i]-Min[i]+1;
		p1=(D)i*(Max[i]-Min[i]+1);
		p2=(D)i*i*(Max[i]-Min[i]+1);
		ans+=p2*q0+p0*q2-2.*p1*q1;
		q0+=Max[i]-Min[i]+1;
		q1+=(D)i*(Max[i]-Min[i]+1);
		q2+=(D)i*i*(Max[i]-Min[i]+1);
	}
	else break;
}
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d",&n);int Minx=INF,Miny=INF;
	rep(i,1,n) scanf("%d%d",&P[i].x,&P[i].y),Minx=min(Minx,P[i].x),Miny=min(Miny,P[i].y);
	rep(i,1,n) P[i].x-=Minx,P[i].y-=Miny;
	work();
	rep(i,1,n) swap(P[i].x,P[i].y);
	work();
	printf("%.10lf\n",(double)(ans/cnt/(cnt-1.)));
}

