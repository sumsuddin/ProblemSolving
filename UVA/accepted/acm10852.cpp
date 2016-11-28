#include<stdio.h>
long i,j,n,t;
bool bu[10050];
int main()
{
	bu[0]=1;
	bu[1]=1;

	for(i=4;i<10000;i+=2)
		bu[i]=1;

	for(i=3;i<10000;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=2*i;j<10000;j+=i)
				bu[j]=1;
		}
	}

	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=n/2+1;i<=n;i++)
			if(bu[i]==0)
			{
				printf("%ld\n",i);
				break;
			}
	}
	return 0;
}