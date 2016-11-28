#include<stdio.h>
#include<math.h>
double a,b,c,s,area,r1,r2,r3,t;
long n;

int main()
{
	scanf("%ld",&n);

	while(n--)
	{
		scanf("%lf%lf%lf",&r1,&r2,&r3);

		a=r1+r2;
		b=r2+r3;
		c=r3+r1;

		s=(a+b+c)*0.5;

		area=sqrt(s*(s-a)*(s-b)*(s-c));

		t=acos((b*b+c*c-a*a)/(2.0*b*c));
		area-=0.5*r3*r3*t;

		t=acos((a*a+c*c-b*b)/(2.0*a*c));
		area-=0.5*r1*r1*t;

		t=acos((b*b+a*a-c*c)/(2.0*a*b));
		area-=0.5*r2*r2*t;

		printf("%.6lf\n",area);
	}
	return 0;
}