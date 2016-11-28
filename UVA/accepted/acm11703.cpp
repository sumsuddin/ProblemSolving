#include<stdio.h>
#include<math.h>
double r,pi=3.14159265358979323846;
long i,x[1000005];

int main()
{
	x[0]=1;
	for(i=1;i<1000001;i++)
	{
		r=(i*pi)/180;

		x[i]=(x[(long)floor(i-sqrt(i))]+x[(long)floor(log(i))]+x[(long)floor(i*pow(sin(i),2))])%1000000;
	}
	while(scanf("%ld",&i) && i>-1)
	{
		printf("%ld\n",x[i]);
	}
	return 0;
}