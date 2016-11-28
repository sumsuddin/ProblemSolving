#include<stdio.h>
long i,n,fib[500],flag,lst;
int main()
{
	fib[0]=2,fib[1]=3,i=1;
	while(fib[i]<=1000)
	{
		i++;
		fib[i]=fib[i-1]+fib[i-2];
	}
	lst=i+1;

	while(scanf("%ld",&n) && n)
	{
		flag=1;
		for(i=0;i<lst;i++)
			if(fib[i]==n)
			{
				flag=0;
				break;
			}
		if(flag)
			printf("Alicia\n");
		else
			printf("Roberto\n");
	}
	return 0;
}