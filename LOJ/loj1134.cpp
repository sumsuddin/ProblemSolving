#include<stdio.h>

long i,n,M,t,ans[100050],com[100050],cs=1,a;

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&M);

		ans[0]=0;
		for(i=1;i<=n;i++)
			scanf("%ld",&a),com[i]=(com[i-1]+a)%M;

		for(i=0;i<M;i++)
			ans[i]=-1;

		ans[0]=a=0;
		for(i=1;i<=n;i++)
			a+=++ans[com[i]];


		printf("Case %ld: %ld\n",cs++,a);
	}
	return 0;
}