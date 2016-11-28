#include<stdio.h>
long t,n,sum,lst,i,cs=1;
bool bn[100];
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		lst=0;
		while(n)
		{
			bn[lst++]=(bool)(n%2);
			n/=2;
		}
		sum=0;
		bn[lst]=0;
		for(i=0;i<=lst;i++)
		{
			sum+=bn[i];
			if(bn[i]==0 && sum)
			{
				bn[i]=1;
				sum--;
				for(n=i-1;n>=sum;n--)
					bn[n]=0;
				while(sum--)
					bn[sum]=1;
				break;
			}
		}
		if(bn[lst])
			lst++;
		sum=1;
		n=0;
		for(i=0;i<lst;i++)
		{
			n+=bn[i]*sum;
			sum*=2;
		}
		printf("Case %ld: %ld\n",cs++,n);
	}
	return 0;
}