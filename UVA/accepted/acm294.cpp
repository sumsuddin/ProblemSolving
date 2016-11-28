#include<stdio.h>
#include<math.h>
bool flag;
long i,j,sq,n,pi,d,low,uper,ma,a;
void divisor(long pi)
{
	d=2;
	sq=(long)sqrt(pi);
	for(j=2;j<=sq;j++)
	{
		if((pi%j)==0)
			d+=2;
	}
	if(sq*sq==pi)
		d--;
}
int main()
{
	scanf("%ld",&n);
	while(n--)
	{
		scanf("%ld%ld",&low,&uper);

		ma=0;
		for(i=low;i<=uper;i++)
		{
			divisor(i);
			if(d>ma)
			{
				ma=d;
				a=i;
			}
		}
		printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n",low,uper,a,ma);
	}

	return 0;
}