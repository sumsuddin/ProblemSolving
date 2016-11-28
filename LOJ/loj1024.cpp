#include<stdio.h>
#include<math.h>
long rm[10050],a[10005],lst,t,n,p,d,sq,i,j,carry,cs=1;

void mul(long n,long cnt)
{
	p=1;long i;
	while(p<10000000 && cnt)
		p*=n,cnt--;
	for(i=0;i<lst;i++)
		a[i]*=p;
	for(i=0;i<lst;i++)
	{
		carry=a[i]/10;
		a[i]=a[i]%10;
		a[i+1]+=carry;
	}
	while(carry)
		a[lst++]=carry%10,carry/=10;
	if(cnt)
		mul(n,cnt);
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<10000;i++)
			rm[i]=0;

		for(i=0;i<n;i++)
		{
			scanf("%ld",&p);

			sq=(long)sqrt(p);
			d=0;
			while(p%2==0)
				d++,p>>=1;
			if(rm[2]<d)
				rm[2]=d;
			for(j=3;j<=sq;j+=2)
			{
				if(p%j==0)
				{
					d=0;
					while(p%j==0)
						d++,p/=j;
					if(rm[j]<d)
						rm[j]=d;
				}
			}
			if(p>1 && rm[p]==0)
				rm[p]=1;
		}
		a[0]=lst=1;
		if(rm[2])
			mul(2,rm[2]);
		for(i=3;i<10000;i+=2)
			if(rm[i])
				mul(i,rm[i]);
		lst=lst;
		printf("Case %ld: ",cs++);
		while(lst--)
			printf("%ld",a[lst]);
		printf("\n");
	}
	return 0;
}
