#include<stdio.h>
long i,a,min,sum,n,cs=1,gc,count,c,m,cnt;
long gcd(long a,long b)
{
	while(1)
	{
		c=b%a;
		if(c==0)
			return a;
		b=a;
		a=c;
	}
}
int main()
{
	while(~scanf("%ld",&n),n)
	{
		printf("Case %ld:\n",cs++);
		sum=min=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a);
			sum+=a;
		}
		if(sum<0)
			min=1,sum*=-1;

		if(sum%n)
		{
			a=sum%n;
			gc=gcd(a,n);

			m=n/gc;
			count=0;
			while(m)
			{
				count++;
				m/=10;
			}
			m=sum/n;
			cnt=0;
			while(m)
			{
				cnt++;
				m/=10;
			}
			m=sum/n;
			if(min)
			{
				printf("  %*ld\n",count+cnt,a/gc);
				if(m)
					printf("- %ld",m);
				else
					printf("- ");

				for(i=0;i<count;i++)
					printf("-");
				printf("\n");
				printf("  %*ld\n",count+cnt,n/gc);
			}
			else
			{
				printf("%*ld\n",count+cnt,a/gc);
				if(m)
					printf("%ld",m);

				for(i=0;i<count;i++)
					printf("-");
				printf("\n");
				printf("%*ld\n",count+cnt,n/gc);
			}
		}
		else
		{
			if(min)
				printf("- %ld\n",sum/n);
			else
				printf("%ld\n",sum/n);
		}
	}
	return 0;
}