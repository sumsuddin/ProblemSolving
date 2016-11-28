#include<stdio.h>

long i,x,y,a[100],b[100],p1,p2,rank[100],ac,tr,t;
char st[100];

void init()
{
	tr=ac=0;
	for(i=65;i<91;i++)
	{
		a[i]=-1;
		b[i]=0;
		rank[i]=0;
	}
}

long parent(long p)
{
	while(a[p]!=-1)
		p=a[p];
	return p;

}

int main()
{
	scanf("%ld\n",&t);

	while(t--)
	{
		init();
		while(scanf("%c",&x)==1 && x=='(')
		{
			scanf("%c,%c)\n",&x,&y);
			p1=parent((long)x);
			p2=parent((long)y);
			if(p1!=p2)
			{
				if(rank[p1]>rank[p2])
				{
					a[p2]=p1;
					rank[p1]++;
				}
				else
				{
					a[p1]=p2;
					rank[p2]++;
				}
			}
		}
		gets(st);
		gets(st);
		for(i=0;st[i];i++)
		{
			if(st[i]!=',')
				b[parent((long)st[i])]++;
		}

		for(i=65;i<91;i++)
			if(b[i]==1)
				ac++;
			else if(b[i]>1)
				tr++;

		printf("There are %ld tree(s) and %ld acorn(s).\n",tr,ac);
	}
			
	return 0;
}