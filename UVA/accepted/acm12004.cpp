#include<stdio.h>
long t,n,cs=1;

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);
		n=n*(n-1);
		if(n%4)
			printf("Case %ld: %ld/2\n",cs++,n/2,2);
		else
			printf("Case %ld: %ld\n",cs++,n/4);
	}
	return 0;
}