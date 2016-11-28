#include<stdio.h>
#include<math.h>
int main()
{
	long double sum;
	long i,j,n;

	while(scanf("%ld",&n)==1)
	{
		sum=1;
		j=0;
		for(i=0;i<n;i++)
		{
			sum/=2;
			if(sum<1)
			{
				sum*=10;
				j++;
			}
		}
		printf("2^-%ld = %.3llfe-%ld\n",n,sum,j);
	}
	return 0;
}