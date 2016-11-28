#include<stdio.h>
#include<math.h>

long long i,j,prm[100000],l,h,sq,a,las,mn,mx,dis,xm,ym,xn,ynn;
bool bu[1000000],flag,fg;
int main()
{
	bu[0]=1;
	bu[1]=1;

	prm[0]=2;
	las=1;

	for(i=4;i<1000000;i+=2)
		bu[i]=1;

	for(i=3;i<1000000;i+=2)
	{
		if(bu[i]==0)
		{
			prm[las++]=i;
			for(j=3*i;j<1000000;j+=(2*i))
				bu[j]=1;
		}
	}

	while(~scanf("%lld%lld",&l,&h))
	{
		for(i=0;i<1000001;i++)
			bu[i]=0;
		sq=(long)sqrt(h)+1;

		for(i=0;i<sq;i++)
		{
			a=l/prm[i];
			if(l%prm[i]==0)
				a--;
			if(a==0)
				a++;
			a=(a+1)*prm[i];

			for(j=a;j<=h;j+=prm[i])
				bu[j-l]=1;
		}
		if(l==1)
			bu[0]=1;

		fg=flag=1;
		for(i=0;i<=h-l;i++)
			if(bu[i]==0)
			{
				if(flag)
					a=i,flag=0;
				else
				{
					dis=i-a;
					if(fg)
					{
						mn=mx=dis,fg=0;
						xm=xn=a,ym=ynn=i;
					}
				}
				if(dis<mn)
				{
					mn=dis;
					xn=a;ynn=i;
				}
				if(dis>mx)
				{
					mx=dis;
					xm=a;ym=i;
				}
				a=i;
			}
		if(fg)
			printf("There are no adjacent primes.\n");
		else
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n",xn+l,ynn+l,xm+l,ym+l);
	}
	return 0;
}