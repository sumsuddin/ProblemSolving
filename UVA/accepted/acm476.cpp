#include<stdio.h>

long d,i,j;
double x1[1000],x2[1000],y1[1000],y2[1000],x,y;
char c;
bool flag;

int main()
{
	i=0;
	while(scanf(" %c ",&c) && c!='*')
	{
		scanf("%lf%lf%lf%lf",&x1[i],&y1[i],&x2[i],&y2[i]);

		if(x1[i]>x2[i])
		{
			x=x1[i];
			x1[i]=x2[i];
			x2[i]=x;
		}

		if(y1[i]>y2[i])
		{
			y=y1[i];
			y1[i]=y2[i];
			y2[i]=y;
		}
		i++;
	}
	d=1;
	while(scanf("%lf%lf",&x,&y) && x!=9999.9 && y!=9999.9)
	{
		flag=1;
		for(j=0;j<i;j++)
		{
			if(x>x1[j] && x<x2[j] && y>y1[j] && y<y2[j])
			{
				printf("Point %ld is contained in figure %ld\n",d,j+1);
				flag=0;
			}
		}
		if(flag)
			printf("Point %ld is not contained in any figure\n",d);
		d++;
	}
	return 0;
}