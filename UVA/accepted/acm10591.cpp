#include<stdio.h>

long int devide(long int *a,long int *sum)
{
	long int c;
	while(*a)
	{
		c=*a%10;
		*sum+=c*c;
		*a/=10;
	}
	return *sum;
}

int main()
{
	long int a,b,n,sum,i,j,p=1;

	scanf("%ld",&n);

	while(n--)
	{
		scanf("%ld",&a);

		b=a;i=0;
		while(1)
		{
			sum=0;
			a=devide(&a,&sum);



			if(a==1)
			{
				printf("Case #%ld: %ld is a Happy number.\n",p++,b);
				break;
			}

			else if(a==b || a<10)
			{
				printf("Case #%ld: %ld is an Unhappy number.\n",p++,b);
				break;
			}
		}
	}
	return 0;
}