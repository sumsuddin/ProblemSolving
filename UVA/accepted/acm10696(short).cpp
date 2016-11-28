#include<stdio.h>
int main()
{
	long int a,n;
	while(scanf("%ld",&n),n)
	{
		if(n<102)
			printf("f91(%ld) = 91\n",n);
		else
		{
			a=n-10;
			printf("f91(%ld) = %ld\n",n,a);
		}
	}
	return 0;
}