#include<stdio.h>
int main()
{
	long l,g,n;

	scanf("%ld",&n);
	while(n--)
	{
		scanf("%ld%ld",&g,&l);
		if(l%g)
			printf("-1\n");
		else
			printf("%ld %ld\n",g,l);
	}
	return 0;
}