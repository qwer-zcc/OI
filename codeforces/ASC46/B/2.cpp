#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int C[101][101],M[101],F[101],p=175781251,pow3[100001];
int main() {
	//freopen("bipartite.in","r",stdin), freopen("bipartite.out","w",stdout);
	pow3[0]=1;
	for(int i=1;i<=100000;++i)pow3[i]=(pow3[i-1]*3)%p;
	F[0]=M[0]=C[0][0]=1;
	for (int n=1;n <=10; ++n) {
		C[n][0]=1;
		for (int i=1;i<=n;++i)C[n][i]=(C[n-1][i-1]+C[n-1][i])%p;
		for(int i=0;i<=n;++i)M[n]=(M[n]+1LL*C[n][i]*pow3[i*(n-i)])%p;
		for (int i=1;i<n;++i)F[n]=(F[n]+1LL*C[n-1][i]*F[i]%p*F[n-i])%p;
		F[n]=(1LL*M[n]*87890626%p-F[n]+p)%p;
		printf("%d %d\n",F[n],M[n]);
	}
	return 0;
	while(cin>>p,p) cout<<F[p]<<endl;
}
