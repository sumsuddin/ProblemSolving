#include<stdio.h>

long i,j,prm[1000050],ind[1000050],t,n,cs=1,lst,a;
long long sum;
bool bu[1000050];

int main()
{
	prm[0]=2;
	lst=1;
	for(i=3;i<1000001;i+=2)
		if(bu[i]==0)
		{
			prm[lst++]=i;
			for(j=3*i;j<1000001;j+=2*i)
				bu[j]=1;
		}
	prm[lst++]=1000003;
	ind[0]=1;
	ind[1]=2;
	for(i=2,j=1;i<1000001;i++)
	{
		ind[i]=prm[j];
		if(i%2==0 && bu[i+1]==0)
			j++;
	}

	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);
		sum=0LL;
		for(i=0;i<n;i++)
			scanf("%ld",&a),sum+=ind[a];
		printf("Case %ld: %lld Xukha\n",cs++,sum);
	}
	return 0;
}
