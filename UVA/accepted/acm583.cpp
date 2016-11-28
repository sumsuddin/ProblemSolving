#include<stdio.h>
#include<math.h>
int main()
{
	long int a,i,n;
	while(scanf("%ld",&n),n)
	{
		printf("%ld =",n);
		if(n==-1)
		{
			printf(" -1\n");
			continue;
		}
		if(n==1)
			printf(" 1\n");
		else
		{
			if(n<0)
			{
				printf(" -1 x");
				n*=-1;
			}
			a=(long int)sqrt(n)+1;

			while(!(n%2))
			{
				n/=2;
				printf(" 2");
				if(n!=1)
					printf(" x");
			}

			for(i=3;i<=a;i+=2)
			{
				while(!(n%i))
				{
					n/=i;
					printf(" %ld",i);
					if(n!=1)
						printf(" x");
				}
				a=(long int)sqrt(n)+1;
			}
			if(n && n!=1)
				printf(" %ld",n);
			printf("\n");
		}
	}
	return 0;
}