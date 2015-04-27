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
const LL Mod=998244353LL;
struct Matrix
{
	LL a[10][10],n,m;
	Matrix() {}
	Matrix(int _n,int _m) : n(_n),m(_m) {rep(i,1,n) rep(j,1,m) a[i][j]=0;}
};
Matrix operator *(Matrix a,Matrix b)
{
	Matrix c=Matrix(a.n,b.m);
	rep(i,1,a.n) rep(j,1,b.m) rep(k,1,a.m)
		c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j]%Mod)%Mod;
	return c;
}
Matrix Pow(Matrix a,int k)
{
	Matrix b=a;k--;
	for(;k;k>>=1){if (k&1) b=b*a;a=a*a;}
	return b;
}
int n;
int main()
{
	freopen("figure.in","r",stdin);
	freopen("figure.out","w",stdout);
	while (scanf("%d",&n)!=EOF && n) {
	Matrix a=Matrix(3,3);
	a.a[1][1]=5;a.a[2][1]=-6;a.a[3][1]=a.a[1][2]=a.a[2][3]=1;
	if (n==1) {puts("1");continue;}
	else if (n==2) {puts("2");continue;}
	else if (n==3) {puts("5");continue;}
	Matrix b=Matrix(1,3);
	b.a[1][1]=5;b.a[1][2]=2;b.a[1][3]=1;
	a=Pow(a,n-3);
	b=b*a;
	printf("%lld\n",(b.a[1][1]%Mod+Mod)%Mod);}
}
