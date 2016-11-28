#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	double a,b,c,d;
	char st[10];


	while(scanf("%lf%lf",&a,&b)==2)
	{
		gets(st);

		a+=6440;

		if(!strcmp(st," min"))
			b/=60;
		if(b>180)
			b=360-b;
		b*=3.14159265358979323846264338;
		b/=180;

		c=a*b;
		
		b/=2;

		d=a*sin(b);
		d*=2;

		printf("%lf %lf\n",c,d);

	}
	return 0;
}