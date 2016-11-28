#include<stdio.h>
#include<math.h>
long long i,sum,n,x,sq,t,ss[30];
int main()
{
	scanf("%ld",&t);

    for(n=1;;n++)
    {
		x=(long long)pow(2,n-1)*((long long)pow(2,n)-1);

		sq=(long long)sqrt(x);
		sum=1;
		for(i=2;i<=sq;i++)
			if(x%i==0)
				sum+=i+x/i;
		if(sum==x)
			ss[n]=1;
		else
			ss[n]=0;
		if(x>(long long )pow(2,33))
		break;
	}		

	while(t--)
	{
		scanf("%ld",&n);
		if(t)
		scanf(",");
		if(ss[n])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
