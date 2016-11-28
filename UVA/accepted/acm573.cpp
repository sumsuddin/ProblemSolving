#include<stdio.h>
long i;
double h,u,d,f,mn,dp,p;
int main()
{
	while(~scanf("%lf%lf%lf%lf",&h,&u,&d,&f),h)
	{
		dp=((u*f)/100)+1e-17;
		p=0;

		for(i=1;;i++)
		{
			mn=u-((i-1)*dp);
			if(mn<0)
			{
				mn=0;
				dp=0;
				u=0;
			}
			p+=mn;

			if(p>h)
			{
				printf("success on day %ld\n",i);
				break;
			}
			else if(p<0)
			{
				printf("failure on day %ld\n",i);
				break;
			}
			p-=d;
			if(p>h)
			{
				printf("success on day %ld\n",i);
				break;
			}
			else if(p<0)
			{
				printf("failure on day %ld\n",i);
				break;
			}
		}
	}
	return 0;
}