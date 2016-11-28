#include<stdio.h>
#include<math.h>
long i,j,bu[1000000],h,mx,sum,m,n,d,flag;
int main()
{
	while(~scanf("%ld%ld",&n,&m))
	{
		h=(long)pow((double)(n+m),(1.0/3.0))+1;

		sum=mx=0;

		for(i=1;i<=h;i++)
		{
			for(j=i+1;j<=h;j++)
			{
				d=i*i*i+j*j*j;
				if(d<=n+m && d>=n)
				{
					if(d==1001)
						i=i;

					bu[d-n]++;
					if(mx<d-n)
						mx=d-n;
				}
			}
		}

		flag=1;
		for(i=0;i<=mx;i++)
		{
			if(bu[i]>1)
				printf("%ld\n",i+n),flag=0;
			bu[i]=0;
		}
		if(flag)
			printf("None\n");
	}
	return 0;
}