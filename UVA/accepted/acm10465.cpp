#include<stdio.h>
#define swap(m,n) m^=n^=m^=n
long i,mx,x,min,a,b,t;
int main()
{
	while(~scanf("%ld%ld%ld",&a,&b,&t))
	{
		if(a>b)
			swap(a,b);

		mx=t/a;

		min=t%a;
		x=t/b;
		for(i=1;i<=x;i++)
		{
			if(((t-(i*b))%a)<min)
			{
				min=(t-(i*b))%a;
				mx=i+(t-(i*b))/a;
			}
		}
		printf("%ld",mx);
		if(min)
			printf(" %ld\n",min);
		else
			printf("\n");
	}
	return 0;
}