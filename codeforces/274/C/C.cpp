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
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define pb push_back
#define mp make_pair
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
template<class T> void read(T &x)
{
    char ch;
    while ((ch=getchar()) && !isdigit(ch));x=ch-'0';
    while ((ch=getchar()) && isdigit(ch)) x=x*10+ch-'0';
}
const D DINF=1e30,eps=1e-7;
const int N=200;
struct point
{
    D x,y;
    point() {}
    point(D _x,D _y) : x(_x),y(_y) {}
} P[N];
struct Line
{
	D k,b;
	Line() {}
	Line(D _k,D _b) : k(_k),b(_b) {}
} ;
int n;
map<pair<int,int>,int> Hash;
D Ans=-1;
point operator -(point a,point b) {return point(a.x-b.x,a.y-b.y);}
point operator +(point a,point b) {return point(a.x+b.x,a.y+b.y);}
D operator ^(point a,point b) {return a.x*b.x+a.y*b.y;}
void sc_point(point a)
{
	printf("point %.3lf %.3lf\n",a.x,a.y);
}
D check_acute(point a,point b,point c)
{
	//   a->b  µã»ý   a->c 
	point X=b-a,Y=c-a;
	if (X.x*Y.y==X.y*Y.x) return -1;
	return X^Y;
}
D Dis(point a,point b) {return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
Line Get_Line(point a,point b)
{
	if (a.x==b.x) return Line(INF,a.x);
	else
	{
		D k=(b.y-a.y)/(b.x-a.x);
		return Line(k,a.y-a.x*k);
	}
}
Line Change_k(Line a)
{
	if (a.k==INF) return Line(0,a.b);
	else if (a.k==0) return Line(INF,a.b);
	else return Line(-1/a.k,a.b);
}
Line Change_b(Line a,point b)
{
	if (a.k==INF) return Line(a.k,b.x);
	else if (a.k==0) return Line(a.k,b.y);
	else return Line(a.k,b.y-a.k*b.x);
}
point Get_point(Line x,Line y)
{
	if (x.k>y.k) swap(x,y);
	if (y.k==INF) return point(y.b,x.k*y.b+x.b);
	if (x.k==0) return point((x.b-y.b)/(y.k) , x.b);
	if (y.k==0) return point((y.b-x.b)/(x.k) , y.b);
	D a=x.k,b=x.b,c=y.k,d=y.b;
	return point( ((a*d-b*c)/(a-c)-b)/a , (a*d-b*c)/(a-c));
}
point Find_Ct(point a,point b,point c)
{
	point d=point((a.x+b.x)/2.,(a.y+b.y)/2.),
		  e=point((a.x+c.x)/2.,(a.y+c.y)/2.);
	Line lab=Get_Line(a,b),lac=Get_Line(a,c);
	lab=Change_k(lab);lac=Change_k(lac);
	lab=Change_b(lab,d);lac=Change_b(lac,e);
	return Get_point(lab,lac);
}
void update(point a,point b,point c)
{
	point d=c+(b-a),Ct;
	if (Hash[mp(d.x,d.y)])
	{
		Ct=point((b.x+c.x)/2.,(b.y+c.y)/2.);
		D ans=DINF;
		rep(l,1,n) ans=min(ans,Dis(Ct,P[l]));
		if (ans>=Dis(Ct,a)-eps) Ans=max(Ans,ans);
	}
}
int main()
{
	//freopen("C.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n) scanf("%lf%lf",&P[i].x,&P[i].y),Hash[mp(P[i].x,P[i].y)]=1;
	rep(i,1,n) rep(j,i+1,n) rep(k,j+1,n)
	{
		D ca=check_acute(P[i],P[j],P[k]),cb=check_acute(P[j],P[i],P[k]),cc=check_acute(P[k],P[i],P[j]);
		if (!(ca<eps||cb<eps||cc<eps))
		{
			point Ct=Find_Ct(P[i],P[j],P[k]);
			D ans=DINF;
			rep(l,1,n) ans=min(ans,Dis(Ct,P[l]));
			if (ans>=Dis(Ct,P[i])-eps) Ans=max(Ans,ans);
		}
		if (-eps<ca && ca<eps) update(P[i],P[j],P[k]);
		if (-eps<cb && cb<eps) update(P[j],P[i],P[k]);
		if (-eps<cc && cc<eps) update(P[k],P[i],P[j]);
	}
	if (Ans<eps && Ans>-eps) puts("-1");
	else printf("%.10lf\n",Ans);
}

