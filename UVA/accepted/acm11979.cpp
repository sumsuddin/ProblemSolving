#include<stdio.h>
#define swap(m,n)m^=n^=m^=n
long i,j,k,n,m,sum,d,st[2010][15],p=1,t;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%ld",&st[i][j]);
		sum=0;
		for(j=0;j<m;j++)
		{
			for(i=0;i<n;i++)
				for(k=i+1;k<n;k++)
					if(st[i][j]>st[k][j])
						swap(st[i][j],st[k][j]);
			for(i=0;i<n;i++)
			{
				d=st[i][j]-i;
				if(d<0)
					d*=-1;
				sum+=d;
			}
		}
		printf("Case %ld: %ld\n",p++,sum);
	}
	return 0;
}