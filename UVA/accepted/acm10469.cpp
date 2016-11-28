#include<stdio.h>

int main()
{
	long int a,b,c;
	while(scanf("%ld%ld",&a,&b)==2)
	{
		c=a^b;
		printf("%ld\n",c);
	}
	return 0;
}