#include<stdio.h>
#include<math.h>
long n,flag;
double x,y,xx,x2,yy,y2;
int main()
{
	while(~scanf("%ld%lf%lf%lf%lf",&n,&xx,&yy,&x2,&y2))
	{
		flag=1;
		while(n--)
		{
			if(flag)
			{
				scanf("%lf%lf",&x,&y);

				if(2*sqrt((xx-x)*(xx-x)+(yy-y)*(yy-y))<=sqrt((x2-x)*(x2-x)+(y2-y)*(y2-y)))
				{
					printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",x,y);
					flag=0;
				}
			}
			else
				scanf("%lf%lf",&x,&y);
		}
		if(flag)
			printf("The gopher cannot escape.\n");
	}
	return 0;
}