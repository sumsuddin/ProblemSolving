#include<stdio.h>
#include<math.h>
long i,p,j,ndib[100010],sdib[100010],a,b,k,g,h,t;

int main()
{
	sdib[1]=1;
	ndib[1]=1;


	for(i=2;i<100001;i++)
	{
		p=(long)sqrt(i);
		for(j=1;j<=p;j++)
			if(i%j==0)
			{
				sdib[i]+=j;
				sdib[i]+=i/j;
				ndib[i]+=2;
			}
		if(i==p*p)
		{
			ndib[i]--;
			sdib[i]-=p;
		}
	}

	scanf("%ld",&t);
	while(t--)
	{
		g=h=0;
		scanf("%ld%ld%ld",&a,&b,&k);
		for(i=a;i<=b;i++)
		{
			if(i%k==0)
			{
				g+=ndib[i];
				h+=sdib[i];
			}
		}
		printf("%ld %ld\n",g,h);
	}

	return 0;
}