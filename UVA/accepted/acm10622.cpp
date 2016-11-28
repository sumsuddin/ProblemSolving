#include<stdio.h>
#include<math.h>
typedef long long lng;
lng n,count,i,sq,fl,a;
lng gcd (lng a,lng b)
{
	lng c;
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
	while(scanf("%lld",&n),n)
	{
		fl=0;
        if(n<0)
        n*=-1,fl=1;                     
		sq=sqrt(n)+1;
		count=0;
		a=-1;
		if(n%2==0)
		{
			while(n%2==0)
				n/=2,count++;
			a=count;
		}
		for(i=3;i<sq;i+=2)
		{
			if(n%i==0)
			{
				count=0;
				while(n%i==0)
					n/=i,count++;
				if(a==-1)
					a=count;
				else
					a=gcd(a,count);
			}
		}
		if(n>1)
			a=1;
		if(fl && a%2==0)
			while(a%2==0)
				a/=2;
		printf("%lld\n",a);
	}
	return 0;
}
