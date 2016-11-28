#include<stdio.h>
long double x1,x2,x3,x4,y4,y1,y2,y3,det,A1,B1,C1,A2,B2,C2;
long t;
int main()
{
	scanf("%ld",&t);
	printf("INTERSECTING LINES OUTPUT\n");
	while(t--)
	{
		scanf("%llf%llf%llf%llf%llf%llf%llf%llf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);

		A1 = y2-y1;
		B1 = x1-x2;
		C1 = A1*x1+B1*y1;

		A2 = y4-y3;
		B2 = x3-x4;
		C2 = A2*x3+B2*y3;


		det = A1*B2 - A2*B1;

		if(det==0.0)
		{
			if(C1/A1==C2/A2)
				printf("LINE\n");
			else
				printf("NONE\n");
		}
		else
			printf("POINT %.2llf %.2llf\n",(B2*C1 - B1*C2)/det,(A1*C2 - A2*C1)/det);
	}
	printf("END OF OUTPUT\n");
	return 0;
}