#include<stdio.h>
#include<math.h>
int main()
{
	double x1,x2,x3,y1,y2,y3,d,dx,g,c,f;
	char gch,fch,cch;

	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
	{
		d=4*((x1-x2)*(y2-y3)-(x2-x3)*(y1-y2));

		dx=2*((y1-y2)*(x2*x2+y2*y2-x3*x3-y3*y3)-(y2-y3)*(x1*x1+y1*y1-x2*x2-y2*y2));

		g=dx/d;

		dx=2*((x2-x3)*(x1*x1+y1*y1-x2*x2-y2*y2)-(x1-x2)*(x2*x2+y2*y2-x3*x3-y3*y3));

		f=dx/d;

		c=-1*(x1*x1+y1*y1+2*g*x1+2*f*y1);

		if(g<0)
		{
			gch='-';
			g*=-1;
		}
		else
			gch='+';
		if(f<0)
		{
			fch='-';
			f*=-1;
		}
		else
			fch='+';

		printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",gch,g,fch,f,sqrt(g*g+f*f-c));
		if(c<0)
		{
			cch='-';
			c*=-1;
		}
		else
			cch='+';
		printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n",gch,2*g,fch,2*f,cch,c);

	}
	return 0;
}