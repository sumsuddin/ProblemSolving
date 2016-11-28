#include<stdio.h>
#include<string.h>
#include<algorithm>
#define swap(m,n) m^=n^=m^=n

using namespace std;

char st[100];
bool flag;
long long sy[1005],i,j,carry,k,n;


void splt(long long *max,long long *min)
{
	i=*max=*min=0;

	while(n)
	{
		st[i++]=n%10;
		n/=10;
	}
	sort(st,st+i);

	for(j=0;j<i;j++)
		*min=(*min*10)+st[j];
	while(i--)
		*max=(*max*10)+st[i];
}

int main()

{
    long long max,min;
	while(scanf("%lld",&n),n)
	{
		k=flag=0;
		printf("Original number was %lld\n",n);

		while(1)
		{
			splt(&max,&min);

			printf("%lld - %lld = %lld\n",max,min,n=sy[k]=max-min);

			for(i=0;i<k;i++)
				if(sy[k]==sy[i])
				{
					flag=1;
					break;
				}

			if(flag)
			{
				printf("Chain length %lld\n",k+1);
				if(k)
					printf("\n");
				break;
			}
			else
				k++;
		}
	}
	return 0;
}
