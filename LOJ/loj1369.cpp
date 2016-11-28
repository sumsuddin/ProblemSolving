#include<stdio.h>
long a[1000005],i,n,sum,q,t,dir,p,cs=1;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		sum=0;
		scanf("%ld%ld",&n,&q);

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		for(i=0;i<n;i++)
			sum+=((n-i-1)*a[i]-i*a[i]);

		printf("Case %ld:\n",cs++);
		while(q--)
		{
			scanf("%ld",&dir);
			if(dir)
				printf("%ld\n",sum);
			else
			{
				scanf("%ld",&p);
				i=p+1;

				sum+=(p*a[p]-(n-p-1)*a[p]);
				scanf("%ld",&a[p]);
				sum-=(p*a[p]-(n-p-1)*a[p]);
			}
		}
	}
	return 0;
}