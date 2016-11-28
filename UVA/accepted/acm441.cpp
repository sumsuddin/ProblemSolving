#include<stdio.h>
#include<algorithm>
using namespace std;
long a[50],i,j,k,l,n,m,p;
bool flag=1;
int main()
{
	while(scanf("%ld",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		if(flag)
			flag=0;
		else
			printf("\n");

		sort(a,a+n);

		for(i=0;i<n-5;i++)
			for(j=i+1;j<n-4;j++)
				for(k=j+1;k<n-3;k++)
					for(l=k+1;l<n-2;l++)
						for(m=l+1;m<n-1;m++)
							for(p=m+1;p<n;p++)
								printf("%ld %ld %ld %ld %ld %ld\n",a[i],a[j],a[k],a[l],a[m],a[p]);
	}
	return 0;
}