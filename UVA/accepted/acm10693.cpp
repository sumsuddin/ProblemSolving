#include<stdio.h>
#include<math.h>
int main()
{
	double l,f,v,vl;
	while(scanf("%lf%lf",&l,&f)==2 && (l||f))
	{
		v=sqrt(2*l*f);
		printf("%.8lf ",v);

		vl=(v*3600)/(2*l);
		printf("%.8lf\n",vl);
	}
	return 0;
}