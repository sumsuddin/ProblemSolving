#include<stdio.h>
#include<math.h>
long prime(long a)
{
	long i,d,c;

	if((a%2)==0)
	{
		d=0;
		return 0;
	}
	else
	{
		c=1;
		d=(long)sqrt(a)+1;
		for(i=3;i<d;i+=2)
		{
			if((a%i)==0)
			{
				c=0;
				return 0;
				break;
			}
		}
		if(c)
			return 1;
	}
}
int main()
{
	long a,b,d,n;

	while(scanf("%ld",&a)==1)
	{				
		n=a;
		if(a==2 ||a==1)
			printf("%ld is prime.\n",n);
		else
		{
			d=prime(a);
			if(d)
			{
				b=0;
				while(a)
				{
					b=b*10+a%10;
					a/=10;
				}
				if(b!=n)
					d+=prime(b);
			}
			if(d==0)
				printf("%ld is not prime.\n",n);
			else if(d==1)
				printf("%ld is prime.\n",n);
			else if(d==2)
				printf("%ld is emirp.\n",n);
		}

	
	}
	return 0;
}