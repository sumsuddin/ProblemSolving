#include<stdio.h>
long i,j,n,m,st[10000010],b,ans,l,u,d,ii;

long bsearch(long nn)
{
	d=1;
	l=0;u=n-1;ii=(u-l)/2;
	while(u>=l)
	{

		if(st[ii]==nn)
		{
			d=0;
			return ii;
		}
		else
			if(st[ii]<nn)
			{
				l=ii+1;
				ii=(u+l)/2;
			}
			else
				if(st[ii]>nn)
				{
					u=ii-1;
					ii=(u+l)/2;
				}
	}
	if(d)
		return -1;
}

int main()
{
	while(scanf("%ld%ld",&n,&m) && ( n || m))
	{
		for(i=0;i<n;i++)
			scanf("%ld",&st[i]);
		ans=0;
		for(j=0;j<m;j++)
		{
			scanf("%ld",&b);
			if(bsearch(b)!=-1)
				ans++;
		}	
		printf("%ld\n",ans);
	}
	return 0;
}