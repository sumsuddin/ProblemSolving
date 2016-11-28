#include<stdio.h>
#include<math.h>

#define MAX 5000005
long st[MAX],r,sq,k,n;
bool bu[MAX];

long fun(long a)
{
	if(a==3)
		return 3;

	r=0;
	if(a%2==0)
	{
		r+=2;
		while(a%2==0)
			a/=2;
	}
	sq=(long)sqrt(a);
	for(k=3;a>2 && k<=sq;k+=2)
	{
		if(a%k==0)
		{
			while(a%k==0)
				a/=k;
			r+=k;
		}
	}
	if(a>2)
		r+=a;

	return r;
}

int main()
{
	long i,j,m,n;

	bu[0]=1;
	bu[1]=1;

	for(i=4;i<5000001;i+=2)
		bu[i]=1;

	for(i=3;i<2237;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=i*i;j<5000001;j+=i+i)
				bu[j]=1;
		}
	}

	st[0]=0;
	st[1]=0;
	st[2]=1;

	for(i=3;i<5000001;i++)
	{
		if(bu[fun(i)]==0)
			st[i]=st[i-1]+1;
		else
			st[i]=st[i-1];
	}

	while(scanf("%ld",&m),m)
	{
		scanf("%ld",&n);
		printf("%ld\n",st[n]-st[m-1]);
	}
	return 0;
}