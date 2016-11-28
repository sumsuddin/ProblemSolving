#include<stdio.h>
long in[100],i,n,d,t,mx,cs=1;
long long bu[100],sum;

void get(long long p)
{
	if(p==0)
		return;
	if(p<0)
		i=1;
	else
		i=0;
	sum=0;
	for(;i<32;i+=2)
	{
		sum+=bu[i];
		if(((sum<0)?-sum:sum )>=((p<0)?-p:p))
		{
			in[i]=1;
			if(mx<i)
				mx=i;
			get(p-bu[i]);
			break;
		}
	}
}

int main()
{
	n=d=1;
	bu[0]=1;
	for(i=1;i<32;i++)
		bu[i]=(n*=2)*(d*=-1);

	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<32;i++)
			in[i]=0;

		sum=mx=0;
		if(n)
			get(n);

		printf("Case #%ld: ",cs++);
		for(i=mx;i>=0;i--)
			printf("%ld",in[i]);
		printf("\n");
	}
	return 0;
}