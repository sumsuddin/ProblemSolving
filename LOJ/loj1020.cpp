#include<stdio.h>
long t,n,cs=1;
char st[10];
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%s",&n,&st);

		if(st[0]=='A')
		{
			if((n-1)%3==0)
				printf("Case %ld: Bob\n",cs++);
			else
				printf("Case %ld: Alice\n",cs++);
		}
		else
		{
			if(n%3==0)
				printf("Case %ld: Alice\n",cs++);
			else
				printf("Case %ld: Bob\n",cs++);
		}
	}
	return 0;
}