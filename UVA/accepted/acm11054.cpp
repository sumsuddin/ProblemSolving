#include<stdio.h>

long i,n,a[100050],sum;
int main()
{
	while(scanf("%ld",&n) && n)
	{
		sum=0;
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		for(i=0;i<n;i++)
		{
			if(a[i]<0)
				sum-=a[i];
			else
				sum+=a[i];

			a[i+1]+=a[i];
		}
		printf("%ld\n",sum);
	}
	return 0;
}