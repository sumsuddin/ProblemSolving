#include<stdio.h>
bool st[1000005];
long i,sum,p;
int main()
{
	for(i=0;i<1000001;i++)
	{
		p=i;
		sum=0;
		while(p)
		{
			sum+=p%10;
			p/=10;
		}
		st[i+sum]=1;
	}
	for(i=0;i<1000001;i++)
	{
		if(st[i]==0)
			printf("%ld\n",i);
	}
	return 0;
}