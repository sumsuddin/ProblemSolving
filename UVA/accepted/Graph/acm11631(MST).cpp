#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	long w,p,q;
}ss;

ss number[300000];

int fun(const void *a, const void *b)
{
	if( ( ((ss*)a)->w > ((ss*)b)->w ))
		return 1;
	if( ( (ss*)a)->w < ((ss*)b)->w)
		return -1;
	return 0;
}

long sw,large,a[300000],i,t,rank[300000],n,edge,ac,p1,p2,sum,ans,cs=1;

void init()
{
	for(i=0;i<=n;i++)
	{
		a[i]=i;
		rank[i]=0;
	}
}

long parent(long p)
{
	while(a[p]!=p)
		p=a[p];
	return p;
}

int main()
{

	while(scanf("%ld%ld",&n,&edge) && (n || edge))
	{
		init();
		sum=ans=0;

		for(i=0;i<edge;i++)
		{
			scanf("%ld%ld%ld",&number[i].p,&number[i].q,&number[i].w);
			ans+=number[i].w;
		}

		qsort(number, edge, sizeof(number[0]),fun);

		for(i=0;i<edge;i++)
		{
			p1=parent(number[i].p);
			p2=parent(number[i].q);
			if(p1!=p2)
			{
				sum+=number[i].w;
				if(rank[p1]>rank[p2])
				{
					a[p2]=p1;
					rank[p1]++;
				}
				else
				{
					a[p1]=p2;
					rank[p2]++;
				}
			}
		}
		printf("%ld\n",ans-sum);
	}
	return 0;
}