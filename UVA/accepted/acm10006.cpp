#include<stdio.h>
long n,st[70000];
int main()
{
	st[561]=1;
	st[1105]=1;
	st[1729]=1;
	st[2465]=1;
	st[2821]=1;
	st[6601]=1;
	st[8911]=1;
	st[10585]=1;
	st[15841]=1;
	st[29341]=1;
	st[41041]=1;
	st[46657]=1;
	st[52633]=1;
	st[62745]=1;
	st[63973]=1;
	while(scanf("%ld",&n),n)
	{
		if(st[n])
			printf("The number %ld is a Carmichael number.\n",n);
		else
			printf("%ld is normal.\n",n);
	}
	return 0;
}