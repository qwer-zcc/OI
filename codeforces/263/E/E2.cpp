#include<bits/stdc++.h>
#define R(i,a,b) for(int i=a;i<=b;i++)
template<class T> void read(T &x)
{
	char ch;
	while ((ch=getchar())&&!isdigit(ch));x=ch-'0';
	while ((ch=getchar())&&isdigit(ch)) x=x*10+ch-'0';
}
int n,m,k,ax,ay,p,q;
long long s[2100][2100],A=-1,S;
int main()
{
	read(n);read(m);read(k);
	R(i,1,n)R(j,1,m)read(p),s[i+j-1][i-j+m]=p;
	R(i,1,n+m-1)R(j,1,m+n-1)s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	R(i,k,n+1-k)R(j,k,m+1-k)
	{
		S=0;p=i+j-1,q=i-j+m;
		R(l,0,k-1)S+=s[p+l][q+l]-s[p-l-1][q+l]-s[p+l][q-l-1]+s[p-l-1][q-l-1];
		if(S>A)A=S,ax=i,ay=j;
	}
	printf("%d %d",ax,ay);
}

