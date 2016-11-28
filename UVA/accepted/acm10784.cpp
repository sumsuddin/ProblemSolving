#include<stdio.h>
#include<math.h>
long n,cs=1;
int main()
{
	while(scanf("%ld",&n) && n)
	{
		n=(ceil)((3.0+sqrt(9.0+(8.0*n)))/2);
		printf("Case %ld: %ld\n",cs++,n);
	}
	return 0;
}