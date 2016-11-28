#include<stdio.h>
#include<algorithm>
using namespace std;
long i,j,sum,a[110],half,t,n;
bool bu[100000];
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);
		sum=0;

		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			sum+=a[i];
		}
		sort(a,a+n);
		half=sum/2;
		for(i=0;i<=half;i++)
			bu[i]=0;

		bu[0]=1;
		for(i=0;i<n;i++)
		{
			for(j=half-a[i];j>=0;j--)
				if(bu[j] && j+a[i]<=half)
					bu[j+a[i]]=1;
		}

		for(i=half;i>=0;i--)
			if(bu[i])
			{
				printf("%ld\n",sum-2*i);
				break;
			}
	}
	return 0;
}