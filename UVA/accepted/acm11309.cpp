#include<stdio.h>
long a[2500],i,n,b,t;
int main()
{
	for(i=0;i<2400;i++)
	{
		b=i;
		n=0;
		while(b)
		{
			n=n*10+(b%10);
			b/=10;
		}
		if(n==i && i%100<60)
			a[i]=1;
	}

	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld:%ld",&i,&b);
		i=i*100+b+1;

		while(1)
		{
			if(a[i])
			{
				b=i%1000;
				n=b%100;
				printf("%ld%ld:%ld%ld\n",i/1000,b/100,n/10,i%10);
				break;
			}
			else
			{
				i++;
				if(i>=2400)
					i=0;
			}
		}
	}
	return 0;
}