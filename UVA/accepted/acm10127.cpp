#include<stdio.h>

long i,ex,j,st[10100],d;

long division()
{
	for(d=0,ex=0;;d++)
	{
		ex=ex*10+1;
		ex=ex%i;
		if(ex==0)
			break;
	}
	return d+1;
}

int main()
{
	st[1]=1;
	for(i=3;i<10000;i+=2)
	{
		if(i%5!=0)
				st[i]=division();
	}
	while(~scanf("%ld",&i))
	{
		printf("%ld\n",st[i]);
	}
	return 0;
}