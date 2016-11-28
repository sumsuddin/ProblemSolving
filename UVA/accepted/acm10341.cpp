#include<stdio.h>
#include<math.h>
#define EPS 1e-7
double p,x,r,s,t,u,q;
double form(double x)
{
	return p* exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double srch(double l, double h)
{
	double mid=(l+h)*.5;

	if((h-l)<EPS)
		return mid;

	if(form(mid)>0.0)
		return srch(mid,h);
	else
		return srch(l,mid);
}

int main()
{
	while(~scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u))
	{
		if(form(0.0)<0.0 || form(1.0)>0.0)
			printf("No solution\n");
		else
			printf("%.4lf\n",srch(0,1));
	}
	return 0;
}