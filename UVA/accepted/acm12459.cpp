#include<stdio.h>
long long f[100],n,i;
void fibo()
{
	for(i=3;i<81;i++)
		f[i]=f[i-1]+f[i-2];
}

int main()
{
	f[1]=1,f[2]=2;
	fibo();
	while(~scanf("%lld",&n) && n)
	{
		printf("%lld\n",f[n]);
	}
	return 0;
}