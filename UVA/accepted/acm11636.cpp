#include<stdio.h>
#include<math.h>
int main()
{
	double x,n;
	long p=1;
	while(scanf("%lf",&n) &&n>=0)
	{
		x=log(n)/log(2);

		x=ceil(x);
		printf("Case %ld: %.0lf\n",p++,x);
	}
	return 0;
}