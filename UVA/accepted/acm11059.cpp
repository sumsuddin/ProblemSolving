#include<stdio.h>
long i,a[50],n,cs=1,j,ma,ans,d;

int main()
{
	while(~scanf("%ld",&n))
	{
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		ma=0;
		for(d=1;d<=n;d++)
		{
			for(i=0;i<=n-d;i++)
			{
				ans=1;
				for(j=0;j<d;j++)
					ans*=a[i+j];
				if(ans>ma)
					ma=ans;
			}
		}

		printf("Case #%ld: The maximum product is %ld.\n\n",cs++,ma);
	}
	return 0;
}