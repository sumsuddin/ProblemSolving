#include<stdio.h>
#define swap(m,n) m^=n^=m^=n
int main()
{
	long n,m,i,j,a[550],sum;

	scanf("%ld",&n);

	while(n--)
	{
		scanf("%ld",&m);
		sum=0;
		i=m;
		while(i--)
			scanf("%ld",&a[i]);

		for(i=0;i<m;i++)
		{
			for(j=i+1;j<m;j++)
				if(a[i]>a[j])
					swap(a[i],a[j]);
		}

		i=m/2;

		while(m--)
		{
			if(a[m]>a[i])
				sum+=(a[m]-a[i]);
			else
				sum+=(a[i]-a[m]);
		}
		printf("%ld\n",sum);
	}
	return 0;
}