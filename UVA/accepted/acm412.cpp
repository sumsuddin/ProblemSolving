#include<stdio.h>
#include<math.h>

long i,j,count,n,st[100],d;

long ncr(long n)
{	
	d=n*(n-1);
	d/=2;
	return d;
}

long gcd(long a,long b)
{
	long gcd;
	if(b>a)
	{
		gcd=b;
		b=a;
		a=gcd;
	}
	while(a)
	{
		gcd=a%b;
		a=b;

		if(gcd)
			b=gcd;
		else
			break;
	}
	return b;
}

int main()
{
	while(scanf("%ld",&n) && n!=0)
	{
		for(i=0;i<n;i++)
			scanf("%ld",&st[i]);

		count=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(gcd(st[i],st[j])==1)
					count++;
			}
		}
		if(count)
			printf("%.6lf\n",(double)sqrt((double)(((double)ncr(n)/(double)count)*6)));
		else
			printf("No estimate for this data set.\n");
		
	}
	return 0;
}