#include<stdio.h>
#include<algorithm>
using namespace std;
long t,n,w,k,i,j,sum,com[110],y[110],ans[110],dp[110],mx,ind[110],p,ans1[110],cs=1;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld",&n,&w,&k);
		for(i=0;i<n;i++)
			scanf("%*ld%ld",&y[i]);

		sort(y,y+n);

		for(i=0;i<n;i++)
		{
			ans[i]=dp[i]=0;
			j=i;
			while(j<n && y[i]+w>=y[j])
				dp[i]++,j++;
			ind[i]=j;
		}
		ans[n]=0;

		while(k--)
		{
			mx=0;
			for(i=n-1;i>=0;i--)
			{
				p=dp[i]+ans[ind[i]];
				if(p>mx)
					mx=p;
				ans1[i]=mx;
			}
			for(i=0;i<n;i++)
				ans[i]=ans1[i];
		}
		printf("Case %ld: %ld\n",cs++,ans[0]);
	}
	return 0;
}
