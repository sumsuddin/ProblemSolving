#include<stdio.h>
long d,i,j;
double x1[100],x2[100],y1[100],y2[100],x3[100],y3[100],x,y,mid,mid1,xa,xb,xc;
char c[20];
bool flag;

int main()
{
	i=0;
	while(scanf(" %c ",&c[i]) && c[i]!='*')
	{
		if(c[i]=='r')
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
		}
		else
			if(c[i]=='c')
				scanf("%lf%lf%lf",&x1[i],&x2[i],&y1[i]);
			else
				scanf("%lf%lf%lf%lf%lf%lf",&x1[i],&y1[i],&x2[i],&y2[i],&x3[i],&y3[i]);

		i++;
	}
	d=1;
	while(scanf("%lf%lf",&x,&y) && x!=9999.9 && y!=9999.9)
	{
		flag=1;
		for(j=0;j<i;j++)
		{
			if(c[j]=='r')
			{
				if(x>x1[j] && x<x2[j] && y>y1[j] && y<y2[j])
				{
					printf("Point %ld is contained in figure %ld\n",d,j+1);
					flag=0;
				}
			}
			else
			{
				if(c[j]=='c')
				{
					if((x-x1[j])*(x-x1[j])+(y-x2[j])*(y-x2[j])<(y1[j]*y1[j]))
					{
						printf("Point %ld is contained in figure %ld\n",d,j+1);
						flag=0;
					}
				}
				else
				{
					mid=(x1[j]+x2[j]+x3[j])/3.0;
					mid1=(y1[j]+y2[j]+y3[j])/3.0;
					
					xa=((y1[j]-y2[j])*x+(x2[j]-x1[j])*y+(x1[j]*y2[j]-x2[j]*y1[j]))/((y1[j]-y2[j])*mid+(x2[j]-x1[j])*mid1+(x1[j]*y2[j]-x2[j]*y1[j]));
					xb=((y2[j]-y3[j])*x+(x3[j]-x2[j])*y+(x2[j]*y3[j]-x3[j]*y2[j]))/((y2[j]-y3[j])*mid+(x3[j]-x2[j])*mid1+(x2[j]*y3[j]-x3[j]*y2[j]));
					xc=((y1[j]-y3[j])*x+(x3[j]-x1[j])*y+(x1[j]*y3[j]-x3[j]*y1[j]))/((y1[j]-y3[j])*mid+(x3[j]-x1[j])*mid1+(x1[j]*y3[j]-x3[j]*y1[j]));

					if(xa>0 && xb>0 && xc>0)
					{
						printf("Point %ld is contained in figure %ld\n",d,j+1);
						flag=0;
					}
				}

			}
		}
		if(flag)
			printf("Point %ld is not contained in any figure\n",d);
		d++;
	}
	return 0;
}