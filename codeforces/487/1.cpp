#include<stdio.h>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
const int maxn=100050,maxm=maxn,INF=0x7fffffff;
int n,m,q,w[maxn];
int es=0,he[maxn],ne[maxm*2],to[maxm*2];
int dfn[maxn],low[maxn],tim=0;
int bel[maxn],bs=0,cut[maxn];
bool is_cut[maxn];
multiset<int> ww[maxn];
pii st[maxn];
int tp=0;
map<pii,int> e;
int es2=0,he2[maxn],ne2[maxn*2],to2[maxn*2];
int dep[maxn],fa[maxn],siz[maxn],son[maxn],top[maxn],pos[maxn],ps=0;
int ts=0,l[maxn*2],r[maxn*2],mn[maxn*2],v[maxn];
void ins(int x,int y)
{
	ne[++es]=he[x],he[x]=es,to[es]=y;
}
void ins2(int x,int y)
{
	ne2[++es2]=he2[x],he2[x]=es2,to2[es2]=y;
}
void dfs(int x,int f)
{
	int i,y;
	st[++tp]=mp(f,x);
	dfn[x]=low[x]=++tim;
	for(i=he[x];i;i=ne[i])
		if((y=to[i])!=f)
		{
			if(!dfn[y])
			{
				dfs(y,x);
				if(low[y]>=dfn[x])
				{
					is_cut[cut[++bs]=x]=1;
					do
					{
						bel[st[tp].x]=bel[st[tp].y]=bs;
						tp--;
					}while(st[tp+1].x!=x||st[tp+1].y!=y);
				}
				else low[x]=min(low[x],low[y]);
			}
			else
				low[x]=min(low[x],dfn[y]);
		}
}
void dfs2(int x)
{
	int i,y;
	siz[x]=1;
	for(i=he2[x];i;i=ne2[i])
		if((y=to2[i])!=fa[x])
		{
			fa[y]=x;
			dep[y]=dep[x]+1;
			dfs2(y);
			siz[x]+=siz[y];
		}
	for(i=he2[x];i;i=ne2[i])
		if((y=to2[i])!=fa[x]&&siz[y]*2>=siz[x])
			son[x]=y;
}
void dfs3(int x)
{
	int i,y;
	v[pos[x]=++ps]=x;
	if(son[x]) top[son[x]]=top[x],dfs3(son[x]);
	for(i=he2[x];i;i=ne2[i])
		if((y=to2[i])!=fa[x]&&y!=son[x])
			top[y]=y,dfs3(y);
}
void update(int x) { mn[x]=min(mn[l[x]],mn[r[x]]); }
void build(int x,int ll,int rr)
{
	if(ll==rr) { mn[x]=*ww[v[ll]].begin();return ; }
	int mid=(ll+rr)>>1;
	build(l[x]=++ts,ll,mid);
	build(r[x]=++ts,mid+1,rr);
	update(x);
}
void modify(int x,int ll,int rr,int p)
{
	if(ll==rr) { mn[x]=*ww[v[ll]].begin();return ; }
	int mid=(ll+rr)>>1;
	if(p<=mid)
		modify(l[x],ll,mid,p);
	else 
		modify(r[x],mid+1,rr,p);
	update(x);
}
int query(int x,int ll,int rr,int a,int b)
{
	if(a<=ll&&rr<=b) return mn[x];
	int mid=(ll+rr)>>1,s=INF;
	if(a<=mid)
		s=min(s,query(l[x],ll,mid,a,b));
	if(b>mid)
		s=min(s,query(r[x],mid+1,rr,a,b));
	return s;
}
void modify0(int x,int y)
{
	int xx=bel[x];
	multiset<int>::iterator t=ww[xx].find(w[x]);
	ww[xx].erase(t);
	ww[xx].insert(w[x]=y);
	modify(1,1,ps,pos[xx]);
}
int query0(int x0,int y0)
{
	if(x0==y0) return w[x0];
	if(dep[x0]<dep[y0]) swap(x0,y0);
	int x=bel[x0],y=bel[y0],tx=top[x],ty=top[y],cx=(is_cut[x0]?x0:0),cy=(is_cut[y0]?y0:0),s=INF;
	if(x==y) return min(*ww[x].begin(),w[cut[x]]);
	while(tx!=ty)
	{
		if(dep[tx]<dep[ty]) swap(x,y),swap(tx,ty),swap(cx,cy);
		if(dep[tx]>=dep[ty]) 
		{
			s=min(s,query(1,1,ps,pos[tx],pos[x]));
			cx=cut[tx];
			x=fa[tx];
			tx=top[x];
		}
	}
	if(dep[x]<dep[y]) swap(x,y),swap(cx,cy);
	if(dep[x]>dep[y]) 
	{
		s=min(s,query(1,1,ps,pos[y]+1,pos[x]));
		cx=cut[v[pos[y]+1]];
	}
	if(cx==cy||(y0==cx&&cut[y]!=y0))
		s=min(s,w[cx]);
	else 
		s=min(s,min(*ww[y].begin(),w[cut[y]]));
	return s;
}
int main()
{
	freopen("E.in","r",stdin);
	int i,j,x,y;
	char ci;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(i=0;i<=m;i++)
		scanf("%d%d",&x,&y),ins(x,y),ins(y,x);
	dfs(1,0);
	for(i=1;i<=n;i++) printf("%d ",bel[i]);puts("");
	return 0;
	for(i=1;i<=n;i++)
		for(j=he[i];j;j=ne[j])
		{
			y=to[j];
			int x0=bel[i],y0=bel[y];
			if((y=to[j])&&x0!=y0&&!e.count(mp(x0,y0)))
				ins2(x0,y0),ins2(y0,x0),e[mp(x0,y0)]=e[mp(y0,x0)]=1;
		}
	for(i=1;i<=n;i++)
		ww[bel[i]].insert(w[i]);
	dfs2(bel[1]);
	top[bel[1]]=bel[1];
	dfs3(bel[1]);
	build(++ts,1,ps);
	while(q--)
	{
		ci=getchar();
		while(ci!='A'&&ci!='C') ci=getchar();
		scanf("%d%d",&x,&y);
		if(ci=='A') printf("%d\n",query0(x,y));
		else modify0(x,y);
	}
	return 0;
}
