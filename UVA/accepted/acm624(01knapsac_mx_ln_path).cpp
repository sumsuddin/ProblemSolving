#include<stdio.h>

long i,ck[1000050],tot[1000050],a[50],m,n,j;
bool sum[1000050];

int main()
{
	while(~scanf("%ld",&m))
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);

		for(i=0;i<=m;i++)
			ck[i]=tot[i]=sum[i]=0;

		sum[0]=1;

		for(i=1;i<=n;i++)
		{
			for(j=m;j>=0;j--)
				if(sum[j] && j+a[i]<=m)
				{
					sum[j+a[i]]=1;
					if(tot[j+a[i]]<tot[j]+1 && ((ck[j]>>i)&1)==0)
						tot[j+a[i]]=tot[j]+1,ck[j+a[i]]=ck[j]|1<<i;
				}
		}

		for(i=m;i>=0;i--)
			if(sum[i])
			{
				for(j=0;j<=n;j++)
					if(((ck[i]>>j)&1)==1)
						printf("%ld ",a[j]);
				break;
			}
		printf("sum:%ld\n",i);
	}
	return 0;
}