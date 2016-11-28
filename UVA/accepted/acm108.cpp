#include<stdio.h>
long i,j,k,l,sum,mx,st[110][110],a[110][110],b[110][110],n;
int main()
{
	while(~scanf("%ld",&n))
	{
		mx=-9999999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%ld",&st[i][j]);
				if(mx<st[i][j])
					mx=st[i][j];
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=i;k<=n;k++)
				{
					if(k==i)
						a[j][k]=st[j][k];
					else
						a[j][k]=a[j][k-1]+st[j][k];

					if(mx<a[j][k])
						mx=a[j][k];
				}
			}
			for(l=1;l<=n;l++)
			{
				for(j=1;j<=n;j++)
				{
					sum=0;
					for(k=l;k<=n;k++)
					{
						if(k==l)
							b[k][j]=a[k][j];
						else
							b[k][j]=b[k-1][j]+a[k][j];

						if(mx<b[k][j])
							mx=b[k][j];
					}
				}
			}
		}

		printf("%ld\n",mx);
	}
	return 0;
}
