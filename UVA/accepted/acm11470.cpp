#include<stdio.h>

int main()
{
	long int n,i,j,a,test[100],st[100],p=1;

	while(scanf("%ld",&n),n)
	{
		a=n/2;
		a+=n%2;
		for(i=0;i<=a;i++)
			test[i]=0;

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				scanf("%ld",&st[j]);


			if(i<a)
			{
				for(j=0;j<=i;j++)
					test[j]+=st[j];
				for(j=j;j<n-i;j++)
					test[i]+=st[j];
				for(j=j;j<n;j++)
					test[n-1-j]+=st[j];
			}
			else
			{
				for(j=0;j<=n-i-1;j++)
					test[j]+=st[j];
				for(j=j;j<i;j++)
					test[n-i-1]+=st[j];
				for(j=j;j<n;j++)
					test[n-1-j]+=st[j];
			}
		}
		printf("Case %ld:",p++);
		for(j=0;j<a;j++)
			printf(" %ld",test[j]);
		printf("\n");
	}
	return 0;
}
