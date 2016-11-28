#include<stdio.h>
#include<algorithm>
using namespace std;
#define swap(m,n) m^=n^=m^=n
long m,n,i,j,a[20005];

void rev(long *min)
{
	j=m-1;
	*min=m/2;
	for(i=0;i<*min;i++,j--)
		swap(a[i],a[j]);
}

int main()
{

long min;
	scanf("%ld",&n);
	while(n--)
	{
		scanf("%ld",&m);


		for(i=0;i<m;i++)
			scanf("%ld",&a[i]);

		sort(a,a+m);
		rev(&min);

		min=0;
		for(i=2;i<m;i+=3)
			min+=a[i];
		printf("%ld\n",min);
	}
	return 0;
}
