#include<stdio.h>
int h,m,sec;
long double s,t,pr,sp;
char c;
int main()
{
	t=s=pr=sp=0;
	while(~scanf("%d:%d:%d%c",&h,&m,&sec,&c))
	{
		pr=h*3600+m*60+sec;
		if(c==' ')
		{
			s+=((pr-t)*sp)/3600;
			t=pr;
			scanf("%llf",&sp);
		}
		else
		{
			printf("%02d:%02d:%02d %.2llf km\n",h,m,sec,s+((pr-t)*sp)/3600);
		}
	}
	return 0;
}