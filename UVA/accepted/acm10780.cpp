#include<stdio.h>
#include<math.h>
long i,sq,m,n,count,flag,d,e,pr,cnt,cs=1,mn,t;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&m,&n);
		mn=1000000000;
		e=m;
		flag=1,pr=0;
		count=0;
		sq=(long)sqrt(m);

		while(m%2==0)
		{
			count++;
			pr=1;
			m/=2;
		}

		d=n;
		cnt=0;
		while(d)
		{
			cnt+=(d/2);
			d/=2;
		}
		if(count-cnt>0)
			flag=0;

		if(count && cnt/count<mn)
			mn=cnt/count;

		for(i=3;i<=sq && flag;i++)
		{
			count=0;
			while(m%i==0)
			{
				count++;
				pr=1;
				m/=i;
			}

			d=n;
			cnt=0;
			while(d)
			{
				cnt+=(d/i);
				d/=i;
			}
			if(count-cnt>0)
				flag=0;
			if(count && cnt/count<mn)
				mn=cnt/count;
		}
		if(m>1)
		{
			if(n<m)
				flag=0;
			else
			{
				d=n;
				cnt=0;
				while(d)
				{
					cnt+=(d/m);
					d/=m;
				}
				if(cnt<mn)
					mn=cnt;
			}
		}
		printf("Case %ld:\n",cs++);
		if(flag && (pr ||(pr==0 &&n>=e)))
			printf("%ld\n",mn);
		else
			printf("Impossible to divide\n");
	}
	return 0;
}