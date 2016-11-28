#include<stdio.h>
long a,n,sum,ma;
int main()
{
	while(scanf("%ld",&n) && n)
	{
		sum=ma=0;
		while(n--)
		{
			scanf("%ld",&a);
			sum+=a;
			if(sum>ma)
				ma=sum;
			else
				if(sum<0)
					sum=0;
		}
		if(ma==0)
			printf("Losing streak.\n");
		else
			printf("The maximum winning streak is %ld.\n",ma);
	}
	return 0;
}
