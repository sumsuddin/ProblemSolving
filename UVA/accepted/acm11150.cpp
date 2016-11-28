#include<stdio.h>
#include<string.h>

int main()
{
	long a,c,n;

	while(scanf("%ld",&a)==1)
	{
		n=a;
		while(a>=3)
		{
			c=a%3;
			a/=3;
			n+=a;
			a+=c;
		}
		if(a==2)
			n++;
		printf("%ld\n",n);
	}
	return 0;
}