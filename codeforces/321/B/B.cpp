//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 02/11/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF ((~0U>>1)-3)
#define LLINF (~0ULL>>1)
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
multiset<int,greater<int> > def,me,Me;
multiset<pair<int,int>,greater<pair<int,int> > > atk;
multiset<int,greater<int> >::iterator It;
multiset<int> Atk,Def;
int n,m,x,ans;
char s[100];
int work()
{
	int ans=0;
	while (Atk.size() && Me.size())
	{
		if (*Me.begin()<*Atk.begin()) break;
		ans+=*Me.begin()-*Atk.begin();
		Me.erase(Me.begin());
		Atk.erase(Atk.begin());
	}
	return ans;
}
int main()
{
	//freopen("B.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n)
	{
		scanf("%s%d",s,&x);
		if (s[0]=='A') atk.insert(mp(x,0)),Atk.insert(x);
		else if (s[0]=='D') atk.insert(mp(x,1)),Def.insert(x);
	}
	rep(i,1,m) scanf("%d",&x),me.insert(x),Me.insert(x);
	while (me.size() && atk.size())
	{
		if (atk.begin()->second==0)
		{
			if (*me.begin()>=atk.begin()->first)
			{
				ans+=*me.begin()-atk.begin()->first;
				atk.erase(atk.begin());
				me.erase(me.begin());
				continue;
			}
			else break;
		}
		else
		{
			It=me.lower_bound(atk.begin()->first);
			if (It==me.begin()) break;
			It--;
			atk.erase(atk.begin());
			me.erase(It);
		}
	}
	if (!atk.size())
	{
		while (me.size())
		{
			ans+=*me.begin();
			me.erase(me.begin());
		}
	}
	ans=max(ans,work());
	printf("%d\n",ans);
}

