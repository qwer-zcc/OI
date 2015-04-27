//+-------------------------------------+
//|     By   qwer_zcc                   |
//|     Date 12/10/2014                 |
//+-------------------------------------+
#include <bits/stdc++.h>
#define INF ~0U>>1
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
const int N=310000,Mod=1000000007,Base=9999973,NN=150000;
int Pre[N],po[N],cnt,n,m,root[N],dis[N],po2[N],al,Ans[N],pre[N],vis[N],flag,VIS[N];
queue<int> List;
vector<int> E[N],F[N];
struct lj{int c,l,r,len,hash;}t[15000000];
int Chen(int a,int b,int c){return int((LL)a*(LL)b%(LL)c);}
void update(int w,int u,int v)
{
	if (u==v) return;
	int mid=u+v>>1;
	if (!t[w].l && !t[w].r) return;
	if (!t[w].r)
	{
		t[w].hash=t[t[w].l].hash;
		t[w].len=t[t[w].l].len;
	}
	else if (!t[w].l)
	{
		t[w].hash=Chen(t[t[w].r].hash,po[mid-u+1],Base);
		t[w].len=0;
	}
	else
	{
		t[w].hash=(Chen(t[t[w].r].hash,po[mid-u+1],Base)+t[t[w].l].hash)%Base;
		if (t[t[w].l].len==mid-u+1) t[w].len=t[t[w].l].len+t[t[w].r].len;
		else t[w].len=t[t[w].l].len;
	}
}
int ask_len(int p,int l,int r,int u,int v)
{
	if (l==u && r==v) return t[p].len;
	int mid=u+v>>1;
	if (r<=mid) return ask_len(t[p].l,l,r,u,mid);
	else if (l>mid) return ask_len(t[p].r,l,r,mid+1,v);
	else
	{
		int c=ask_len(t[p].l,l,mid,u,mid);
		if (c==mid-l+1) return c+ask_len(t[p].r,mid+1,r,mid+1,v);
		else return c;
	}
}
int Newnode()
{
	return ++cnt;
}
int Cover(int p,int l,int r,int u,int v)
{
	if (l==u && r==v) return 0;
	int k=Newnode();
	t[k]=t[p];
	int mid=u+v>>1;
	if (r<=mid) t[k].l=Cover(t[p].l,l,r,u,mid);
	else if (l>mid) t[k].r=Cover(t[p].r,l,r,mid+1,v);
	else t[k].l=Cover(t[p].l,l,mid,u,mid),t[k].r=Cover(t[p].r,mid+1,r,mid+1,v);
	update(k,u,v);
	return k;
}
void add(int &p,int l,int u,int v)
{
	if (!p) p=Newnode();
	else
	{
		int k=Newnode();
		t[k]=t[p];
		p=k;
	}
	if (u==v) {t[p].c=t[p].hash=t[p].len=1;return;}
	int mid=u+v>>1;
	if (l<=mid) add(t[p].l,l,u,mid);
	else add(t[p].r,l,mid+1,v);
	update(p,u,v);
}
int Cmp(int p,int q,int u,int v)
{
	if (u==v) return t[p].c<t[q].c;
	int mid=u+v>>1;
	if (t[t[p].r].hash!=t[t[q].r].hash) return Cmp(t[p].r,t[q].r,mid+1,v);
	else return Cmp(t[p].l,t[q].l,u,mid);
}
void sc(int x)
{
	printf("(%d)  ",x);
	drep(i,10,1) printf("%d",ask_len(root[x],i,NN,1,NN)>0);puts("");
}
void sc2(int x)
{
	printf("(%d)  ",x);
	drep(i,10,1) printf("%d",ask_len(x,i,NN,1,NN)>0);puts("");
}
void Erase(int p)
{
	if (!p) return;
	List.push(p);
	Erase(t[p].l);
	Erase(t[p].r);
	t[p].l=t[p].r=t[p].len=t[p].c=t[p].hash=0;
}
struct cmp{int operator()(const int &a, const int &b) { return !Cmp(root[a],root[b],1,NN);} };
priority_queue<int,vector<int>,cmp> Q;
int main()
{
	freopen("E.in","r",stdin);
	//freopen("me.out","w",stdout);
	scanf("%d%d",&n,&m);int x,y,z,S,T;
	rep(i,1,m) scanf("%d%d%d",&x,&y,&z),E[x].pb(y),E[y].pb(x),F[x].pb(z),F[y].pb(z);
	scanf("%d%d",&S,&T);
	if (S==T) {printf("0\n1\n%d",S);return 0;}
	po[0]=po2[0]=1;
	rep(i,1,120000) po[i]=Chen(po[i-1],2,Base),po2[i]=Chen(po2[i-1],2,Mod);
	
	Q.push(S);
	while (Q.size())
	{
		int x=Q.top();Q.pop();vis[x]=1;
		for (int i=0;i<E[x].size();i++)
		{
			int CCnt=cnt,Len=ask_len(root[x],F[x][i]+1,NN,1,NN),Rt;
			if (Len>0)
			{
				Rt=Cover(root[x],F[x][i]+1,F[x][i]+Len,1,NN);
				add(Rt,F[x][i]+Len+1,1,NN);
			}
			else
			{
				Rt=root[x];
				add(Rt,F[x][i]+1,1,NN);
			}
			if ((E[x][i]!=S && !root[E[x][i]]) || Cmp(Rt,root[E[x][i]],1,NN))
			{
				dis[E[x][i]]=(dis[x]+po2[F[x][i]])%Mod;
				root[E[x][i]]=Rt;
				pre[E[x][i]]=x;
				Pre[E[x][i]]=F[x][i];
				if (!vis[E[x][i]]) Q.push(E[x][i]);
			}
			else
			{
				rep(_,CCnt+1,cnt) t[_].l=t[_].r=t[_].len=t[_].c=t[_].hash=0;
				cnt=CCnt;
			}
		}
	}
	int DIS=0;
	if (!dis[T]) {puts("-1");return 0;}
	Ans[++al]=T;
	while (pre[T]) DIS=(DIS+po2[Pre[T]])%Mod,T=pre[T],Ans[++al]=T;
	printf("%d\n",DIS);
	printf("%d\n",al);
	drep(i,al,2) printf("%d ",Ans[i]);printf("%d\n",Ans[1]);
}

