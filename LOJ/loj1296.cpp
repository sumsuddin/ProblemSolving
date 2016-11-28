#include<stdio.h>

long i,j,t,n,cs=1;


int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		j=0;
		while(n--)
		{
			scanf("%ld",&i);
			while(i%2)
				i/=2;
			j^=i/2;
		}

		if(j)
			printf("Case %ld: Alice\n",cs++);
		else
			printf("Case %ld: Bob\n",cs++);
	}
	return 0;
}