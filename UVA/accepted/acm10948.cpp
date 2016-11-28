#include<stdio.h>
#include<math.h>
#define MAX 1000005
long st[MAX];
bool bu[MAX],flag;

int main()
{
	long i,j,m,n;

	bu[0]=1;
	bu[1]=1;

	for(i=4;i<MAX;i+=2)
		bu[i]=1;

	for(i=3;i<MAX;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=3*i;j<MAX;j+=2*i)
				bu[j]=1;
		}
	}

	st[0]=2;
	j=1;
	for(i=3;i<MAX;i+=2)
	{
		if(bu[i]==0)
			st[j++]=i;
	}


	while(scanf("%ld",&m),m)
	{
		n=m/2+1;
		flag=1;
		for(i=0;st[i]<n;i++)
		{
			if(bu[m-st[i]]==0)
			{
				printf("%ld:\n%ld+%ld\n",m,st[i],m-st[i]);
				flag=0;
				break;
			}

		}
		if(flag)
			printf("%ld:\nNO WAY!\n",m);
	}
	return 0;
}