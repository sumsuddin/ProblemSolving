#include<stdio.h>
#include<math.h>

#define pi 3.14159265358979323846264338327950288419716939937510582097
double a,b,c,l,h,w,A,A1,s,area;
int main()
{
	while(scanf("%lf%lf%lf%lf",&l,&w,&h,&A1)==4)
	{
		A=((A1*pi)/180);
		if(h*sin(1.5707963267948966192313216916395-A)<l*sin(A))
		{
			a=h/sin(A);
			b=h/tan(A);
			s=(a+b+h)/2;

			area=sqrt(s*(s-a)*(s-b)*(s-h))*w;
		}
		else
			if(h*sin(1.5707963267948966192313216916395-A)==l*sin(A))
			{
				c=sqrt(l*l+h*h);
				s=(l+h+c)/2;
				area=sqrt(s*(s-l)*(s-h)*(s-c))*w;
			}
			else
			{
				a=l/cos(A);
				b=l*tan(A);
				s=(a+b+l)/2;

				area=((h*l)-sqrt(s*(s-a)*(s-b)*(s-l)))*w;
			}
			printf("%.3lf mL\n",area);
	}
	return 0;
}