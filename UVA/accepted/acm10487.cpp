#include<stdio.h>
#include<algorithm>
using namespace std;
long i,j,ans,a[1010],sum[1000010],p,pf,l,u,nn,n,m,d,cs=1;
long bsearch()
{
	l=0;u=p;
	while(u>=l)
	{
		i=(u+l)/2;

		if(sum[i]==nn)
			return i;
		else
			if(sum[i]<nn)
				l=i+1;
			else
				if(sum[i]>nn)
					u=i-1;
	}
	return i;
}

int main()
{
	while(scanf("%ld",&nn),nn)
	{
		p=0;
		for(i=0;i<nn;i++)
			scanf("%ld",&a[i]);

		for(i=0;i<nn;i++)
		{
			for(j=0;j<nn;j++)
			{
				if(i!=j)
				{
					sum[p]=0;
					sum[p++]=a[i]+a[j];
				}
			}
		}
		sum[p]=0;

		sort(sum,sum+p);

		scanf("%ld",&m);
		printf("Case %ld:\n",cs++);
		while(m--)
		{
			scanf("%ld",&nn);
			pf=bsearch();
			ans=pf;
			if(sum[pf]==nn)
				printf("Closest sum to %ld is %ld.\n",nn,sum[ans]);
			else
			{
				d=nn-sum[pf];

				if(d<0)
					d*=-1;
				for(i=pf+1;i<nn;i++)
				{
					j=nn-sum[i];
					if(j<0)
						j*=-1;
					if(d>j)
					{
						d=j;
						ans=i;
					}
					else
						break;
				}
				for(i=pf-1;i>=0;i--)
				{
					j=nn-sum[i];
					if(j<0)
						j*=-1;
					if(d>j)
					{
						d=j;
						ans=i;
					}
					else
						break;
				}
				printf("Closest sum to %ld is %ld.\n",nn,sum[ans]);
			}
		}
	}
	return 0;
}