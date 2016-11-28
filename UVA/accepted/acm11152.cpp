#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846264338327950288419716939937510
int main()
{
	long double s,a,b,c,p,r,area3,area2,area1;

	while(scanf("%llf%llf%llf",&a,&b,&c)==3)
	{
		s=(a+b+c)*.5;
		p=s*(s-a)*(s-b)*(s-c);
		r=sqrt(p)/s;
		area3=pi*r*r;
		area2=sqrt(p)-area3;
		r=(a*b*c)/(4*sqrt(p));
		area1=(pi*r*r)-area2-area3;
		printf("%.4llf %.4llf %.4llf\n",area1,area2,area3);
	}
	return 0;
}