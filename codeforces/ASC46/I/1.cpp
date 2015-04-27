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
#include <cassert>
using namespace std;

int u[32768],pos[32768],mem[102400],n;
int main(){
	freopen("I.in","r",stdin);
	scanf("%d",&n);u[0]=1;
	for(int _=1,s=0,h=n+1,&e=pos[0],t;;++_,fflush(stdout)){
		scanf("%d",u+_);
		switch(u[_]){
		case 1:
			if(e){
				printf("A %d\n",pos[mem[e]=_]=e);
				e=0;
			}else{
				++s;
				printf("A %d\n",pos[mem[s]=_]=s);
				pos[0]=e=++s;
			}
			break;
		case 2:
			++s;
			printf("A %d\n",pos[mem[s]=_]=s);
			mem[++s]=_;
			break;
		case 3:
			mem[--h]=_;mem[--h]=_;mem[--h]=_;
			printf("A %d\n",pos[_]=h);
			break;
		case 0:exit(0);
		default:
			switch(u[t=-u[_]]){
			case 1:
				if(e){
					e=1+(e-1^1);
					if(e!=pos[t]){
						printf("M %d %d\n",e,pos[mem[e]]=pos[t]);
						mem[pos[t]]=mem[e];
					}
					if(!(e&1))--e;
					if(e!=s-1){
						printf("M %d %d\n",s-1,pos[mem[s]]=e);
						mem[e+1]=mem[e]=mem[s];
					}
					mem[s--]=e=0;mem[s--]=0;
				}else{
					mem[e=pos[t]]=0;pos[t]=0;
					if(s-e>1 && u[mem[s]]==1){
						printf("M %d %d\n",s,pos[mem[s]]=e);
						mem[e]=mem[s];mem[e=s]=0;
					}
				}
				break;
			case 2:
				if(pos[t]+1!=s)
				for(int i=0,k;i<2;i+=u[k]){
					if((k=mem[s-i]))printf("M %d %d\n",pos[k],pos[t]+i);
					pos[k]=pos[t]+i;
					for(int j=0;j<u[k];++j)mem[pos[t]+i+j]=k;
				}
				mem[s--]=0;mem[s--]=0;
				if(e && s-e>1 && u[mem[s]]==1){
					printf("M %d %d\n",s,pos[mem[s]]=e);
					mem[e]=mem[s];mem[e=s]=0;
				}
				break;
			case 3:
				if(pos[t]!=h){
					printf("M %d %d\n",h,pos[mem[h]]=pos[t]);
					mem[pos[t]++]=mem[h];
					mem[pos[t]++]=mem[h];
					mem[pos[t]++]=mem[h];
				}
				mem[h++]=0;mem[h++]=0;mem[h++]=0;
			}
			pos[t]=0;puts("D");
		}
		assert(!e || s-e<=1 || u[mem[s]]==2);
	}
}
