#include<stdio.h>
int main()
{
	long int a,b,i,sum;
	printf("PERFECTION OUTPUT\n");
	while(scanf("%ld",&a),a)
	{
		b=a/2;sum=0;
		for(i=1;i<=b;i++)
		{
			if(!(a%i))
				sum+=i;
		}
		if(sum==a)
			printf("%5d  PERFECT\n",a);
		else
		{
			if(sum<a)
				printf("%5d  DEFICIENT\n",a);
			else
				printf("%5d  ABUNDANT\n",a);
		}

	}
	printf("END OF OUTPUT\n");
	return 0;
}