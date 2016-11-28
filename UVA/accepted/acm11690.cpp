#include<stdio.h>

long a[10010],rank[10010],p1,p2,x,y,n,m,flag,wt[10010],i,t;

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
		scanf("%ld%ld",&n,&m);

		init();

		for(i=0;i<n;i++)
			scanf("%ld",&wt[i]);

		for(i=0;i<m;i++)
		{
			scanf("%ld%ld",&x,&y);
			p1=parent(x);
			p2=parent(y);
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
			}
		}
		for(i=0;i<n;i++)
		{
			p1=parent(i);
			if(p1!=i)
			{
				wt[p1]+=wt[i];
				wt[i]=0;
			}
		}
		flag=1;
		for(i=0;i<n;i++)
			if(wt[i]!=0)
			{
				flag=0;
				break;
			}

		if(flag)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}