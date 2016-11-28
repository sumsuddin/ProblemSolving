#include<stdio.h>
long long i,m,d,n;
int main()
{
	while(~scanf("%lld%lld",&n,&m))
	{
		d=1;
		for(i=0;i<=m;i++)
			d*=2;
		if(d>n)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
