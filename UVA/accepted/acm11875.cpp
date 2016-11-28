#include<stdio.h>
int main()
{
	long a[15],p,q=1,n,m;
	scanf("%ld",&n);

	while(n--)
	{
		scanf("%ld",&m);

		p=m/2;
		while(m--)
			scanf("%ld",&a[m]);

		printf("Case %ld: %ld\n",q++,a[p]);
	}
	return 0;
}