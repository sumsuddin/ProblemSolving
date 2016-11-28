#include<stdio.h>
#include<string.h>
long i,x,y,a[5010],b[5010],p1,p2,n,max,t,m;
char s1[50],s2[50],st[5010][50];

long parent(long p)
{
	if(a[p]==-1)
		return p;
	else
		parent(a[p]);
}
int main()
{
	;
	while(scanf("%ld%ld",&n,&m) && (n||m))
	{
		getchar();
		for(i=1;i<=n;i++)
		{
			gets(st[i]);
			a[i]=-1;
			b[i]=0;
		}
		while(m--)
		{
			scanf("%s%s",s1,s2);
			for(i=1;i<=n;i++)
				if(strcmp(st[i],s1)==0)
				{
					p1=parent(i);
					break;
				}
			for(i=1;i<=n;i++)
				if(strcmp(st[i],s2)==0)
				{
					p2=parent(i);
					break;
				}
			if(p1!=p2)
				a[p2]=p1;
		}
		max=0;
		for(i=1;i<=n;i++)
		{
			x=parent(i);
			b[x]++;
			if(b[x]>max)
				max=b[x];
		}
		printf("%ld\n",max);

	}
	return 0;
}