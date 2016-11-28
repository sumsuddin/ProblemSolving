#include<stdio.h>
long t,sum,a;
char st[20];
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%s",st);
		if(st[0]=='d')
		{
			scanf("%ld",&a);
			sum+=a;
		}
		else
			printf("%ld\n",sum);
	}
	return 0;
}