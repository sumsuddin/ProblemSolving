#include<stdio.h>
#include<string.h>
bool sr[10000000];
long step,mod,i,seed,sum,p;
int main()
{
	while(scanf("%ld%ld",&step,&mod)==2)
	{
		sr[0]=1;seed=0;
		for(i=1;i<mod;i++)
		{
			sr[seed=(seed+step)%mod]=1;
		}
		sum=1;
		for(i=1;i<mod;i++)
		{
			sum+=sr[i];
			sr[i]=0;
		}
		if(sum==mod)
			printf("%10ld%10ld    Good Choice\n\n",step,mod);
		else
			printf("%10ld%10ld    Bad Choice\n\n",step,mod);
	}
	return 0;
}