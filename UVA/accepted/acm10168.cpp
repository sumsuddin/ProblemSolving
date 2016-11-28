#include<stdio.h>
long n,i,j,m,st[1000000],ls;
bool bu[10000050];

void cong(long a)
{
	m=a/2+1;
	for(i=0;st[i]<m;i++)
	{
		if(bu[a-st[i]]==0)
		{
			printf(" %ld %ld\n",st[i],a-st[i]);
			return;
		}
	}
}

int main()
{
	bu[0]=1;
	bu[1]=1;

	for(i=4;i<10000001;i+=2)
		bu[i]=1;

	for(i=3;i<10000001;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=3*i;j<10000001;j+=(2*i))
				bu[j]=1;
		}
	}
	st[0]=2;ls=1;
	for(i=3;i<=10000000;i+=2)
		if(bu[i]==0)
			st[ls++]=i;

	while(~scanf("%ld",&n))
	{
		if(n<8)
			printf("Impossible.\n");
		else
			if(n%2==0)
			{
				printf("%ld %ld",2,2);
				cong(n-4);
			}
			else
			{
				printf("2 3");
				cong(n-5);
			}		
	}

	return 0;
}