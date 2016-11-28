#include<stdio.h>
#include<math.h>
long i,sq,m,n,count,flag,d,e,pr;
int main()
{
	while(~scanf("%ld%ld",&n,&m))
	{

		if(n==0 && m==1)
		{
			printf("%ld divides %ld!\n",m,n);
			continue;
		}

		e=m;
		flag=1,pr=0;
		count=0;
		sq=(long)sqrt(m);

		while(m%2==0)
		{
			count++;
			pr=1;
			m/=2;
		}

		d=n;
		while(d)
		{
			count-=(d/2);
			d/=2;
		}
		if(count>0)
			flag=0;
		for(i=3;i<=sq && flag;i++)
		{
			count=0;
			while(m%i==0)
			{
				count++;
				pr=1;
				m/=i;
			}

			d=n;
			while(d)
			{
				count-=(d/i);
				d/=i;
			}
			if(count>0)
				flag=0;
		}
		if(m>1)
		{
			if(n<m)
				flag=0;
		}
		if(flag && (pr ||(pr==0 &&n>=e)))
			printf("%ld divides %ld!\n",e,n);
		else
			printf("%ld does not divide %ld!\n",e,n);
	}
	return 0;
}