#include<stdio.h>
#include<math.h>
#define prec 1e-9
double disl,dish,x1,x2,x3,x4,yy1,y2,y3,y4,xl,xh,yh,yl,d1,d2,A1,A2,B1,B2,C1,C2,p1,p2,det;
long n,t,cs=1;
double tern(double x1,double yy1,double x3,double y3,double x4,double y4)
{
    while(sqrt((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4))>=prec)
    {
        xl=(x3+2.0*x4)/3.0;
        yl=(y3+2.0*y4)/3.0;
        
        
        xh=(2.0*x3+x4)/3.0;
        yh=(2.0*y3+y4)/3.0;
        
        disl=(x1-xl)*(x1-xl)+(yy1-yl)*(yy1-yl);
        dish=(x1-xh)*(x1-xh)+(yy1-yh)*(yy1-yh);
        if(disl<dish)
        {
			if((x3-xh)*(x3-xh)+(y3-yh)*(y3-yh)>(x4-xh)*(x4-xh)+(y4-yh)*(y4-yh))
            {
				x4=xh;
				y4=yh;
			}
			else
			{
				x3=xh;
				y3=yh;
			}
        }
        else
        {
			if((x3-xl)*(x3-xl)+(y3-yl)*(y3-yl)>(x4-xl)*(x4-xl)+(y4-yl)*(y4-yl))
            {
				x4=xl;
				y4=yl;
			}
			else
			{
				x3=xl;
				y3=yl;
			}
        }   
    }
    disl=(x1-x3)*(x1-x3)+(yy1-y3)*(yy1-y3);
    dish=(x1-x4)*(x1-x4)+(yy1-y4)*(yy1-y4);
    
    if(disl<dish)
        return sqrt(disl);
    else
        return sqrt(dish);
}

int main()
{
    scanf("%ld",&t);
    
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&yy1,&x2,&y2,&x3,&y3,&x4,&y4);

		A1 = y2-yy1;
		B1 = x1-x2;
		C1 = A1*x1+B1*yy1;

		A2 = y4-y3;
		B2 = x3-x4;
		C2 = A2*x3+B2*y3;


		det = A1*B2 - A2*B1;

		p1=-100000;
		p2=100000;

		d1=10000000;

		if(det!=0.0)
		{
			p1=(B2*C1 - B1*C2)/det;
			p2=(A1*C2 - A2*C1)/det;

			if((x1-p1) * (p1-x2) >=0.0 && (yy1-p2) * (p2-y2)>=0.0 && (x3-p1) * (p1-x4) >=0.0 && (y3-p2) * (p2-y4)>=0.0)
				d1=0.0;
		}
			


        d2=tern(x1,yy1,x3,y3,x4,y4);
		if(d1>d2)
			d1=d2;
        d2=tern(x2,y2,x3,y3,x4,y4);
		if(d1>d2)
			d1=d2;
		d2=tern(x3,y3,x1,yy1,x2,y2);
		if(d1>d2)
			d1=d2;
		d2=tern(x4,y4,x1,yy1,x2,y2);
		if(d1>d2)
			d1=d2;

        printf("Case %ld: %.10lf\n",cs++,d1);
    }
    return 0;
}
/*

  2
  1 1 5 1
  7 7 2 2

  1 1 3 1
  2 2 2 0

*/