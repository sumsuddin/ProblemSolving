#include<stdio.h>
long a,b,c,t,cs=1;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld",&a,&b,&c);

		if(a<=20 && b<=20 && c<=20)
			printf("Case %ld: good\n",cs++);
		else
			printf("Case %ld: bad\n",cs++);
	}
	return 0;
}