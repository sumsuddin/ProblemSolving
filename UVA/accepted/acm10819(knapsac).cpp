#include<stdio.h>
#include<algorithm>
using namespace std;

long n,m,l,i,cc[1000050],j;
bool st[1000050];
struct ss
{
	long cst,fb;
}
nd[100005];

bool cmp(ss a,ss b)
{
	return a.cst<b.cst;
}

int main()
{
	while(~scanf("%ld%ld",&n,&m))
	{
		for(i=0;i<m;i++)
			scanf("%ld%ld",&nd[i].cst,&nd[i].fb);

		sort(nd,nd+m,cmp);
		for(i=0;i<100000;i++)
			st[i]=0,cc[i]=1000000000;

		st[0]=1;
		cc[0]=0;
		l=m*6;

		for(i=0;i<m;i++)
		{
			for(j=l;j>=0;j--)
			{
				if(st[j])
				if((cc[j]+nd[i].cst<=n || (cc[j]+nd[i].cst>2000 && cc[j]+nd[i].cst<=n+200)) && cc[j+nd[i].fb]>cc[j]+nd[i].cst)
				{
					st[j+nd[i].fb]=1;

					cc[j+nd[i].fb]=cc[j]+nd[i].cst;
				}
			}
		}
		for(i=l;i>=0;i--)
			if(st[i])
			{
				printf("%ld\n",i);
				break;
			}
	}
	return 0;
}