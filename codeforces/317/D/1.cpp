#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int sg[]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
long long x;
int n,m,i,cnt,ans,num,bo[120000];
int main(){
	freopen("1.out","w",stdout);
	//scanf("%d",&n);
	n=19000881;
	m=(int)sqrt(n);
	num=n-m+1;
	for(i=2;i<=m;++i)if(!bo[i]){
		for(cnt=0,x=i;x<=n;x*=i,cnt++){
			if(x<=m)bo[x]=1;
			else num--;
		}
		ans^=sg[cnt];
		printf("%d\n",ans);
	}
	printf("%d %d %d\n",ans,num,m);
	ans^=num&1;
	puts(ans?"Vasya":"Petya");
} 
