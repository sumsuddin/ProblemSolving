#include<stdio.h>
int main()
{
	long int m,n,c,max,i;
	scanf("%ld",&n);

	for(i=1;i<=n;i++)
	{
		max=0;
		scanf("%ld",&m);
		while(m--)
		{
			scanf("%ld",&c);
			if(c>max)
				max=c;
		}
		printf("Case %ld: %ld\n",i,max);
	}
	return 0;
}