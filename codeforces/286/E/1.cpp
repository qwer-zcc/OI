#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define rep(i,a,b) for (int i=a;i<b;i++)
using namespace std;
const int Max=4000;
const double pi=acos(-1);
const double pjd=1e-8;
char ch;
struct lj{double a,b;}w[Max],A[Max],B[Max],C[Max],c[Max],tmp[Max];
int l1,l2,a[Max],b[Max],ans[Max],NN,m;
lj operator+(const lj &a,const lj &b)
{
    lj z;
    z.a=a.a+b.a;z.b=a.b+b.b;
    return z;
}
lj operator*(const lj &a,const lj &b)
{
    lj z;
    z.a=a.a*b.a-a.b*b.b;z.b=a.a*b.b+a.b*b.a;
    return z;
}
lj js(int p,int x,int l,int len,int *a)
{
    lj ans,le,re;
    if (x+l>=len) {ans.a=a[x]*w[(p*x)%NN].a;ans.b=a[x]*w[(p*x)%NN].b;return ans;}
    le=js(p,x,l<<1,len,a);re=js(p,x+l,l<<1,len,a);
    ans.a=le.a+re.a;ans.b=le.b+re.b;
    return ans;
}
void fft(lj *const &u,const int &v)
{
    int p=1<<v,q=1<<(m-v);
    if (p==NN) return;
    fft(u,v+1);fft(u+p,v+1);
    rep(i,0,q)
    tmp[i]=u[((i&((q>>1)-1))<<(v+1))+p]*w[i<<v]+u[(i&((q>>1)-1))<<(v+1)];
    rep(i,0,q) u[i<<v]=tmp[i];
}
int main()
{
	freopen("1.in","r",stdin);
    int l1=0;int l2=0;
    while (scanf("%c",&ch) && ch!='\n') a[l1++]=ch-'0';
    while (scanf("%c",&ch) && ch!='\n') b[l2++]=ch-'0';
    rep(i,0,l1/2) swap(a[i],a[l1-i-1]);
    rep(i,0,l2/2) swap(b[i],b[l2-i-1]);
    int l=l1+l2,N=1;
    while (N<l) N<<=1,m++;NN=N;
    for (int i=N-1;i>=0;i--) printf("%d ",a[i]);puts("");
    w[0].a=1;w[0].b=0;
    w[1].a=cos((double)-(pi)/(N/2));w[1].b=sin((double)-(pi)/(N/2));
    rep(i,2,N) w[i]=w[1]*w[i-1];
    rep(i,0,l1) A[i].a=1.0*a[i]; rep(i,0,l2) B[i].a=1.0*b[i];
    fft(A,0);fft(B,0);
    rep(i,0,N) C[i]=A[i]*B[i];
    rep(i,0,N) w[i].b=-w[i].b;
    fft(C,0);
    rep(i,0,N) C[i].a=C[i].a/N;
    rep(i,0,N) ans[i]=int(C[i].a+0.5);
    while (ans[N-1]==0) N--;
    rep(i,1,N) ans[i]+=ans[i-1]/10,ans[i-1]%=10;
    for (int i=N-1;i>=0;i--) printf("%d",ans[i]);
}
