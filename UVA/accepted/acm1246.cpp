#include<stdio.h>
#include<math.h>
long i,j,l,h,sum,t,div[10010],sq;
bool bu[20000],flag;
int main()
{
	bu[0]=1;
	bu[1]=1;

	for(i=4;i<10001;i+=2)
		bu[i]=1;

	for(i=3;i<10001;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=2*i;j<10001;j+=i)
				bu[j]=1;
		}
	}
	div[2]=2;
	for(i=3;i<=10001;i++)
	{
		div[i]=2;
		if(bu[i])
		{
			sq=sqrt(i);
			for(j=2;j<=sq;j++)
				if(i%j==0)
					div[i]+=2;
			if(sq*sq==i)
				div[i]--;
		}
	}

	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&l,&h);

		if(l>h)
		{
			i=l;
			l=h;
			h=i;
		}
		flag=0;
		for(i=l;i<=h;i++)
		{
			if(bu[div[i]]==0)
			{
				if(flag)
					printf(" ");
				else
					flag=1;
				printf("%ld",i);
			}
		}
		if(flag==0)
			printf("-1\n");
		else
			printf("\n");
	}
	return 0;
}