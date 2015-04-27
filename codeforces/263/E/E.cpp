#include <bits/stdc++.h>
int n,m,k,s[1100][1100],i,j,l,S,ax,ay,p,q,A;
int main()
{
	std::cin>>n>>m>>k;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)std::cin>>S,s[i+j-1][i-j+m]=S;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	for(i=k;i<n+2-k;i++)for(j=k;j<m+2-k;j++)
	{
		S=0;p=i+j-1,q=i-j+m;
		for(l=0;l<k;l++)S=s[p+l][q+l]-s[p-l-1][q+l]-s[p+l][q-l-1]+s[p-l-1][q-l-1];
		if(S>A)A=S,ax=i,ay=j;
	}
	printf("%d %d",ax,ay);
}

