#include<stdio.h>
#include<algorithm>
using namespace std;
long p,pa=1,i,st[50],q,n,m,sum;
int main()
{
	scanf("%ld",&m);

	while(m--)
	{	
		sum=0;
		scanf("%ld%ld%ld",&n,&q,&p);
		for(i=0;i<n;i++)
			scanf("%ld",&st[i]);
		sort(st,st+n);
		for(i=0;i<q && i<n;i++)
		{
			sum+=st[i];
			if(p<sum)
				break;
		}
		printf("Case %ld: %ld\n",pa++,i);
	}
	return 0;
}