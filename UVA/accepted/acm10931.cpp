#include<stdio.h>

void bin(long int *a,long int *c)
{
	long int b;
	b=*a%2;
	*c+=b;
	*a/=2;
	if(*a)
		bin(a,c);
	printf("%ld",b);
}

int main()
{
	long int ans,n;
	while(scanf("%ld",&n),n)
	{
		ans=0;
		printf("The parity of ");
		bin(&n,&ans);
		printf(" is %ld (mod 2).\n",ans);
	}
	return 0;
}
