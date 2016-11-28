#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,x,y,z,s;

	while(scanf("%lf%lf%lf",&a,&b,&c)==3)
	{

		if((a+b)>c && (a+c)>b && (b+c)>a)
		{
			x=sqrt(((8*b*b)/9)+((8*c*c)/9)-((4*a*a)/9));
			y=sqrt(((8*b*b)/9)+((8*a*a)/9)-((4*c*c)/9));
			z=sqrt(((8*a*a)/9)+((8*c*c)/9)-((4*b*b)/9));

			s=(x+y+z)/2;

			x=sqrt(s*(s-x)*(s-y)*(s-z));
		
			printf("%.3lf\n",x);
		}
		else
			printf("-1.000\n");
	}
	return 0;
}