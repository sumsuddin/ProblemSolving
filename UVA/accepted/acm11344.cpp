#include<stdio.h>
long n,d,t;
bool flag;
char st[10050];
long div(long d)
{
	long i,ex;
	for(i=0,ex=0;st[i];i++)
	{
		ex=ex*10+(st[i]-48);
		ex=ex%d;
	}
	return ex;
}
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		flag=1;
		scanf("%s",st);
		scanf("%ld",&n);
		while(n--)
		{
			scanf("%ld",&d);
			if(flag && div(d))
				flag=0;
		}
		if(flag)
			printf("%s - Wonderful.\n",st);
		else
			printf("%s - Simple.\n",st);
	}
	return 0;
}