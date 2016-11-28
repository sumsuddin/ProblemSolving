#include<stdio.h>
long cs=1,b,bc,a[50],va[50],t,n,i,j,mn;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		for(i=0;i<36;i++)
			scanf("%ld",&a[i]);

		scanf("%ld",&n);

		printf("Case %ld:\n",cs++);
		while(n--)
		{
			scanf("%ld",&b);
			mn=99999999;
			printf("Cheapest base(s) for number %ld:",b);
			for(i=2;i<37;i++)
			{
				bc=b;

				va[i]=0;
				for(j=0;bc;j++)
				{
					va[i]+=a[(bc%i)];
					bc/=i;
				}
				if(mn>va[i])
					mn=va[i];
			}
			for(i=2;i<37;i++)
				if(va[i]==mn)
					printf(" %ld",i);
			printf("\n");
		}
		if(t)
			printf("\n");
	}
	return 0;
}