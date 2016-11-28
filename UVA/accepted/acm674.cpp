#include<stdio.h>

long coin[]={1,5,10,25,50},value[8000],mx=7490,i,j,n,p;

int main()
{
	value[0]=1;

	for(i=0;i<5;i++)
	{
		p++;
		for(j=coin[i];j<mx;j++)
			value[j]+=value[j-coin[i]];
	}
	while(~scanf("%ld",&n))
	{
		printf("%ld\n",value[n]);
	}
	return 0;
}