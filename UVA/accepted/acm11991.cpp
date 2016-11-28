#include<stdio.h>
#include<algorithm>
#include<memory.h>
using namespace std;
#define swap(m,n)m^=n^=m^=n
long st[1000010],n,m,i,a[1000010],b[1000010],pr,k,l,u,rpt[1000010];
bool flag;
struct ss
{
	long a,pos,rep;
}
sr[1000010];

int cmp(void const *a,void const *b)
{
	if(((ss*)a)->a==((ss*)b)->a)
		return ((ss*)a)->pos-((ss*)b)->pos;
	else
		return ((ss*)a)->a-((ss*)b)->a;
}

int main()
{
	while(~scanf("%ld%ld",&n,&m))
	{
		memset(rpt,0,sizeof(rpt));
		for(i=0;i<n;i++)
		{
			scanf("%ld",&sr[i].a);
			sr[i].rep=++rpt[sr[i].a];
			sr[i].pos=i+1;
		}
		qsort(sr,n,sizeof(sr[0]),cmp);
		while(m--)
		{
			scanf("%ld%ld",&k,&pr);
			flag=1;
			l=0;u=n-1;
			while(u>=l)
			{
				i=(u+l)/2;

				if(sr[i].a==pr)
				{
					if(sr[i].rep==k)
					{
						flag=0;
						printf("%ld\n",sr[i].pos);
						break;
					}
					else
						if(sr[i].rep<k)
							l=i+1;
						else
							if(sr[i].rep>k)
								u=i-1;
				}
				else
					if(sr[i].a<pr)
						l=i+1;
					else
						if(sr[i].a>pr)
							u=i-1;
			}
			if(flag)
				printf("0\n");
		}
	}
	return 0;
}