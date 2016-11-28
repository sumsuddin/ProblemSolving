#include<stdio.h>
long a,b,c,d,sum;
int main()
{
	while(scanf("%ld%ld%ld%ld",&a,&b,&c,&d) && (a||b||c||d))
	{
		sum=1080;
		if(a<=b)
			sum+=(40+a-b)*9;
		else
			sum+=(a-b)*9;
		if(c<=b)
			sum+=(40+c-b)*9;
		else
			sum+=(c-b)*9;
		if(c<=d)
			sum+=(40+c-d)*9;
		else
			sum+=(c-d)*9;
		printf("%ld\n",sum);
	}
	return 0;
}