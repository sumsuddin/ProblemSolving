#include<stdio.h>
long i,sum,hp,h,l,flag=0,aa[1000050];
long hpy(long a)
{
	sum=0;
	hp++;
	while(a)
		sum+=(a%10)*(a%10),a/=10;
	if(sum<10)
	{
		if(sum==1 || sum==7)
			return hp+aa[sum];
		else
			return 0;
	}
	else
		hpy(sum);
}

int main()
{
	aa[1]=1;
	aa[7]=6;
	for(i=8;i<1000000;i++)
	{
		hp=0;
		aa[i]=hpy(i);
	}
	while(~scanf("%ld%ld",&l,&h))
	{
		if(flag)
			printf("\n");
		else
			flag=1;
		for(i=l;i<=h;i++)
			if(aa[i])
				printf("%ld %ld\n",i,aa[i]);
	}
	return 0;
}

