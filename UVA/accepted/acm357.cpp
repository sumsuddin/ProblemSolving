#include<stdio.h>

long long coin[]={1,5,10,25,50},value[30010],mx=30005,i,j,n;

int main()
{
	value[0]=1;

	for(i=0;i<5;i++)
	{
		for(j=coin[i];j<mx;j++)
			value[j]+=value[j-coin[i]];
	}
	while(~scanf("%lld",&n))
	{
		if(value[n]==1)
			printf("There is only 1 way to produce %lld cents change.\n",n);
		else
			printf("There are %lld ways to produce %lld cents change.\n",value[n],n);
	}
	return 0;
}