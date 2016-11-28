#include<stdio.h>
#include<math.h>
double t,d,e,h,ct1;
char st,c,ct;

int main()
{
	while(scanf("%c",&st) && st!='E')
	{
		scanf("%lf %c %lf%*c",&t,&c,&d);


		if(st+c=='T'+'D')
		{
			if(st=='D')
			{
				e=t;
				t=d;
				d=e;
				ct=st;
				st=c;
				c=ct;
			}
			e = 6.11 * exp(5417.7530 * ((1.0/273.16) - (1.0/(d+273.16))));
			h = (0.5555)*(e - 10.0);
			h+=t;
			printf("%c %.1lf %c %.1lf H %.1lf\n",st,t,c,d,h);
		}
		else
			if(st+c=='T'+'H')
			{
				if(st=='H')
				{
					e=t;
					t=d;
					d=e;
					ct=st;
					st=c;
					c=ct;
				}
				e=((d-t)/.5555)+10;
				h=(1/((1/273.16)-(log(e/6.11)/(5417.7530*log(2.718281828)))))-273.16;
				printf("%c %.1lf D %.1lf %c %.1lf\n",st,t,h,c,d);
			}
			else
			{
				if(st=='D')
				{
					e=t;
					t=d;
					d=e;
					ct=st;
					st=c;
					c=ct;
				}
				e = 6.11 * exp(5417.7530 * ((1.0/273.16) - (1.0/(d+273.16))));
				h = (0.5555)*(e - 10.0);
				ct1=t-h;
				printf("T %.1lf %c %.1lf %c %.1lf\n",ct1,c,d,st,t);
			}
	}
	return 0;
}