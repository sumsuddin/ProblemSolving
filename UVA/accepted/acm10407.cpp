#include<stdio.h>
#include<math.h>
long i,n,num[1050],gc,as;
long gcd(long a,long b)
{
	long c;
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
	while(scanf("%ld",&num[0]),num[0])
	{
		n=1;
		while(scanf("%ld",&num[n]),num[n])
			n++;

		gc=num[1]-num[0];
		if(gc==0)
			gc=num[0];
		if(gc<0)
			gc*=-1;
		
		for(i=2;i<n;i++)
		{
            as=num[i]-num[i-1];
            if(as<0)
                    as*=-1;            
			gc=gcd(gc,as==0?num[i]:as);
        }

		printf("%ld\n",gc);
	}
	return 0;
}
