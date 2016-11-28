#include<stdio.h>
#include<math.h>
#include<string.h>
typedef long long lng;
lng i,j,prm[1005],pr[1005],t,n,l,ind,sq,m,lst,lim,cs=1;
bool fl[1005],bu[1005],flag;
char st[100];
int main()
{
	scanf("%lld",&t);

	prm[0]=2;
	lst=1;
	for(i=3;i<1000;i+=2)
	{
		if(bu[i]==0)
		{
			prm[lst++]=i;
			for(j=3*i;j<1000;j+=(2*i))
				bu[j]=1;
		}
	}
	lim=1;
	for(i=1;i<=18;i++)
	lim*=10;
	while(t--)
	{
		scanf("%s",st);
		n=0;
		for(i=0;st[i];i++)
			if(st[i]<='9' && st[i]>='0')
				n=n*10+(st[i]-48);
			else
				break;

		l=strlen(st)-i;

		for(i=2;i<=n;i++)
			pr[i]=fl[i]=0;
		for(i=n;i>1;i-=l)
		{
			fl[i]=1;
			if(i<l)
				break;
		}

		for(i=2;i<=n;i++)
			if(fl[i])
			{
				sq=(lng)sqrt(i);
				ind=i;
				for(j=0;prm[j]<=sq;j++)
				{
					while(ind%prm[j]==0)
						pr[prm[j]]++,ind/=prm[j];
				}
				if(ind>1)
					pr[ind]++;
			}
		m=1;
		flag=1;
		for(i=2;i<=n && flag;i++)
			if(pr[i])
			{
            m*=pr[i]+1;
            if(m>lim)
            flag=0;
         }
      printf("Case %lld: ",cs++);
      if(flag)
		printf("%lld\n",m);
		else
		printf("Infinity\n");
	}
	return 0;
}
