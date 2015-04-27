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
const int N=120000;
stack<int> rem,space;
int n,la,lb,L,val[N],pos[N],ty[N],id;
void let_in(int x)
{
	if (x==la-1) {la-=2;return;}
	if (ty[val[la-1]]==2)
	{
		printf("M %d %d\n",la-1,x);
		pos[val[la-1]]=x;
		val[x]=val[x+1]=val[la-1];
		val[la-1]=val[la]=0;
		la-=2;
	}
	else if (ty[val[la-1]]==1 && ty[val[la]]==1)
	{
		printf("M %d %d\n",la-1,x);
		printf("M %d %d\n",la,x+1);
		pos[val[la-1]]=x;
		val[x]=val[la-1];
		pos[val[la]]=x+2;
		val[x+1]=val[la];
		la-=2;
	}
	else if (ty[val[la-1]]==1)
	{
		printf("M %d %d\n",la-1,x);
		pos[val[la-1]]=x;
		val[x]=val[la-1];val[x+1]=0;
		val[la-1]=val[la]=0;
		la-=2;
	}
}
int main()
{
	freopen("I.in","r",stdin);
	scanf("%d",&L);la=0,lb=L+1;
	for(;;fflush(stdout))
	{
		scanf("%d",&n);
		if (n==0) break;
		++id;
		if (n==1)
		{
			ty[id]=1;
			if (rem.size())
			{
				int x=rem.top();rem.pop();
				pos[id]=x+1;
				val[x+1]=id;
				printf("A %d\n",x+1);
			}
			else
			{
				++la;
				pos[id]=la;
				val[la]=id;
				if (la&1) rem.push(la);
				printf("A %d\n",la);
				++la;
			}
			continue;
		}
		if (n==2)
		{
			ty[id]=2;
			++la;
			pos[id]=la;
			val[la]=val[la+1]=id;
			printf("A %d\n",la);
			++la;
			continue;
		}
		if (n==3)
		{
			ty[id]=3;
			lb-=3;
			printf("A %d\n",lb);
			pos[id]=lb;
			if (val[lb]||val[lb+1]||val[lb+2]) while(1);
			val[lb]=val[lb+1]=val[lb+2]=id;
			continue;
		}
		n=-n;int x=pos[n];
		if (ty[n]==1)
		{
			if (x&1)
			{
				if (ty[val[x+1]]==1)
				{
					printf("M %d %d\n",x+1,x);
					val[x]=val[x+1];
					val[x+1]=0;
					pos[val[x]]=x;
					rem.push(x);
				}
				else if (!val[x+1])
				{
					val[x]=0;
					let_in(x);
				}
			}
			else
			{
				if (ty[val[x-1]]==1)
				{
					val[x]=0;
					rem.push(x-1);
				}
				else if (!val[x-1])
				{
					val[x]=0;
					let_in(x);
				}
			}
		}
		else if (ty[n]==2)
		{
			val[x]=val[x+1]=0;
			let_in(x);
		}
		else if (ty[n]==3)
		{
			if (x!=lb)
			{
				printf("M %d %d\n",lb,x);
				val[x]=val[x+1]=val[x+2]=val[lb];
				val[lb]=val[lb+1]=val[lb+2]=0;
				lb+=3;
			}
			else val[x]=val[x+1]=val[x+2]=0,lb+=3;
		}
		puts("D");pos[n]=0;
	}
}
