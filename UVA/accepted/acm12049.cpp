#include<stdio.h>
#include<algorithm>
using namespace std;
long i,j,g,h,sum,a[10010],b[10010],t,m,n;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		for(i=0;i<m;i++)
			scanf("%ld",&b[i]);
		sum=g=h=0;

		sort(a,a+n);
		sort(b,b+m);

		for(i=0;g<n && h<m;i++)
		{
			if(a[g]!=b[h])
			{
				sum++;
				if(a[g]>b[h])
					h++;
				else
					g++;
			}
			else
			{
				g++;
				h++;
			}
		}
		sum+=n-g;
		sum+=m-h;

		printf("%ld\n",sum);
	}
	return 0;
}