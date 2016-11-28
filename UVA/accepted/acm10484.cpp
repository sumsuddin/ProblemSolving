#include<stdio.h>
#include<math.h>
typedef long lng;
lng i,j,prm[155],pr[155],n,l,sq,lst,ind;
bool bu[155],flag;
long long d;
int main()
{
	prm[0]=2;
	lst=1;
	for(i=3;i<100;i+=2)
	{
		if(bu[i]==0)
		{
			prm[lst++]=i;
			for(j=3*i;j<100;j+=(2*i))
				bu[j]=1;
		}
	}
	while(~scanf("%ld%lld",&n,&d) && (n||d))
	{
      if(d<0)
      d*=-1;
		for(i=2;i<=100;i++)
			pr[i]=0;
		for(i=2;i<=n;i++)
		{
			sq=(lng)sqrt(i);
			ind=i;
			for(j=0;prm[j]<=sq && j<lst;j++)
			{
				while(ind%prm[j]==0)
					pr[prm[j]]++,ind/=prm[j];
			}
			if(ind>1)
				pr[ind]++;
		}
		flag=1;
		sq=(lng)sqrt(d);
		for(j=0;prm[j]<=sq && j<lst;j++)
			while(d%prm[j]==0)
			{
				pr[prm[j]]--,d/=prm[j];
				if(pr[prm[j]]<0)
				{
					flag=0;
					break;
				}
			}
		if(d>1)
		{
			if(d>=100)
				flag=0;
			else
         {   pr[d]--;
			   if(pr[d]<0)
				  flag=0;
         }
		}

		d=1;
		for(i=2;i<=n && flag;i++)
			if(pr[i])
				d*=pr[i]+1;
 
		if(flag)
			printf("%lld\n",d);
		else
			printf("0\n");
	}
	return 0;
}
