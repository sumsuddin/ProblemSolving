#include<stdio.h>
int main()
{
	long n;
	while(scanf("%ld",&n))
	{
		if(n<0)
			break;
		else
		{
			if(n==1)
				printf("0%%\n");
			else
				printf("%ld%%\n",n*25);
		}
	}
	return 0;
}