#include<stdio.h>
int main()
{
	long int n,i,a[50];
	while(scanf("%ld",&n),n>=0)
	{
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		i=0;
		while(n)
		{
			a[i++]=n%3;
			n/=3;
		}
		for(i=i-1;i>=0;i--)
			printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}