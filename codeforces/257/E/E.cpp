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
const int N=120000;
set<pair<int,int> > unk,InUp,OutUp;
set<pair<int,int>,greater<pair<int,int> > > InDown,OutDown;
struct lj{int t,s,f;}P[N];
int dir,Fnow,PUp,PDown,n,m,Finish;
LL Tnow,ans[N];
void Wait()
{
//	puts("Wait");
	if (dir==0) Fnow+=unk.begin()->first-Tnow;
	else if (dir==1) Fnow-=unk.begin()->first-Tnow;
	Tnow=(LL)unk.begin()->first;
	if (P[unk.begin()->second].s>=Fnow) OutUp.insert(mp(P[unk.begin()->second].s,unk.begin()->second)),PUp++;
	else OutDown.insert(mp(P[unk.begin()->second].s,unk.begin()->second)),PDown++;
	dir=PDown>PUp;
	unk.erase(unk.begin());
	//printf("!! %d %d\n",Tnow,Fnow);
}
void Goin()
{
//	puts("Goin");
	if (dir==0)
	{
		Tnow+=(LL)OutUp.begin()->first-Fnow;
		Fnow=OutUp.begin()->first;
		PUp--;
		if (P[OutUp.begin()->second].f>=Fnow) InUp.insert(mp(P[OutUp.begin()->second].f,OutUp.begin()->second)),PUp++;
		else InDown.insert(mp(P[OutUp.begin()->second].f,OutUp.begin()->second)),PDown++;
		OutUp.erase(OutUp.begin());
	}
	else
	if (dir==1)
	{
		Tnow+=(LL)Fnow-OutDown.begin()->first;
		Fnow=OutDown.begin()->first;
		PDown--;
		if (P[OutDown.begin()->second].f>=Fnow) InUp.insert(mp(P[OutDown.begin()->second].f,OutDown.begin()->second)),PUp++;
		else InDown.insert(mp(P[OutDown.begin()->second].f,OutDown.begin()->second)),PDown++;
		OutDown.erase(OutDown.begin());
	}
	dir=PDown>PUp;
}
void Leave()
{
//	puts("Leave");
	if (dir==0)
	{
		Tnow+=(LL)InUp.begin()->first-Fnow;
		Fnow=InUp.begin()->first;
		ans[InUp.begin()->second]=Tnow;
		PUp--;
		InUp.erase(InUp.begin());
		Finish++;
	}
	else
	if (dir==1)
	{
		Tnow+=(LL)Fnow-InDown.begin()->first;
		Fnow=InDown.begin()->first;
		ans[InDown.begin()->second]=Tnow;
		PDown--;
		InDown.erase(InDown.begin());
		Finish++;
	}
	dir=PDown>PUp;
	if (PDown==0 && PUp==0) dir=-1;
}
int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d%d%d",&P[i].t,&P[i].s,&P[i].f),unk.insert(mp(P[i].t,i));
	dir=-1,Tnow=0,Fnow=1;
	while (Finish<n)
	{
		int nxt1=INF,nxt2=INF,nxt3=INF;
		if (unk.size()) nxt1=unk.begin()->first-Tnow;
		if (dir==0)
		{
			//printf("-- %d %d\n",OutUp.begin()->first,Fnow);
			if (OutUp.size()) nxt2=min(nxt2,OutUp.begin()->first-Fnow);
			if (InUp.size()) nxt3=min(nxt3,InUp.begin()->first-Fnow);
			if (OutDown.size() && Fnow-OutDown.begin()->first==0) nxt2=min(nxt2,Fnow-OutDown.begin()->first),dir=1;
			if (InDown.size() && Fnow-InDown.begin()->first==0) nxt3=min(nxt3,Fnow-InDown.begin()->first),dir=1;
		}
		//printf("%d %d %d\n",nxt1,nxt2,nxt3);
		if (dir==1)
		{
			if (OutDown.size()) nxt2=min(nxt2,Fnow-OutDown.begin()->first);
			if (InDown.size()) nxt3=min(nxt3,Fnow-InDown.begin()->first);
			if (OutUp.size() && OutUp.begin()->first-Fnow==0) nxt2=min(nxt2,OutUp.begin()->first-Fnow),dir=0;
			if (InUp.size() && InUp.begin()->first-Fnow==0) nxt3=min(nxt3,InUp.begin()->first-Fnow),dir=0;
		}
		//if (nxt1==INF && nxt2==INF && nxt3==INF) {puts("fail");return 0;}
		if (nxt1<=nxt2 && nxt1<=nxt3) Wait();
		else if (nxt2<=nxt1 && nxt2<=nxt3) Goin();
		else Leave();
		//printf("%d %d    time %d  floor %d   %d      PUp %d  PDown %d\n",Finish,n,Tnow,Fnow,dir,PUp,PDown);
		//puts("");
	}
	rep(i,1,n) printf("%I64d\n",ans[i]);
}

