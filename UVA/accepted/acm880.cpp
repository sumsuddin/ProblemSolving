#include<stdio.h>
#include<math.h>
long n,x,y;
int main()
{
	while(~scanf("%ld",&n))
	{
		x=(-1+(long)sqrt(1+8*n))/2;
		
		y=(x*(x+1))/2;

		n-=y;

		if(n==0)
			printf("1/%ld\n",x);
		else
			printf("%ld/%ld\n",x+2-n,n);
	}
	return 0;
}