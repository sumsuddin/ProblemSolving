#include<stdio.h>
#include<algorithm>
using namespace std;
long a[5],t,cs=1;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld",&a[0],&a[1],&a[2]);

		sort(a,a+3);

		if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
			printf("Case %ld: yes\n",cs++);
		else
			printf("Case %ld: no\n",cs++);
	}
	return 0;
}
