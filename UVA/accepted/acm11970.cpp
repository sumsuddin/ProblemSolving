#include<stdio.h>
#include<math.h>
long i,d,x,n,cs=1,t,sq;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		sq=(long)sqrt(n);
		printf("Case %ld:",cs++); 
		for(i=sq;i>0;i--)
		{
			x=n-i*i;

			d=(long)sqrt(n-x);
			if(d*d==n-x)
				if(x>0 && x%d==0)
					printf(" %ld",x);
		}

		printf("\n");
	}
	return 0;
}