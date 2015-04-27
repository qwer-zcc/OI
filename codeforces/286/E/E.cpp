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
#define rep(i,a,b) for (int i=a;i<b;i++)
#define Rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define pb push_back
#define mp make_pair
#define Pi M_PI
using namespace std;
const int N=2200000;
const double pjd=1e-8;
char ch;
struct point
{
	double a,b;
	point() {}
	point(D _a,D _b) : a(_a),b(_b) {}
}w[N],A[N],C[N],tmp[N];
int l1,l2,a[N],ans[N],NN,m,n,nn,val[N],vis[N];
int Ans[N],al,gs=0;
point operator+(const point &a,const point &b) {return point(a.a+b.a,a.b+b.b);}
point operator*(const point &a,const point &b) {return point(a.a*b.a-a.b*b.b,a.a*b.b+a.b*b.a);}
void fft(point *const &u,int v)
{
    int p=1<<v,q=1<<(m-v),t=(q>>1)-1;
    if (p==NN) return;
    fft(u,v+1);fft(u+p,v+1);
    rep(i,0,q)
    {
        int c=((i&t)<<(v+1));
        tmp[i]=u[c+p]*w[i<<v]+u[c],gs++;
    }
    rep(i,0,q) u[i<<v]=tmp[i];
}
int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d%d",&n,&nn);
	Rep(i,1,n) scanf("%d",&val[i]),a[val[i]]=1,vis[val[i]]=1;
	int l1=l2=nn+1;
	int l=l1+l2,N=1;
    while (N<l) N<<=1,m++;
	NN=N;
    w[0].a=1;w[0].b=0;
    w[1].a=cos((D)-(Pi)/(N/2.));w[1].b=sin((D)-(Pi)/(N/2.));
    rep(i,2,N) w[i]=w[1]*w[i-1];
    rep(i,0,l1) A[i].a=1.0*a[i];
    fft(A,0);
    rep(i,0,N) C[i]=A[i]*A[i];
    rep(i,0,N) w[i].b=-w[i].b;
    fft(C,0);
    rep(i,0,N) C[i].a=C[i].a/(D)N;
    rep(i,0,N) ans[i]=int(C[i].a+0.5);
    Rep(i,1,nn)
    if (!vis[i] && ans[i]) {puts("NO");return 0;}
    Rep(i,1,nn)
    if (vis[i] && !ans[i]) Ans[++al]=i;
    puts("YES");
    printf("%d\n",al);
    Rep(i,1,al) printf("%d ",Ans[i]);
}
