#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;

const int MAXM=1e8;
bool x[2*MAXM+1];
char a[5][2][5],*b;

int main()
{
	freopen("B.in","r",stdin);
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	int i,j,t;
	for(i=0;i<5;i++)
		for(j=0;j<2;j++)
			scanf("%s",a[i][j]);
	for(j=MAXM,i=t=0;t<MAXM;t++)
	{
		b=a[i][x[j]];
		x[j]=b[0]-'0';
		j=j+(b[1]=='L'?-1:1);
		i=b[2]-'A';
		if(i>5)
			return puts("happy beaver");
	}
	puts("unhappy beaver");
	return 0;
}
