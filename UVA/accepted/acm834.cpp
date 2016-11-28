#include<stdio.h>

int main()
{
	long a,b,c,d;

	while(scanf("%ld%ld",&a,&b)==2)
	{
		printf("[%ld;",a/b);

		d=0;

		while(1)
		{
			c=a%b;
			if(c==0)
			{
				printf("]\n");
				break;
			}
			else
				if(d++)
					printf(",");

			a=b;
			b=c;
			printf("%ld",a/b);
		}
	}
	return 0;
}