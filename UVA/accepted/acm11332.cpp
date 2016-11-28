#include<stdio.h>

long int summ(long int *a)
{
	long int b=0;
	while(*a)
	{
		b+=*a%10;
		*a/=10;
	}
	*a=b;
	if(*a>9)
		summ(a);
	else
		return b;
}

int main()
{
	char st[25];
	long int sum,ans,i;
	while(gets(st) && st[0]!='0')
	{
		i=sum=0;
		while(st[i])
		{
			sum+=(st[i]-48);
			i++;
		}

		if(sum>9)
			ans=summ(&sum);

		else
			ans=sum;

		printf("%ld\n",ans);
	}return 0;
}
