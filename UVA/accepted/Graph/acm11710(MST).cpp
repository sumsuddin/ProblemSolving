#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long i,a[100010],rank[100010],eg,p1,p2,mx,n,sw,m;
struct TT
{
	long p,q,w;
}nd[100010];
char st[500][100],ss[100],sr[100];

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
	return p->w - q->w ;
}
int main()
{
	while(scanf("%ld%ld",&n,&eg) && ( n || m))
	{
		init();
		for(i=0;i<n;i++)
			scanf("%s",st[i]);

		for(i=0;i<eg;i++)
		{
			scanf("%s%s%ld",ss,sr,&nd[i].w);
			for(mx=0;mx<n;mx++)
				if(strcmp(st[mx],ss)==0)
				{
					nd[i].p=mx;
					break;
				}
			for(mx=0;mx<n;mx++)
				if(strcmp(st[mx],sr)==0)
				{
					nd[i].q=mx;
					break;
				}
		}

		mx=0;
		qsort((void *)nd,eg,sizeof(nd[0]),func);

		for(i=0;i<eg;i++)
		{
			p1=parent(nd[i].p);
			p2=parent(nd[i].q);
			if(p1!=p2)
			{
				mx+=nd[i].w;

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
		eg=0;
		for(i=0;i<n;i++)
			if(parent(i)==i)
			{
				eg++;
				if(eg>=2)
					break;
			}

		scanf("%s",ss);
		if(eg==1)
			printf("%ld\n",mx);
		else
			printf("Impossible\n");
	}
	return 0;
}