#include<stdio.h>
#include<algorithm>
using namespace std;
long st[2000005],n,i;
int main()
{
	while(scanf("%ld",&n),n)
	{
		
		i=n;
		while(i--)
			scanf("%ld",&st[i]);

		sort(st,st+n);

		for(i=0;i<n;i++)
		{
			if(i)
				printf(" %ld",st[i]);
			else
				printf("%ld",st[i]);
		}
		printf("\n");
	}
	return 0;
}