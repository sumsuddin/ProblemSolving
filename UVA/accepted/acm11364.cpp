#include<stdio.h>
#define swap(m,n) m^=n^=m^=n
int main()
{
	long n,m,i,j,a[50],sum;
	scanf("%ld",&n);

	while(n--)
	{
		scanf("%ld",&m);
		
		for(i=0;i<m;i++)
			scanf("%ld",&a[i]);

		for(i=0;i<m;i++)
		{
			for(j=i+1;j<m;j++)
			{
				if(a[i]>a[j])
					swap(a[i],a[j]);
			}
		}

		sum=0;
		for(i=1;i<m;i++)
			sum+=(a[i]-a[i-1]);
		sum*=2;
		printf("%ld\n",sum);
	}
	return 0;
}