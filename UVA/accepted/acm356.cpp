#include<stdio.h>
#include<math.h>
int main()
{
	long i,j,n,sum,k=0;
	while(scanf("%ld",&n)==1)
	{
		if(k)
			printf("\n");
		k=1;

		if(n)
		{
			sum=0;
			j=n;
			for(i=1;i<n;i++)
			{
				while(j && (sqrt(j*j+i*i)>n-.5))
					j--;
				sum+=j;
			}
			printf("In the case n = %ld, %ld cells contain segments of the circle.\nThere are %ld cells completely contained in the circle.\n",n,8*n-4,4*sum);
		}
		else
			printf("In the case n = %ld, 0 cells contain segments of the circle.\nThere are 0 cells completely contained in the circle.\n",n);

	}
	return 0;
}
