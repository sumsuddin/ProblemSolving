#include<stdio.h>
#include<math.h>


int main()
{
	long int n,i,j,pp=1,sum,p,c,st[100000];
		st[0]=2;

	for(i=2;i<32800;i++)
	{
		sum=1;
		p=(long int)sqrt(i);
		p++;

		if(!(i%2))
			continue;
		for(j=3;j<p;j++)
		{
			c=i%j;
			if(c==0)
			{
				sum=0;
				break;
			}
		}

		if(sum)
			st[pp++]=i;
	}

	while(scanf("%ld",&n)==1)
	{
		if(n==0)
			break;
		p=0;
		for(i=0;st[i]<=n;i++)
		{
			for(j=i;st[j]<=n;j++)
				if(n==(st[i]+st[j]))
					p++;
		}
		printf("%ld\n",p);
	}
	return 0;
}