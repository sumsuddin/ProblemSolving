#include<stdio.h>
#include<algorithm>
using namespace std;
long i,n,a[100],chk,t;
bool flag;
void subset(long inc,long sum)
{
	if(sum==chk)
	{
		flag=0;
		return;
	}

	if(inc>=n || sum+a[inc]>chk)
		return ;
	if(flag)
		subset(inc+1,sum+a[inc]);
	if(flag)
		subset(inc+1,sum);
}
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&chk,&n);
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		sort(a,a+n);

		flag=1;
		subset(0,0);
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}