#include<stdio.h>

int main()
{
	long double n,r,e,d,i,c;
	while(scanf("%llf%llf",&n,&r) && (n||r))
	{
		c=n-r;
		d=e=1;
		if(c>r)
		{
			for(i=c+1;i<=n;i++)
				d*=i;
			for(i=1;i<=r;i++)
				e*=i;
		}
		else
		{
			for(i=r+1;i<=n;i++)
				d*=i;
			for(i=1;i<=c;i++)
				e*=i;
		}
		d/=e;
		printf("%.0llf things taken %.0llf at a time is %.0llf exactly.\n",n,r,d);
	}
	return 0;
}