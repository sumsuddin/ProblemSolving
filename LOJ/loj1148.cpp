#include<stdio.h>
#include<algorithm>
using namespace std;

long i,a[100],n,t,d,bc,cs=1,sum;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		sort(a,a+n);

		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=a[i]+1;
			bc=d=a[i];
			while(d-- && i+1<n && a[i+1]==bc)
				i++;
		}
		if(sum<n)
			printf("Case %ld: %ld\n",cs++,n);
		else
			printf("Case %ld: %ld\n",cs++,sum);
	}
	return 0;
}