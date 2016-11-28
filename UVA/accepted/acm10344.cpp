#include<stdio.h>
long a[10],i;
bool flag;

void call(long sum,long vs)
{
	if(flag)
		return;

	if(vs==31)
	{
		if(sum==23)
			flag=1;
		return;
	}
	long i;
	for(i=0;i<5 && flag==0;i++)
	{
		if((vs>>i & 1)==0 && flag==0)
		{
			call(sum+a[i],vs|(1<<i));
			call(sum-a[i],vs|(1<<i));
			call(sum*a[i],vs|(1<<i));

		}
	}
}

int main()
{
	while(scanf("%ld%ld%ld%ld%ld",&a[0],&a[1],&a[2],&a[3],&a[4]) && (a[0] || a[1] || a[2] || a[3] || a[4]))
	{
		flag=0;
		for(i=0;i<5 && flag==0;i++)
		{
			call(a[i],1<<i);
		}
		if(flag)
			printf("Possible\n");
		else
			printf("Impossible\n");
	}
	return 0;
}
