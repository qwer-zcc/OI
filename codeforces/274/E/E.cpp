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
set<pair<int,int> > F_s[N],S_s[N];
set<pair<int,int> >::iterator It1;
set<pair<int,int>,greater<pair<int,int> > > F_b[N],S_b[N];
set<pair<int,int>,greater<pair<int,int> > >::iterator It2;
map<pair<int,int> , bool>Hash;
LL ans=1;
int n,m,Sx,Sy;
int Get_dir(char s[])
{
	if (s[0]=='N' && s[1]=='E') return 0;
	else if (s[0]=='N' && s[1]=='W') return 1;
	else if (s[0]=='S' && s[1]=='W') return 2;
	else return 3;
}
int Flag;
int vis(int x,int y) {return Hash.count(mp(x,y));}
void add(int x,int y)
{
	Hash[mp(x,y)]=1;
	F_s[x+y].insert(mp(x,y)),F_b[x+y].insert(mp(x,y));
	S_s[x-y+m+1].insert(mp(x,y)),S_b[x-y+m+1].insert(mp(x,y));
}
int dis(pair<int,int> a,pair<int,int> b)
{
	assert(abs(a.first-b.first)==abs(a.second-b.second));
	//printf("%d %d   %d %d\n",a.first,a.second,b.first,b.second);
	return abs(a.first-b.first);
}
int In_line(pair<int,int> x,pair<int,int> a,pair<int,int> b)
{
	int X=x.first,x1=a.first,x2=b.first,y1=a.second,y2=b.second;
	if (!(x.first>=min(a.first,b.first) && x.first<=max(a.first,b.first))) return 0;
	return (x.second-y1)*(x2-x1)==(X-x1)*(y2-y1);
}
pair<pair<int,int>,int> Get_nxt(pair<int,int> Now,int dir)
{
	int ax,ay,V1,V2;
	if (!dir)
	{
		It2=F_b[Now.first+Now.second].lower_bound(mp(Now.first,Now.second));
		ax=It2->first,ay=It2->second;
		V1=vis(ax,ay-1),V2=vis(ax+1,ay);
		if (Now!=mp(Sx,Sy) && In_line(mp(Sx,Sy),Now,mp(ax,ay)))
		{
			Flag=2;
			ans+=(LL)dis(Now,mp(Sx,Sy))-1;
			return mp(mp(0,0),dir);
		}
		else ans+=dis(Now,mp(ax+1,ay-1));
		if (!V1 && !V2) return Flag=1,mp(mp(ax+1,ay-1),2);
		if (V1 && !V2) return mp(mp(ax+1,ay),3);
		if (!V1 && V2) return mp(mp(ax,ay-1),1);
		return Flag=1,mp(mp(ax+1,ay-1),2);
	}
	else if (dir==1)
	{
		It2=S_b[Now.first-Now.second+m+1].lower_bound(mp(Now.first,Now.second));
		ax=It2->first,ay=It2->second;
		V1=vis(ax+1,ay),V2=vis(ax,ay+1);
		if (Now!=mp(Sx,Sy) && In_line(mp(Sx,Sy),Now,mp(ax,ay)))
		{
			Flag=2;
			ans+=(LL)dis(Now,mp(Sx,Sy))-1;
			return mp(mp(0,0),dir);
		}
		else ans+=dis(Now,mp(ax+1,ay+1));
		if (!V1 && !V2) return Flag=1,mp(mp(ax+1,ay+1),3);
		if (V1 && !V2) return mp(mp(ax,ay+1),0);
		if (!V1 && V2) return mp(mp(ax+1,ay),2);
		return Flag=1,mp(mp(ax+1,ay+1),3);
	}
	else if (dir==2)
	{
		It1=F_s[Now.first+Now.second].lower_bound(mp(Now.first,Now.second));
		ax=It1->first,ay=It1->second;
		
		V1=vis(ax-1,ay),V2=vis(ax,ay+1);
		if (Now!=mp(Sx,Sy) && In_line(mp(Sx,Sy),Now,mp(ax,ay)))
		{
			Flag=2;
			ans+=(LL)dis(Now,mp(Sx,Sy))-1;
			return mp(mp(0,0),dir);
		}
		else ans+=dis(Now,mp(ax-1,ay+1));
		if (!V1 && !V2) return Flag=1,mp(mp(ax-1,ay+1),0);
		if (V1 && !V2) return mp(mp(ax,ay+1),3);
		if (!V1 && V2) return mp(mp(ax-1,ay),1);
		return Flag=1,mp(mp(ax-1,ay+1),0);
	}
	else
	{
		It1=S_s[Now.first-Now.second+m+1].lower_bound(mp(Now.first,Now.second));
		ax=It1->first,ay=It1->second;
		V1=vis(ax-1,ay),V2=vis(ax,ay-1);
		if (Now!=mp(Sx,Sy) && In_line(mp(Sx,Sy),Now,mp(ax,ay)))
		{
			Flag=2;
			ans+=(LL)dis(Now,mp(Sx,Sy))-1;
			return mp(mp(0,0),dir);
		}
		else ans+=dis(Now,mp(ax-1,ay-1));
		if (!V1 && !V2) return Flag=1,mp(mp(ax-1,ay-1),1);
		if (V1 && !V2) return mp(mp(ax,ay-1),2);
		if (!V1 && V2) return mp(mp(ax-1,ay),0);
		return Flag=1,mp(mp(ax-1,ay-1),1);
	}
}
int k,x,y,VIS[10];
char s[6];
int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,k) scanf("%d%d",&x,&y),add(x,y);
	rep(i,1,m) add(n+1,i),add(0,i);
	rep(i,1,n) add(i,m+1),add(i,0);
	add(n+1,m+1);add(0,0);add(0,m+1);add(n+1,0);
	scanf("%d%d%s",&Sx,&Sy,s);
	pair<int,int> Now=mp(Sx,Sy);
	int dir=Get_dir(s),Fdir;
	while (!VIS[dir])
	{
		VIS[dir]=1;
		Flag=0;Fdir=dir;
		ans--;
		while (1)
		{
			pair<pair<int,int>,int> T=Get_nxt(Now,dir);
			pair<int,int> Nxt=T.first;
			Now=Nxt;dir=T.second;
			ans++;
			if (Nxt==mp(Sx,Sy)) break;
			if (Flag==1)
			{
				Now=mp(Sx,Sy);
				dir=(Fdir+2)%4;
				break;
			}
			if (Flag==2) break;
			//printf("a = %lld\n",ans);
		}
		//printf("ans = %lld\n",ans);
	}
	printf("%lld\n",ans);
}

