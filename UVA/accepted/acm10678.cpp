#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846264338327950288419716939937510
int main()
{
	long double a,b;
	long n;

	scanf("%ld",&n);
	while(n--)
	{
		scanf("%llf%llf",&a,&b);
		b/=2;
		a/=2;

		a=sqrt(b*b-a*a);
		a=pi*a*b;
		printf("%.3llf\n",a);
	}
	return 0;
}