#include<stdio.h>
int main()
{
	long int a,b,n;

	scanf("%ld",&n);

	while(n--)
	{
		scanf("%ld%ld",&a,&b);

		if(a>b)
		{
			printf(">\n");
			continue;
		}
		if(a==b)
			printf("=\n");

		else
			printf("<\n");
	}
	return 0;
}