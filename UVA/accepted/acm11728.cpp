#include<stdio.h>
#include<math.h>
long i,j,sq,sum,s[11000],cs=1;
int main()
{
	for(i=1;i<1001;i++)
	{
		sum=1+i;
		if(i%2==0)
		{
			sum+=2;
			sum+=(i/2);
		}
		sq=sqrt(i);
		for(j=3;j<=sq;j++)
		{		
			if(i%j==0)
			{
				sum+=j;
				sum+=(i/j);
			}
		}
		if(sq*sq==i)
			sum-=sq;
		s[sum]=i;
	}
	s[3]=2;
	while(scanf("%ld",&i) && i)
	{
		if(s[i])
			printf("Case %ld: %ld\n",cs++,s[i]);
		else
			printf("Case %ld: -1\n",cs++);
	}
	return 0;
}