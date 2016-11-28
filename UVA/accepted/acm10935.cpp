#include<stdio.h>
long i,c,n,d,st[100],sum;

int main()
{
	while(scanf("%ld",&n),n)
	{
		for(i=1;i<=n;i++)
			st[i]=i;
		c=d=1;
		sum=n;

		printf("Discarded cards:");
		while(sum>1)
		{
			sum=0;
			for(i=1;i<=n;i++)
			{
				if(st[i])
				{
					if(d>0)
					{
						if(i==1)
						{
							printf(" 1");
							st[1]=0;
						}
						else
						{
							printf(", %ld",i);
							st[i]=0;
						}
					}
					else
					{
						c=i;
						sum++;
					}
					d*=-1;
				}
			}
		}
		printf("\nRemaining card: %ld\n",c);
	}
	return 0;
}