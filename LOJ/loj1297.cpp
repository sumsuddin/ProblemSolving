#include<stdio.h>
double a,b,midr,midl,mid;
long t,cs=1;
double fn(double x)
{
	if((a-2.0*x)<0.00000000001 || (b-2.0*x)<0.00000000001)
		return 0.0;
	return (a-2.0*x)*(b-2.0*x)*x;
}

void bsrch(double l,double h)
{
	while(h-l>0.00000000001)
	{
		midl=(l*2.0+h)/3.0;
		midr=(l+h*2.0)/3.0;

		if(fn(midl)>fn(midr))
			h=midr;
		else
			l=midl;
	}
	mid=l;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%lf%lf",&a,&b);

		bsrch(0.0,a<b?a:b);
		printf("Case %ld: %.10lf\n",cs++,fn(mid)+1e-11);
	}
	return 0;
}
