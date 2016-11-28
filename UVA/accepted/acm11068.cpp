#include<stdio.h>
float a1,a2,b1,b2,c1,c2,x,y,c;
int main()
{
	while(scanf("%f%f%f%f%f%f",&a1,&b1,&c1,&a2,&b2,&c2)&&(a1||a2||b1||b2||c1||c2))
	{
		c=a1*b2-a2*b1;
		if(c)
		{
			x=(b2*c1-b1*c2)/c;
			y=(c2*a1-c1*a2)/c;
			printf("The fixed point is at %.2f %.2f.\n",x,y);
		}
		else
			printf("No fixed point exists.\n");
	}
	return 0;
}