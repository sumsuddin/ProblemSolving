#include<stdio.h>
#include<math.h>
int main()
{
	long double x1,x2,x3,y1,y2,y3,d,dx,g;

	while(scanf("%llf%llf%llf%llf%llf%llf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
	{
		d=4*((x1-x2)*(y2-y3)-(x2-x3)*(y1-y2));

		dx=2*((y1-y2)*(x2*x2+y2*y2-x3*x3-y3*y3)-(y2-y3)*(x1*x1+y1*y1-x2*x2-y2*y2));

		g=dx/d;

		dx=2*((x2-x3)*(x1*x1+y1*y1-x2*x2-y2*y2)-(x1-x2)*(x2*x2+y2*y2-x3*x3-y3*y3));

		x3=dx/d;

		y3=-1*(x1*x1+y1*y1+2*g*x1+2*x3*y1);

		g=2*3.141592653589793*sqrt(g*g+x3*x3-y3);
		printf("%.2llf\n",g);
	}
	return 0;
}