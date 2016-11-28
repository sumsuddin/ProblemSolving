#include<stdio.h>
long n,a;
bool flag;
int main()
{
	while(scanf("%ld",&n),n)
	{
		flag=1;
		while(n--)
		{
			scanf("%ld",&a);
			if(a)
			{
				if(flag)
				{	
					flag=0;
					printf("%ld",a);
				}
				else
					printf(" %ld",a);
			}
		}
		if(flag)
			printf("0\n");
		else
			printf("\n");
	}
	return 0;
}