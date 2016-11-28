#include<stdio.h>

int main()
{
	long int a,n,st[1005],i,j,ans;

	while(scanf("%ld",&n)==1)
	{
		ans=0;
		for(i=1;i<=n;i++)
			scanf("%ld",&st[i]);

		for(i=1;i<=n;i++)
		{
			for(j=1;j<n;j++)
			{
				if(st[j]>st[j+1])
				{
					ans++;

					a=st[j+1];
					st[j+1]=st[j];
					st[j]=a;
				}
			}
		}

		printf("Minimum exchange operations : %ld\n",ans);
	}
					
return 0;

}
