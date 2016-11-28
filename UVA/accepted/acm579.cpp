#include<stdio.h>
int main()
{
	double h,m;

	while(scanf("%lf:%lf",&h,&m))
	{
		if(h==0 && m==0)
			break;
		else
		{
			h=(h*30+m*.5);
			m=m*6;
			if(h>m)
				h=h-m;
			else
				h=m-h;
			if(h>180)
				h=360-h;
			printf("%.3lf\n",h);
		}
	}
	return 0;
}