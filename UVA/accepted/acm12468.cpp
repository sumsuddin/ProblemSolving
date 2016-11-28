#include<stdio.h>
long a,b,n,d;
int main()
{
	while(scanf("%ld%ld",&n,&d))
	{
		if(n==-1 && d==-1)
			break;

		if(n>d)
		{
			a=n;
			n=d;
			d=a;
		}

		a=99-d+n+1;
		b=d-n;
		if(a<0)
			a*=-1;
		if(b<0)
			b*=-1;
		if(a>b)
			printf("%ld\n",b);
		else
			printf("%ld\n",a);
	}
	return 0;
}