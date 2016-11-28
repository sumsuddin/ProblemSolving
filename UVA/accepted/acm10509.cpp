#include<stdio.h>
#include<math.h>
int main()
{
	double n,b;
	long a;

	while(scanf("%lf",&n),n)
	{
		a=(long)pow(n,.3333333333333);
		if(pow(a+1,3)<=n)
			a++;

		b=a+(.3333333333333*(n-pow(a,3))/pow(a,2));
		printf("%.4lf\n",b);
	}

	return 0;
}