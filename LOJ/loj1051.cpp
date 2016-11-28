#include<stdio.h>
#include<string.h>
long t,x,y,cs=1,v[55],c[55];
char st[55];
long good()
{
	long i;
	v[0]=0;
	c[0]=0;
	for(i=0;st[i];i++)
	{
		if(v[i]==-1 && c[i]==-1)
			return 0;
		if(st[i]=='?')
		{
			if(v[i]>=0)
				v[i+1]=v[i]+1;

			if(c[i]>=0 || v[i]==-1)
				v[i+1]=1;

			if(c[i]>=0)
				c[i+1]=c[i]+1;

			if(v[i]>=0 || c[i]==-1)
				c[i+1]=1;

			if(c[i+1]>=5)
				c[i+1]=-1;
			if(v[i+1]>=3)
				v[i+1]=-1;
		}
		else if(st[i]=='A' || st[i]=='U' || st[i]=='O' || st[i]=='I' || st[i]=='E')
		{
			c[i+1]=-1;
			if(v[i]>=0)
				v[i+1]=v[i]+1;

			if(c[i]>=0 || v[i]==-1)
				v[i+1]=1;

			if(v[i+1]>=3)
				v[i+1]=-1;
		}
		else
		{
			v[i+1]=-1;
			if(c[i]>=0)
				c[i+1]=c[i]+1;

			if(v[i]>=0 || c[i]==-1)
				c[i+1]=1;

			if(c[i+1]>=5)
				c[i+1]=-1;
		}
	}
	if(v[i]>=0 || c[i]>=0)
		return 1;
	else
		return 0;
}

bool bad()
{
	long vwl=0,cnst=0,i;
	for(i=0;st[i];i++)
	{
		if(st[i]=='?')
			vwl++,cnst++;
		else if(st[i]=='A' || st[i]=='U' || st[i]=='O' || st[i]=='I' || st[i]=='E')
			vwl++,cnst=0;
		else
			cnst++,vwl=0;

		if(vwl>=3 || cnst>=5)
			return 1;
	}
	return 0;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%s",st);

		for(x=0;st[x];x++)
			v[x]=c[x]=-1;

		x=y=0;

		x=good();
		y=bad();

		if(x && y)
			printf("Case %ld: MIXED\n",cs++);
		else if(y==0)
			printf("Case %ld: GOOD\n",cs++);
		else
			printf("Case %ld: BAD\n",cs++);
	}
	return 0;
}