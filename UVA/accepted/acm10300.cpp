#include<stdio.h>

int main()
{
	long int a,b,n,ans,fa,k,i;

	scanf("%ld",&n);
		for(k=0;k<n;k++)
		{
			ans=0;
			scanf("%ld",&fa);

			for(i=0;i<fa;i++)
			{
				scanf("%ld%*ld%ld",&a,&b);
				a*=b;
				ans+=a;
			}
			printf("%ld\n",ans);
		}
	
	return 0;
}