#include<stdio.h>
long n,m,t,sum,c;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		sum=0;
		scanf("%ld%ld",&n,&m);
		while(n>=m)
		{
			sum+=n/m;
			c=n%m;
			n/=m;
			n+=c;
		}
		if(n<2)
			printf("%ld\n",sum);
		else
			printf("cannot do this\n");
	}
	return 0;
}