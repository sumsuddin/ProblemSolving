#include<stdio.h>

int main()
{
	long int a,b,i,n,c,d;

	scanf("%ld",&n);

	for(i=0;i<n;i++)
	{
		scanf("%ld%ld",&a,&b);

		c=a+b;
		d=a-b;

		if(a>=b && c%2==0)
		{
			c>>=1;
			d>>=1;
			printf("%ld %ld\n",c,d);
		}
		else
			printf("impossible\n");
	}

	return 0;
}