#include<stdio.h>

long i,j,n,count[2000050],coin[150],t,bill;
bool bu[2000050];

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&bill);

		scanf("%ld",&n);

		for(i=0;i<n;i++)
			scanf("%ld",&coin[i]);

		for(i=0;i<=1000000;i++)
			bu[i]=0,count[i]=10000;

		bu[0]=1;
		count[0]=0;

		for(i=0;i<n;i++)
		{
			for(j=bill;j>=0;j--)
			{
				if(bu[j])
				{
					if(count[j+coin[i]]>count[j]+1)
						count[j+coin[i]]=count[j]+1,bu[j+coin[i]]=1;
				}
			}
		}
		for(i=bill;i<=1000000;i++)
			if(bu[i])
			{
				printf("%ld %ld\n",i,count[i]);
				break;
			}
	}
	return 0;
}