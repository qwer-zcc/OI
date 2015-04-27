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
struct point
{
    int x,y;
    point() {}
    point(int _x,int _y) : x(_x),y(_y) {}
} ;
const int N=120000;
int l,n;
char sa[N];
string s,a;
pair<int,int> Q[N],wz[N];
int main()
{
	//freopen("M.in","r",stdin);
	scanf("%d\n",&n);
	rep(i,1,n)
	{
		gets(sa);
		int c=strlen(sa);
		//s+=a;
		for (int j=0;j<c;j++) s+=sa[j];
		rep(_,l,l+c-1) wz[_]=mp(i,_-l+1);
		l+=c;
	}
	//cout<<s<<endl;
	int now=1;
	rep(i,0,l-1)
	{
		if (s[i]>='a' && s[i]<='z')
		{
			int cnt=0;
			drep(j,i-1,0)
			if (s[j]>='a' && s[j]<='z')
			{
				if (cnt<=0 && s[j]==s[i]) {printf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n",wz[i].first,wz[i].second,s[i],wz[j].first,wz[j].second);break;}
			}
			else if (s[j]=='{' && cnt>0) cnt--;
			else if (s[j]=='}') cnt++;
		}
		/*
		if (s[i]>='a' && s[i]<='z')
		{
			//printf("%d %c %d %d\n",i,s[i],Q[s[i]-'a'].first,Q[s[i]-'a'].second);
			if (Q[s[i]-'a']!=mp(0,0)) printf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n",wz[i].first,wz[i].second,s[i],Q[s[i]-'a'].first,Q[s[i]-'a'].second);
			else Q[s[i]-'a']=mp(wz[i].first,wz[i].second);
			//printf("%d %d\n",Q[0].first,Q[0].second);
		}
		if (s[i]=='}')
		{
			int cnt=1;
			drep(j,i-1,0)
			if (s[j]!='{' && s[j]!='}')
			{
				if (s[j]>='a' && s[j]<='z')
				{
					if (Q[s[j]-'a']==mp(wz[j].first,wz[j].second)) Q[s[j]-'a']=mp(0,0);
				}
			}
			else if (s[j]=='{')
			{
				cnt--;
				if (!cnt)break;
			}
			else if (s[j]=='}') cnt++;
		}
		*/
	}
}

