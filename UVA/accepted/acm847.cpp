#include<stdio.h>
#include<math.h>
double n;
long i;

int main()
{
	while(~scanf("%lf",&n))
	{
		for(i=1;;i++)
		{
			if(pow(9,i)*pow(2,i-1)>=n)
			{
				printf("Stan wins.\n");
				break;
			}
			else if(pow(9,i)*pow(2,i)>=n)
			{
				printf("Ollie wins.\n");
				break;
			}
		}
	}
	return 0;
}