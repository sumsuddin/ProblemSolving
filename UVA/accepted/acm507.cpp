#include<stdio.h>
long i,sum,a,end,start,ansb,anse,mx,n,t,cs=1,d;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		mx=-1;
		sum=0;
		scanf("%ld",&n);

		sum=d=0;start=ansb=anse=end=1;mx=-1;

		for(i=1;i<n;i++)
		{
			scanf("%ld",&a);
			sum+=a;

			if(sum<0)
			{
				sum=0;
				start=i+1;
				end=i+1;
			}
			else
			{
				end++;
				if(mx<sum || (mx==sum &&anse-ansb<end-start))
				{
					mx=sum;
					ansb=start;
					anse=end;
				}
			}
		}

		if(ansb==anse)
			printf("Route %ld has no nice parts\n",cs++);
		else
			printf("The nicest part of route %ld is between stops %ld and %ld\n",cs++,ansb,anse);
	}
	return 0;
}