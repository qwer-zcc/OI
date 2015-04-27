#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <complex>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
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
const int Mod=786433;
const int N=131072;
const int G=10;
int limit,W[2][220000];
LL Pow(LL a,int k) {LL b=1;for(;k;k>>=1,a=a*a%Mod) if (k&1) b=b*a%Mod;return b;}
namespace fft
{
	int cp1[1<<21],cp2[1<<21];
	int R[1<<21],V=0;
	void rev(int* a,int n)
	{
		rep(i,0,n-1) if (R[i]<i) swap(a[R[i]],a[i]);
	}
	void dft(int* a,int n,int flag)
	{
		int wi,w,u,v;
		rev(a,n);
		for (int m=2;m<=n;m<<=1)
		{
			int wi=n/m;
			for (int j=0;j<n;j+=m)
			{
				w=0;
				for (int k=j,k2=j+m/2;k2<j+m;k++,k2++)
					u=a[k],v=(LL)W[flag][w]*a[k2]%Mod,a[k]=(u+v)%Mod,a[k2]=(u-v+Mod)%Mod,w+=wi;
			}
		}
		if (flag)
		{
			int x=Pow(n,Mod-2);
			rep(i,0,n-1) a[i]=(LL)a[i]*x%Mod;
		}
	}
	void init(int n)
	{
		W[0][0]=W[1][0]=1;
		for (int i=1,x=Pow(G,(Mod-1)/n),y=Pow(x,Mod-2);i<=n;i++)
			W[0][i]=(LL)x*W[0][i-1]%Mod,W[1][i]=(LL)y*W[1][i-1]%Mod;
	}
	vector<int> solve(vector<int> a,vector<int> b)
	{
		int n=min(int(a.size()+b.size()+1),N);
		int l=1,cnt=0;
		while (l<n) l<<=1,cnt++;
		if (!V) init(l),V=1;
		rep(i,0,l-1) cp1[i]=cp2[i]=0;
		rep(i,0,l-1)
		{
			R[i]=0;
			rep(j,0,cnt-1) R[i]=(R[i]<<1)+((i>>j)&1);
		}
		for (int i=0;i<a.size();i++) cp1[i]=a[i];
		for (int i=0;i<b.size();i++) cp2[i]=b[i];
		dft(cp1,l,0);dft(cp2,l,0);
		rep(i,0,l-1) cp1[i]=(LL)cp1[i]*cp2[i]%Mod;
		dft(cp1,l,1);
		vector<int> ans;ans.clear();
		rep(i,0,n)
		{
			ans.pb(cp1[i]%Mod);
			if (ans.size()==limit) break;
		}
		return ans;
	}
}
int n,m;
vector<int> f[20];
void update(int x)
{
	while (f[x].size()<=n) f[x].pb(0);
}
void down(int x)
{
	vector<int> p;p.clear();p.pb(0);
	for (int i=0;i<f[x].size()-1;i++) p.pb(f[x][i]);
	f[x]=p;
}
vector<int> operator *(int x,vector<int> a)
{
	for (int i=0;i<a.size();i++) a[i]=(a[i]*x)%Mod;
	return a;
}
vector<int> operator +(vector<int> a,vector<int> b)
{
	for (int i=0;i<a.size();i++) a[i]=(a[i]+b[i])%Mod;
	return a;
}
int main()
{
	freopen("avl.in","r",stdin);
	freopen("avl.out","w",stdout);
	scanf("%d%d",&n,&m);limit=n+1;
	f[0].pb(0);f[0].pb(1);
	f[1].pb(0);f[1].pb(0);f[1].pb(2);f[1].pb(1);
	update(0);update(1);
	rep(i,2,m)
	{
		f[i]=fft::solve(f[i-1],f[i-1])+2*fft::solve(f[i-2],f[i-1]);
		update(i);down(i);
	}
	printf("%d\n",f[m][n]);
}
