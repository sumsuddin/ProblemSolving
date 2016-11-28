#include<stdio.h>
int main()
{
	long int n,p=1;
	
	double a1,a2,a3,a4,b1,b2,b3,sum,b,min;
	scanf("%ld",&n);

	while(n--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf",&a1,&a2,&a3,&a4,&b1,&b2,&b3);

		printf("Case %ld: ",p++);
		sum=0;
		min=b1;

		if(min>b2)
			min=b2;
		if(min>b3)
			min=b3;

		b=(b1+b2+b3-min)/2;

		sum=a1+a2+a3+a4+b;

		if(sum>= 90)
			printf("A\n");
		else
		{
			if(sum>= 80 && sum< 90)
				printf("B\n");
			else
			{
				if(sum>= 70 && sum< 80)
					printf("C\n");
				else
				{
					if(sum>= 60 && sum< 70)
						printf("D\n");
					else
						printf("F\n");
				}
			}
		}
	}
	return 0;
}