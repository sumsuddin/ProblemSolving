#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

long i,j,st[10210],d,n,m,p,q;
int main()
{
	while(~scanf("%ld",&n))
	{
		d=921000005;
		for(i=0;i<n;i++)
			scanf("%ld",&st[i]);

		sort(st,st+n);

		scanf("%ld",&m);

		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(st[i]+st[j]==m)
				{
					p=st[i];
					q=st[j];
				}
				else
				 if(m<st[i]+st[j])
					break;

			}
		}
		printf("Peter should buy books whose prices are %ld and %ld.\n\n",p,q);
	}
	return 0;
}