#include<stdio.h>
long pr[200],rank[200],sum,a,b,p,q,n,e,i;
char x[10],y[10];
long par(long p)
{
	while(pr[p]!=p)
		p=pr[p];
	return p;
}

int main()
{
	while(~scanf("%ld%ld",&n,&e))
	{
		for(i=0;i<150;i++)
			rank[i]=0,pr[i]=i;
		sum=0;
		for(i=0;i<e;i++)
		{
			scanf("%s%s",&x,&y);
			a=x[0],b=y[0];

			p=par(a);
			q=par(b);

			if(p==q)
				sum++;
			else
			{
				if(rank[p]>rank[q])
					rank[p]++,pr[q]=p;
				else
					rank[q]++,pr[p]=q;
			}
		}
		printf("%ld\n",sum+1);
	}
	return 0;
}
