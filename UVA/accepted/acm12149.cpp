#include<stdio.h>
long a[105],i;
int main()
{
	for(i=1;i<101;i++)
		a[i]=a[i-1]+i*i;

	while(scanf("%ld",&i),i)
		printf("%ld\n",a[i]);
	return 0;
}
