#include<stdio.h>
#include<math.h>
long check[1050000],i,p,sum,sq,t,n;
bool bu[1050000];

long div(long ii)
{
	if(ii==1)
		return 1;
	else
	{
		sum=0;
		sq=(long)sqrt(ii);
		for(t=1;t<=sq && sum<6;t++)
		{
			if(ii%t==0)
				sum+=2;
			if(sum==4)
			{
				if(bu[t]==0 && bu[ii/t]==0)
					return 1;
				else
					return 0;
			}
		}
		if(sq*sq==ii)
			sum--;
	}
	return 0;
}

int main()
{
	bu[0]=1;
	bu[1]=1;

	for(i=4;i<1048600;i+=2)
		bu[i]=1;

	for(i=3;i<1048600;i+=2)
	{
		if(bu[i]==0)
		{
			for(p=2*i;p<1048600;p+=i)
				bu[p]=1;
		}
	}

	for(i=3;i<1048600;i++)
	{
		if(div(i))
			check[i]=1;
	}
	while(~scanf("%ld",&n))
	{
		sum=0;
		while(n--)
		{
			scanf("%ld",&p);
			sum+=check[p];
		}
		printf("%ld\n",sum);
	}
	return 0;
}