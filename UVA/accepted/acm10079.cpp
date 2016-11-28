#include<stdio.h>
int main()
{
	long int n;
	while(scanf("%ld",&n))
	{
		if(n<0)
			break;
		else
		{
			n=(long int)(n*(n+1))/2+1;
			printf("%ld\n",n);
		}
	}
	return 0;
}