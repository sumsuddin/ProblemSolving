#include<stdio.h>
#include<string.h>
#define swap(m,n)m^=n^=m^=n
long long coin[]={5,10,20,50,100,200,500,1000,2000,5000,10000},mx=30001,i,j,value[300000],m,n;

int main()
{
    value[0]=1;
	for(i=0;i<11;i++)
	{
		for(j=coin[i];j<mx;j+=5)
			value[j]+=value[j-coin[i]];
	}
	while(scanf("%lld.%lld",&n,&m) && (n!=0 || m!=0))
	{
		i=(n*100)+m;

		printf("%3lld.%02lld%17lld\n",n,m,value[i]);
	}
	return 0;
}
