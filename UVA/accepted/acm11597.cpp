#include<stdio.h>
long n,cs=1;
int main()
{
	while(scanf("%ld",&n) && n)
	{
		printf("Case %ld: %ld\n",cs++,n/2);
	}
	return 0;
}