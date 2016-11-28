#include<stdio.h>
long i,j,a[1010],n,sum,t;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		sum=0;

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		for(i=1;i<n;i++)
			for(j=0;j<i;j++)
				if(a[i]>=a[j])
					sum++;
		printf("%ld\n",sum);
	}
	return 0;
}