#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long i,a[10010],rank[10010],eg,p1,p2,mx,n,sw,m,t,cs=1;
struct TT
{
	long p,q,w;
}nd[10010];

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

int func(  const void *a, const void *b )
{
	TT *p = (TT *)a;
	TT *q = (TT *)b;
	return q->w-p->w ;
}
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&eg);
		init();

		for(i=0;i<eg;i++)
			scanf("%ld%ld%ld",&nd[i].p,&nd[i].q,&nd[i].w);

		mx=10000000;
		qsort((void *)nd,eg,sizeof(nd[0]),func);

		for(i=0;i<eg;i++)
		{
			p1=parent(nd[i].p);
			p2=parent(nd[i].q);
			if(p1!=p2)
			{
				if(mx>nd[i].w)
					mx=nd[i].w;

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
		printf("Case #%ld: %ld\n",cs++,mx);
	}
	return 0;
}