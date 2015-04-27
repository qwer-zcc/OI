#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn (1<<16)
#define P 786433 //P=C*2^k+1
#define G 10 //P
#define ll long long
using namespace std;

int N,n,m,a[maxn*2],b[maxn*2],W[2][maxn*2],rev[maxn*2],f[16][maxn*2],re[16][maxn*2];

ll Pow(ll a,int b)
{
	ll c=1;
	for (;b; b>>=1,a=a*a%P) if (b&1) c=c*a%P;
	return c;
}

void FFT(int*a,int f)
{
	//printf("        %d\n",N);
	for (int i=0; i<N; i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int i=1; i<N; i<<=1)
		for (int j=0,t=N/(i<<1); j<N; j+=i<<1)
			for (int k=0,l=0,x,y; k<i; k++,l+=t) x=(ll)W[f][l]*a[j+k+i]%P,y=a[j+k],a[j+k]=(y+x)%P,a[j+k+i]=(y-x+P)%P;
	if (f) for (int i=0,x=Pow(N,P-2); i<N; i++) a[i]=(ll)a[i]*x%P;
}

void work()
{
	for (int i=0; i<N; i++)
	{
		int x=i,y=0;
		for (int k=1; k<N; x>>=1,k<<=1) (y<<=1)|=x&1;
		rev[i]=y;
	}
	W[0][0]=W[1][0]=1;
	for (int i=1,x=Pow(G,(P-1)/N),y=Pow(x,P-2); i<N; i++) W[0][i]=(ll)x*W[0][i-1]%P,W[1][i]=(ll)y*W[1][i-1]%P;

}


int main()
{
	freopen("avl.in","r",stdin);
	//freopen("avl.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (!m) printf("%d\n",n==1);
	if (m==1) printf("%d\n",n==2?2:n==3?1:0);
	if (m<2) return 0;
	f[0][1]=1;
	f[1][2]=2,f[1][3]=1;
	N=131072;work();
	for (int i=2;i<=m;i++) {
		for (int j=0; j<N; j++) a[j]=f[i-1][j];
		FFT(a,0);
		for (int j=0; j<N; j++) b[j]=(ll)a[j]*a[j]%P;
		FFT(b,1);
		for (int j=1; j<=n;j++) f[i][j]=b[j-1];
		for (int j=0; j<N; j++) b[j]=f[i-2][j];
		FFT(b,0);
		for (int j=0; j<N; j++) a[j]=(ll)a[j]*b[j]%P;
		FFT(a,1);
		for (int j=1; j<=n;j++) f[i][j]=(a[j-1]*2+f[i][j])%P;
	}
	//int an=0;
	//for (int i=1;i<n;i++) an=(1ll*f[m-1][i]*f[m-1][n-i-1]+1ll*f[m-1][i]*f[m-2][n-i-1]*2+an)%P;
	printf("%d\n",f[m][n]);
	//for(;;);
	return 0;
}
