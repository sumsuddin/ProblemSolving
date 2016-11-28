#include<stdio.h>
#include<math.h>

long i,t,j,sum,a[550],prn[550],mid,lb,ub,s,k,bcup,n;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&k);
		i=sum=0;
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]),sum+=a[i];

		ub=sum;
		lb=0;
		while(lb+1<ub)
		{
			mid=(lb+ub)/2;
			bcup=sum;
			for(i=0,j=1;i<k;i++)
			{
				s=0;
				while(s+a[j]<=mid && j<=n)
					s+=a[j++];
				bcup-=s;
			}
			if(bcup>0)
				lb=mid;
			else
				ub=mid;
		}
		prn[k]=n;
		for(i=k-1,j=n;i>=0;i--)
		{
			s=0;
			while(s+a[j]<=ub && j>i)
				s+=a[j--];
			prn[i]=j;
		}
		printf("%ld",a[1]);
		for(i=1,j=2;i<=k;i++)
		{
			while(j<=prn[i] && j<=n)
				printf(" %ld",a[j++]);
			if(i<k)
				printf(" /");
		}
		printf("\n");
	}
	return 0;
}