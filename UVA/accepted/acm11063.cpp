#include<stdio.h>
#include<algorithm>
using namespace std;
long cs=1,n,a[110],i,j,d;
bool flag,dif[1000100];
int main()
{
	while(~scanf("%ld",&n))
	{
		for(i=0;i<1000000;i++)
		{
			if(dif[i])
				dif[i]=0;
		}
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		flag=0;

		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(i!=j)
					if(a[i]>a[j])
					{
						flag=1;
						break;
					}
				d=a[j]+a[i];
				if(dif[d] || a[i]<1 || a[j]<1)
				{
					flag=1;
					break;
				}
				else
					dif[d]=1;
			}
			if(flag)
				break;
		}
		if(flag)
			printf("Case #%ld: It is not a B2-Sequence.\n\n",cs++);
		else
			printf("Case #%ld: It is a B2-Sequence.\n\n",cs++);
	}
	return 0;
}