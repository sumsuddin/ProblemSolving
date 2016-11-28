#include<stdio.h>
#include<math.h>
long bigmod(long b,long p,long m) 
{
	if (p == 0)
	return 1;
	else if (p%2 == 0)
	return ((long)pow(bigmod(b,p/2,m),2)) % m;
	else
	return ((b % m) * bigmod(b,p-1,m)) % m;
}
int main()
{
	long m,b,p;
	while(scanf("%ld%ld%ld",&b,&p,&m)==3)
	{
		printf("%ld\n",bigmod(b,p,m));
	}
	return 0;
}