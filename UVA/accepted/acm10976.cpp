#include<stdio.h>
long i,n,lcm,sum,ab[1000],ac[1000];

int main()
{
	while(~scanf("%ld",&n))
	{
		i=n+1;

		sum=0;
		
		while(1)
		{
			lcm=(n*i)/(i-n);
			if(n==(lcm*i)/(lcm+i))
			{
				ab[sum]=lcm;
				ac[sum]=i;
				sum++;
			}

			if(lcm<i++)
			{
				printf("%ld\n",sum);
				for(i=0;i<sum;i++)
					printf("1/%ld = 1/%ld + 1/%ld\n",n,ab[i],ac[i]);
				break;
			}
		}
	}
	return 0;
}