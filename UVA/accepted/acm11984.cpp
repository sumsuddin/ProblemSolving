#include<stdio.h>
long p=1,n;
double c,f;
int main()
{
	scanf("%ld",&n);

	while(n--)
	{
		scanf("%lf%lf",&c,&f);
		printf("Case %ld: %.2lf\n",p++,c+((5.0/9.0)*f));
	}
	return 0;
}