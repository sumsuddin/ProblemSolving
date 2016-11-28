#include<stdio.h>

long long coin[50],value[30010],mx=30005,i,j,n;

int main()
{
	for(i=1;i<22;i++)
		coin[i]=i*i*i;

	value[0]=1;

	for(i=1;i<22;i++)
	{
		for(j=coin[i];j<mx;j++)
			value[j]+=value[j-coin[i]];
	}
	while(~scanf("%lld",&n))
	{
                            printf("%lld\n",value[n]);
	}
	return 0;
}
