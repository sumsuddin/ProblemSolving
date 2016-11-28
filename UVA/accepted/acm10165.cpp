#include<stdio.h>
long i,n,a,sum;
int main()
{
	while(~scanf("%ld",&n),n)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a);
			sum^=a;
		}
		if(sum==0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}