#include<stdio.h>
long ex,s,n,c,t,cs=1;
long div(long d,long c)
{
	s=ex=0;
	while(ex<d)
		s++,ex=ex*10+c;

	while(ex%d!=0)
	{
		ex%=d;
		s++;
		ex=ex*10+c;
	}
	return s;
}
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&c);

		printf("Case %ld: %ld\n",cs++,div(n,c));
	}
	return 0;
}