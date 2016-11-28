#include<stdio.h>

int main()
{
	long int j=1,n,sum,ans,st[105];
	int i;

	while(scanf("%ld",&n))
	{

		ans=sum=0;
		if(n==0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&st[i]);
			sum+=st[i];
		}

		sum/=n;

		for(i=0;i<n;i++)
		{
			if(st[i]>sum)
				ans+=st[i]-sum;

		}
		printf("Set #%ld\n",j++);
		printf("The minimum number of moves is %ld.\n\n",ans);
	}
	return 0;
}