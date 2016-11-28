#include<stdio.h>
long m,n,d,cs=1;
int main()
{
	while(scanf("%ld%ld",&m,&n) && (m|| n))
	{
		d=(m/n)-1;
		if(m%n)
			d++;

		if(d<0)
			d=0;
		if(d>26)
			printf("Case %ld: impossible\n",cs++);
		else
			printf("Case %ld: %ld\n",cs++,d);
	}
	return 0;
}