#include<stdio.h>
#include<math.h>

#define MAX 1000000

long count[MAX];
long temp[MAX];

long check_prime(long n)
{
	long i;

	if(n==1)
		return 0;
	if(n==2)
		return 1;
	if( (n%2)==0 )
		return 0;

	for(i=3; i*i<=n; i+=2)
		if( (n%i)==0 )
			return 0;

		return 1;
}

void init(void )
{
	long i, j, M, hold;

	hold = 0;
	temp[2] = count[2] = 1;
	for(i=3; i<=MAX; i++)
	{
		M = sqrt(i);

		if(check_prime(i) == 1)
			temp[i] = 1;
		else
		{
			for(j=2; j<=M; j++)
			{
				if( (i%j) == 0)
				{
					hold = j;
					break;
				}
			}
			temp[i] = temp[hold] + temp[i/hold];
		}
		count[i] = count[i-1] + temp[i];
	}

	return ;
}

int main()
{
	long n;

	init();
	while(scanf("%ld", &n)==1)
		printf("%ld\n", count[n]);

	return 0;
}