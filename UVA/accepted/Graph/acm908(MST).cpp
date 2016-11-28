#include<stdio.h>
#include<stdlib.h>
long i,j,n,t,k,mx,sw,rank[10000010],a[10000010],p1,p2,m;
bool flag=0;
struct TT
{
	long p,q,w;
}sr[10000010];

struct ss
{
	long p,q,w;
}sl[20];


void swap(long *m,long *n)
{
	sw=*m;
	*m=*n;
	*n=sw;
}

void init()
{
	for(i=0;i<=t;i++)
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

int cmp(  const void *a, const void *b )
{
	TT *p = (TT *)a;
	TT *q = (TT *)b;
	return p->w-q->w ;
}


int main()
{
	while(~scanf("%ld",&t))
	{
		t--;
		if(flag)
			printf("\n");
		else
			flag=1;

		for(i=0;i<t;i++)
			scanf("%ld%ld%ld",&sr[i].p,&sr[i].q,&sr[i].w);
		scanf("%ld",&k);
		for(i=0;i<k;i++)
			scanf("%ld%ld%ld",&sl[i].p,&sl[i].q,&sl[i].w);

		scanf("%ld",&m);
		for(i=t;i<t+m;i++)
			scanf("%ld%ld%ld",&sr[i].p,&sr[i].q,&sr[i].w);
		t+=m;

		qsort(sr,t,sizeof(sr[0]),cmp);
		init();
		mx=0;
		for(i=0;i<t;i++)
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
				mx+=sr[i].w;
			}
		}
		printf("%ld\n",mx);
		for(i=0;i<k;i++)
			sr[i+t].p=sl[i].p,sr[i+t].q=sl[i].q,sr[i+t].w=sl[i].w;
		t+=k;

		qsort(sr,t,sizeof(sr[0]),cmp);
		init();
		mx=0;
		for(i=0;i<t;i++)
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
				mx+=sr[i].w;
			}
		}
		printf("%ld\n",mx);
	}
	return 0;
}