#include<stdio.h>
#include<math.h>
long i,n,prm[4005],ls,t,j,cs=1,a,b,sq;
bool bu[4005],flag;
void pf()
{
	flag=0;
	sq=sqrt(n)+1;
	for(i=0;i<ls && prm[i]<sq;i++)
		if(n%prm[i]==0)
		{
			a=prm[i];
			printf(" = %ld * %ld",prm[i],n/prm[i]);
			if(flag)
			{
				flag=0;
				printf("\n");
				return ;
			}
			flag=1;
		}
}

void sieve()
{
	bu[0]=1;
	bu[1]=1;

	for(i=4;i<4000;i+=2)
		bu[i]=1;

	for(i=3;i<4000;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=3*i;j<4000;j+=(2*i))
				bu[j]=1;
		}
	}
	prm[0]=2;
	ls=1;
	for(i=3;i<4000;i+=2)
		if(bu[i]==0)
			prm[ls++]=i;
}

int main()
{
	sieve();
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);
		printf("Case #%ld: %ld",cs++,n);
		pf();
		if(flag)
		{
			b=a*a;
			while(n%b!=0 && b<n)
				b*=a;
			printf(" = %ld * %ld\n",b,n/b);
		}
	}
	return 0;
}