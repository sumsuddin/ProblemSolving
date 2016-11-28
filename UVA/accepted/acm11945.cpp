#include<stdio.h>
long i,n,p=1,t;
double s,sum;
int main()
{
	scanf("%ld",&n);

	while(n--)
	{
		sum=0;
		for(i=0;i<12;i++)
		{
			scanf("%lf",&s);
			sum+=s;
		}
		sum/=12;
		i=(long)sum;
		t=(long)(sum/1000);
		sum-=i;
		i=i%1000;
		sum+=i;
		if(t)
			printf("%ld $%ld,%.2lf\n",p++,t,sum);
		else
			printf("%ld $%.2lf\n",p++,sum);
	}
	return 0;
}