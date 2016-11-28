#include<stdio.h>
int main()
{
	long int n,t;

	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);

		n=(((((n*567)/9)+7492)*235)/47)-498;
		n/=10;
		n=n%10;
		if(n<0)
			printf("%ld\n",-n);
		else
			printf("%ld\n",n);
	}
	return 0;
}