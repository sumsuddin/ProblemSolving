#include<stdio.h>
#include<math.h>
int main()
{
	long int n,d;
	while(scanf("%ld",&n))
	{
		if(n==0)
			break;
		else
		{
			d=(long)sqrt(n);
			if(n==d*d)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}