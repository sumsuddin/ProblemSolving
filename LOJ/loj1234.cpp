#include<stdio.h>
double fn[1000060],sum;
long i,d,lst,l,n,t,cs=1;
int main()
{
	fn[0]=sum=0;
	lst=1;
	for(i=1;i<=100000000;i++)
	{
		sum+=1.0/i;
		if(i%100==0)
			fn[lst++]=sum;
	}

	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);
		l=n/100;
		sum=fn[l];
		d=n%100;
		l*=100;
		for(i=1;i<=d;i++)
			sum+=1.0/(l+i);
		printf("Case %ld: %.10lf\n",cs++,sum+1e-12);
	}
	return 0;
}