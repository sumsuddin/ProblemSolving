#include<stdio.h>
long i,n,cc,cnt,ans,prm[1000050],lst,j,d;
bool bu[1000050];
int main()
{
	bu[0]=1;
	bu[1]=1;
	lst=0;
	for(i=3;i<1000001;i+=2)
	{
		if(bu[i]==0)
		{
			prm[lst++]=i;

			for(j=3*i;j<1000001;j+=(2*i))
				bu[j]=1;
		}
	}

	while(scanf("%ld",&n) && n)
	{
		d=ans=1;
		cnt=cc=0;
		while((d<<1)<=n)
			d<<=1,cnt++;

		d=1;
		while((d*5)<=n)
			d*=5,cc++;

		cnt-=cc;

		while(cnt--)
			ans=(ans<<1)%10;

		for(i=0;i<lst && prm[i]<=n;i++)
		{
			if(prm[i]==5)
				continue;

			d=1;
			while((d*prm[i])<=n)
			{
				d*=prm[i];
				ans=(ans*prm[i])%10;
			}
		}
		printf("%ld\n",ans);
	}
	return 0;
}