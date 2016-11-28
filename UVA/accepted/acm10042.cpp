#include<stdio.h>
#include<math.h>
bool bu[1000000];
long i,j,a,sq,ls,in,ret,t,st;

long count (long a)
{
	ret=0;
	while(a)
		ret+=a%10,a/=10;
	return ret;
}
int main()
{

	bu[0]=1;
	bu[1]=1;

	for(i=4;i<32000;i+=2)
		bu[i]=1;

	for(i=3;i<32000;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=3*i;j<32000;j+=(2*i))
				bu[j]=1;
		}
	}
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&st);
		for(i=st+1;i<1000000300;i++)
		{
			a=i;
			ls=0;

			in=count(a);

			sq=(long)sqrt(a)+1;

			if(a%2==0)
			{
				while(a%2==0)
					a/=2,ls+=2;
			}

			for(j=3;j<=sq;j+=2)
			{
				if(bu[j]==0)
				{
					while(a%j==0)
					{
						a/=j;
						ls+=count(j);
					}
				}
			}
			if(a>1)
				ls+=count(a);
			if(ls==in && i!=a && i!=2)
			{
				printf("%ld\n",i);
				break;
			}
		}
	}
	return 0;
}