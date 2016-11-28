#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long i,j,a[300000],rank[300000],t,tot,p1,p2,sw,n,eg,rf;
long x[1000],y[1000],mx;

struct ss
{
	long p,q,w;
} sr[300000];

int cmp(const void *a,const void *b)
{
	return ((ss*)a)->w-((ss*)b)->w;
}

void swap(long *m,long *n)
{
	sw=*m;
	*m=*n;
	*n=sw;
}

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
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&rf,&n);


		for(i=0;i<n;i++)
			scanf("%ld%ld",&x[i],&y[i]);

		eg=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				if(i==j)
					continue;
				sr[eg].p=i;
				sr[eg].q=j;
				sr[eg++].w=((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			}

		qsort(sr,eg,sizeof(sr[0]),cmp);
		init();
		tot=mx=0;
		for(i=0;i<eg;i++)
		{
			p1=parent(sr[i].p);
			p2=parent(sr[i].q);
			if(p1!=p2)
			{
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
				tot++;
				if(sr[i].w>mx)
					mx=sr[i].w;
				if(tot>=n-rf)
					break;
			}
		}
		printf("%.2lf\n",(double)sqrt(mx));
	}
	return 0;
}