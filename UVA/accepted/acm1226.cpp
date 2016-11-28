#include<stdio.h>
long n,m,t,i;
char st[2050];
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%s",&n,st);

		m=0;

		for(i=0;st[i];i++)
		{
			m=m*10+st[i]-'0';
			m%=n;
		}
		printf("%ld\n",m);
	}
	return 0;
}