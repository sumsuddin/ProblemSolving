#include<stdio.h>
#include<math.h>
long long i,j,lst,t,prm[100000],sq,a,b,sum,cs=1;
bool bu[100000];
int main()
{
	scanf("%ld",&t);

	prm[0]=2;
	lst=1;

	for(i=3;i<50000;i+=2)
	{
		if(bu[i]==0)
		{
			prm[lst++]=i;
			for(j=3*i;j<50000;j+=i*2)
				bu[j]=1;
		}
	}

	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		
		if(a==1)
		a++;

		sq=(long)sqrt(b);
		for(i=0;i<=b-a;i++)
			bu[i]=1;

		for(i=0;i<lst && prm[i]<=sq;i++)
		{
			if(a%prm[i]==0 && a/prm[i]!=1)
				j=0;
			else
				j=prm[i]-(a%prm[i]);
			if(j+a==prm[i])
				j+=prm[i];
			for(;j<=b-a;j+=prm[i])
				bu[j]=0;
		}
		sum=0;
		for(i=0;i<=b-a;i++)
			sum+=bu[i];

		printf("Case %lld: %lld\n",cs++,sum);
	}
	return 0;
}
