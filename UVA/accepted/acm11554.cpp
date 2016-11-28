#include<stdio.h>
long i,t,n,sum,d;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		sum=0;
		scanf("%ld",&n);

		for(i=1;i<n;i++)
		{
			if(2*i+1>=n)
				break;
			else
			{
				d=n-2*i-1;
				sum+=(d*(d+1))/2;
			}
		}
		printf("%ld\n",sum);
	}
	return 0;
}