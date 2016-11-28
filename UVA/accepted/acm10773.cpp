#include<stdio.h>
#include<math.h>


int main()
{
	double n,c,d,i,e,u,v;

	scanf("%lf",&n);

	for(i=1;i<=n;i++)
	{
		e=1;
		scanf("%lf%lf%lf",&d,&v,&u);

		if(v>=u)
			printf("Case %.0lf: can't determine\n",i);

		else
		{
			c=u*u-v*v;
			e/=sqrt(c);
			e-=1/u;
			d*=e;

			if(d==0)
				printf("Case %.0lf: can't determine\n",i);
			else
				printf("Case %.0lf: %.3lf\n",i,d);
		}
	}
	return 0;
}