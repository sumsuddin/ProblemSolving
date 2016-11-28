#include<stdio.h>

long long i,k,fact[24],ind[200],ff,sum,now,cs=1,t,n,d;

bool flag,imp;
char st[24];

void rec(long long n)
{
	flag=1;
	sum=0;
	for(k='a';k<='z';k++)
	{
		if(ind[k])
		{
			ind[k]--;
			d=0;
			for(i='a';i<='z';i++)
				d+=ind[i];

			ff=fact[d];
			
			for(i='a';i<='z';i++)
				ff/=fact[ind[i]];
			
			if(sum+ff<n)
				sum+=ff;
			else
			{
				flag=0;
				n-=sum;
				st[now++]=(char)k;
				break;
			}
			ind[k]++;
		}
	}
	if(flag)
	{
		if(n>1)
			imp=1;
		return;
	}
	rec(n);
}

int main()
{
	scanf("%lld",&t);

	fact[0]=1;
	for(i=1;i<21;i++)
		fact[i]=i*fact[i-1];

	while(t--)
	{
		scanf("%s %lld",st,&n);

		now=imp=0;

		for(i='a';i<='z';i++)
			ind[i]=0;

		for(i=0;st[i];i++)
			ind[st[i]]++;

		rec(n);
		st[now]=0;
		if(imp)
			printf("Case %lld: Impossible\n",cs++);
		else
			printf("Case %lld: %s\n",cs++,st);

	}
	return 0;
}