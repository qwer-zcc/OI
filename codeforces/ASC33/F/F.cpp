#include <cstdio>
#include <algorithm>
using namespace std;
int n,x,y,a,b;
int main()
{
	freopen("knights.in","r",stdin);
	freopen("knights.out","w",stdout);
	while (scanf("%d",&n) && n)
	{
		a=b=(int)1e9;
		for(int i=1;i<=n;i++) scanf("%d%d",&x,&y),a=min(a,(x+1)/3),b=min(b,y/3);
		puts(a>b?"Andrew wins the game":"Peter wins the game");
	}
}
