#include<stdio.h>
long n,r,c;
int main()
{
	scanf("%ld",&n);
	while(n--)
	{
		scanf("%ld%ld",&r,&c);
		if((r%3)==2)
			r--;
		if((c%3)==2)
			c--;
		r/=3;
		c/=3;
		r*=c;
		printf("%ld\n",r);
	}
	return 0;
}