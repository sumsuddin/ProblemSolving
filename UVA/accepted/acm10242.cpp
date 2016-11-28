#include<stdio.h>
#include<math.h>
double xx,yy,sx,sy,x[15],y[15];
long i,j;
int main()
{
	bool flag;
	while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3]))
	{
		xx=sx=sy=yy=0;
		for(i=0;i<4;i++)
			for(j=i+1;j<4;j++)
			{
				if(fabs(x[i]-x[j])<1e-8 && fabs(y[i]-y[j])<1e-8)
				{
					if(x[i]<99999999)
						xx=x[i];yy=y[i];
					x[i]=x[j]=y[i]=y[j]=100000000;
				}
			}
		flag=1;
		for(i=0;i<4;i++)
			if(x[i]<99999999)
				sx+=x[i],sy+=y[i],flag=0;
		if(flag)
			printf("%.3lf %.3lf\n",xx,yy);
		else
			printf("%.3lf %.3lf\n",sx-xx+1e-8,sy-yy+1e-8);
	}
	return 0;
}