#include<stdio.h>
#include<math.h>
long long t,n,m,k,sum,cake[1050],drink[1050],a,mn,ck,dr,cs=1,i;
int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&k);

		sum=0;
		for(i=0;i<m;i++)
			scanf("%lld",&cake[i]),sum+=cake[i];
		for(i=0;i<k;i++)
			scanf("%lld",&drink[i]),sum+=drink[i];

		for(i=0;i<n-m-k;i++)
			scanf("%lld",&a),sum+=a;


		mn=cake[0]*n-sum;
		if(mn<0)
			mn=-mn;
		ck=cake[0];
		for(i=1;i<m;i++)
		{
			a=(n*cake[i]-sum);
			if(a<0)
				a=-a;
			if(a<mn || (a==mn && ck>cake[i]))
			{
				mn=a;
				ck=cake[i];
			}
		}

		mn=drink[0]*n-sum;
		if(mn<0)
			mn=-mn;

		dr=drink[0];
		for(i=1;i<k;i++)
		{
			a=(n*drink[i]-sum);
			if(a<0)
				a=-a;
			if(a<mn || (a==mn && dr>drink[i]))
			{
				mn=a;
				dr=drink[i];
			}
		}

		printf("Case #%lld: %lld %lld\n",cs++,ck,dr);
	}
	return 0;
}