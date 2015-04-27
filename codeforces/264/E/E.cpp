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
const int Slen=300000,N=310000;
struct Segment_Tree
{
	int t[(Slen+100000)<<3],Ty;
	void add(int w,int l,int c,int u=1,int v=Slen)
	{
		if (u==v) {t[w]=c;return;}
		int mid=u+v>>1;
		if (l<=mid) add(w<<1,l,c,u,mid);
		else add(w<<1|1,l,c,mid+1,v);
		t[w]=max(t[w<<1],t[w<<1|1]);
	}
	int ask(int w,int l,int r,int u=1,int v=Slen)
	{
		if (l>r) return 0;
		if (l==u && r==v) return t[w];
		int mid=u+v>>1;
		if (r<=mid) return ask(w<<1,l,r,u,mid);
		else if (l>mid) return ask(w<<1|1,l,r,mid+1,v);
		else return max(ask(w<<1,l,mid,u,mid),ask(w<<1|1,mid+1,r,mid+1,v));
	}
}Seg1,Seg2;
pair<int,int> F[10];
set<int> In,All;
int Fl,val[N],Ti,dp[N],n,G[N],a[N];
void Seg2_add(int x,int c)
{
	if (In.size()<=10) return;
	int p=1,flag=0;
	set<int>::iterator It;
	for (It=In.begin();It!=In.end() && p<=10;p++,It++)
		if (*It>=x) flag=1;
	if (flag) Seg2.add(1,val[*It],dp[*It]);
	else Seg2.add(1,val[x],c);
}
void Plant(int x,int y)
{
	All.insert(x);
	val[x]=y+210000-Ti;
	rep(i,1,Fl) F[i].second++;
	if (!Fl) F[++Fl]=mp(x,y);
	else
	{
		if (y>F[Fl].second) F[++Fl]=mp(x,y);
		else
		{
			int il=0;
			rep(i,1,Fl) if (y>F[i].second) {il=i;break;}
			Fl++;
			drep(i,Fl,il+2) F[i]=F[i-1];
			F[il+1]=mp(x,y);
		}
	}
	while (F[Fl].second==11)
	{
		Seg1.add(1,F[Fl].first,dp[F[Fl].first]=Seg1.ask(1,F[Fl].first+1,n)+1);
		In.insert(F[Fl].first);
		Seg2_add(F[Fl].first,dp[F[Fl].first]);
		Fl--;
	}
}
void Cut(int x)
{
	rep(i,1,Fl) F[i].second++;
	if (F[Fl].second==11)
	{
		Seg1.add(1,F[Fl].first,dp[F[Fl].first]=Seg1.ask(1,F[Fl].first+1,n)+1);
		In.insert(F[Fl].first);
		Seg2_add(F[Fl].first,dp[F[Fl].first]);
		Fl--;
	}
	int T=1,flag=0;
	set<int>::iterator It;
	for (It=All.begin();T<=x-1;It++,T++) ;
	rep(i,1,Fl)
	if (F[i].first==*It)
	{
		rep(j,i,Fl-1) F[j]=F[j+1];
		Fl--;
		flag=1;
		break;
	}
	if (!flag) dp[*It]=0,Seg1.add(1,*It,0),In.erase(*It);
	All.erase(It);
	int now=1,Gl=0;
	for (It=In.begin();It!=In.end() && now<=10;now++,It++) G[++Gl]=*It;
	if (Gl==10) Seg2.add(1,val[G[Gl]],0);
	drep(i,Gl,1)
	{
		a[i]=Seg2.ask(1,val[G[i]]+1,Slen)+1;
		rep(j,i+1,Gl)
		if (val[G[j]]>=val[G[i]]) a[i]=max(a[i],a[j]+1);
		dp[G[i]]=a[i];
		Seg1.add(1,G[i],a[i]);
	}
}
int m,ty,x,y;
inline int cmp1(pair<int,int> a,pair<int,int> b){return a.first<b.first;}
inline int cmp2(pair<int,int> a,pair<int,int> b){return a.second<b.second;}
int main()
{
	//freopen("E.in","r",stdin);
	//freopen("E.out","w",stdout);
	scanf("%d%d",&n,&m);Seg1.Ty=1,Seg2.Ty=2;
	rep(_,1,m)
	{
		Ti=_;
		scanf("%d",&ty);
		if (ty==1) {read(x),read(y);Plant(x,y);}
		else {read(x);Cut(x);}
		
		int ans=Seg1.ask(1,1,n);
		sort(F+1,F+Fl+1,cmp1);
		drep(i,Fl,1)
		{
			a[i]=Seg1.ask(1,F[i].first+1,n)+1;
			rep(j,i+1,Fl)
			if (F[i].second<=F[j].second) a[i]=max(a[i],a[j]+1);
			ans=max(ans,a[i]);
		}
		sort(F+1,F+Fl+1,cmp2);
		printf("%d\n",ans);
	}
}
