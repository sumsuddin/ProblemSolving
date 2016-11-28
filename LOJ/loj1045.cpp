#include<stdio.h>
#include<math.h>
double sum,lg[1000060];
long i,t,n,b,cs=1;
int main()
{
	scanf("%ld",&t);

	for(i=1;i<1000001;i++)
		lg[i]=log(i);
	
	while(t--)
	{
		scanf("%ld%ld",&n,&b);
		sum=0;
		for(i=1;i<=n;i++)
			sum+=(lg[i]/lg[b]);
		i=(long)ceil(sum);
		if(i==0)
			i=1;
		printf("Case %ld: %ld\n",cs++,i);
	}
	return 0;
}
