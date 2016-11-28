#include<stdio.h>
#include<algorithm>
using namespace std;
long t,n,a[10050],cs=1,i;
bool flag;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		sort(a,a+n);


		for(i=0;i<n-1;i++)
		{
			if(a[i]==a[i+1])
				a[i]=n-a[i]-1;
		}
		sort(a,a+n);
		flag=1;
		for(i=0;i<n;i++)
			if(a[i]!=i)
			{
				flag=0;
				break;
			}
		if(flag)
			printf("Case %ld: yes\n",cs++);
		else
			printf("Case %ld: no\n",cs++);
	}
	return 0;
}