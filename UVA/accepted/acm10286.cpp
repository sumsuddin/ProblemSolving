#include<stdio.h>
#include<math.h>
#define pi 3.1415926535897932384626433832795
#define con sin((pi/180)*108)/sin((pi/180)*63)
long double n;
int main()
{
	while(~scanf("%llf",&n))
	{

		printf("%.10llf\n",n*con
			);
	}
	return 0;
}