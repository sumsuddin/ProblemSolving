#include<stdio.h>
#define swap(m,n)m^=n^=m^=n
long i,j,k,l,sum,mx,st[110][110],a[110][110],b[110][110],n,m,t,x1,x2,y1,y2;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		mx=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				st[i][j]=1;

		scanf("%ld",&m);

		while(m--)
		{
			scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2);
			if(x2<x1)
				swap(x2,x1);
			if(y2<y1)
				swap(y2,y1);
			for(i=x1;i<=x2;i++)
				for(j=y1;j<=y2;j++)
					st[i][j]=-99999999;
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
					for(k=l;k<=n;k++)
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

		printf("%ld\n",mx);
	}
	return 0;
}
