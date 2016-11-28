#include<stdio.h>
long i,c[20],n,flag;
int main()
{
	c[1]=1;
	for(i=1;i<11;i++)
		c[i+1]=c[i]*(2*(2*i+1))/(i+2);
	while(~scanf("%ld",&n))
	{
		if(flag)
			printf("\n");
		else
			flag=1;
		printf("%ld\n",c[n]);
	}
	return 0;
}