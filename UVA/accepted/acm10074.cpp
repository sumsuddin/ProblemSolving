#include<stdio.h>
long long i,j,k,l,sum,mx,a[110][110],n,m,st[110][110];
int main()
{
	while(scanf("%lld%lld",&n,&m) && (m || n))
	{
		mx=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%lld",&st[i][j]);
				if(st[i][j]==1)
					st[i][j]=-10005;
				else
					st[i][j]=1;
			}
		}

		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=i;k<m;k++)
				{
					if(k==i)
						a[j][k]=st[j][k];
					else
						a[j][k]=a[j][k-1]+st[j][k];

					if(mx<a[j][k])
						mx=a[j][k];
				}
			}
			for(l=0;l<n;l++)
			{
				for(j=0;j<m;j++)
				{
					for(k=l;k<n;k++)
					{
						if(k==l)
							sum=a[k][j];
						else
							sum+=a[k][j];

						if(mx<sum)
							mx=sum;
					}
				}
			}
		}
		printf("%lld\n",mx);
	}
	return 0;
}
