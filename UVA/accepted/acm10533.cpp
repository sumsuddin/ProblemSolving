#include<stdio.h>
#include<math.h>

#define MAX 1000005
long st[MAX],r;
bool bu[MAX];

long fun(long a)
{
	r=0;
	while(a)
	{
		r+=a%10;

		a/=10;
	}
	return r;
}

int main()
{
	long i,j,m,n,p;

	bu[0]=1;
	bu[1]=1;

	for(i=4;i<1000001;i+=2)
		bu[i]=1;

	for(i=3;i<1000001;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=2*i;j<1000001;j+=i)
				bu[j]=1;
		}
	}

	st[0]=0;
	st[1]=0;
	st[2]=1;
	j=1;
	for(i=3;i<1000001;i++)
	{
		if(bu[i]==0 && bu[fun(i)]==0)
			st[i]=st[i-1]+1;
		else
			st[i]=st[i-1];
	}

	scanf("%ld",&p);
	while(p--)
	{
		scanf("%ld%ld",&m,&n);
		printf("%ld\n",st[n]-st[m-1]);
	}
	return 0;
}