#include<stdio.h>

int main()
{
	long int a,b,c,n,i=0;

	scanf("%ld",&n);

	while(i++<n)
	{
		scanf("%ld%ld%ld",&a,&b,&c);

		c=a-c%a;

		if(b<=c)
			c=a-(c-b);
		else
			c=b-c;

		printf("Case %ld: %ld\n",i,c);
	}
	return 0;
}