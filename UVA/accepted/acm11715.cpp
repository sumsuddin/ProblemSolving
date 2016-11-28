#include<stdio.h>
#include<math.h>
int main()
{
	long double a,b,c,x,y,n;

	long int p=1;

	while(scanf("%llf",&n))
	{

		if(n==0)
			break;

		scanf("%llf%llf%llf",&a,&b,&c);

		if(n==1)
		{
			y=(b-a)/c;

			x=(a+.5*y*c)*c;

			printf("Case %ld: %.3llf %.3llf\n",p++,x,y);
		}
		else
		{
			if(n==2)
			{
				y=(b-a)/c;

				x=(a+.5*c*y)*y;

				printf("Case %ld: %.3llf %.3llf\n",p++,x,y);
			}
			else
			{
				if(n==3)
				{
					x=sqrt((a*a)+(2*b*c));

					y=(x-a)/b;

					printf("Case %ld: %.3llf %.3llf\n",p++,x,y);
				}
				else
				{
					if(n==4)
					{
						x=sqrt((a*a)-(2*b*c));

						y=(a-x)/b;

						printf("Case %ld: %.3llf %.3llf\n",p++,x,y);
					}
				}
			}
		}
	}
	return 0;
}
