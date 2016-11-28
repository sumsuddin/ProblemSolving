#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long i,j,sw,t,n,p,eg,mx,p1,p2,rank[1000],a[1000];
char st[1000][10];
bool flag;

struct ss
{
	long p,q,w;
} sr[300000];

int cmp(const void *a,const void *b)
{
	return ((ss*)a)->w-((ss*)b)->w;
}

void swap(long *m,long *n)
{
	sw=*m;
	*m=*n;
	*n=sw;
}

void init()
{
	for(i=0;i<=n;i++)
	{
		a[i]=i;
		rank[i]=0;
	}
}

long parent(long p)
{
	while(a[p]!=p)
		p=a[p];
	return p;
}


void count ()
{
	sw=0;
	for(p=0;st[i][p];p++)
		if(st[i][p]>st[j][p])
		{
			if((st[i][p]-st[j][p])>('9'-st[i][p]+st[j][p]-'0'+1))
				sw+=('9'-st[i][p]+st[j][p]-'0'+1);
			else
				sw+=(st[i][p]-st[j][p]);
		}
		else if(st[i][p]<st[j][p])
		{
			if((-st[i][p]+st[j][p])>(st[i][p]-'0'+'9'-st[j][p]+1))
				sw+=(st[i][p]-'0'+'9'-st[j][p]+1);
			else
				sw+=(-st[i][p]+st[j][p]);
		}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);
		n++;
		strcpy(st[0],"0000");
		for(i=1;i<n;i++)
			scanf("%s",st[i]);

		eg=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				count();
				sr[eg].p=i;
				sr[eg].q=j;
				sr[eg++].w=sw;
			}
		qsort(sr,eg,sizeof(sr[0]),cmp);
		init();
		rank[0]=-58888;
		mx=0;flag=0;
		for(i=0;i<eg;i++)
		{
			p1=parent(sr[i].p);
			p2=parent(sr[i].q);
			if(p1!=p2 && ( flag==0 ||(flag==1 && sr[i].p)))
			{
				if(sr[i].p==0)
					flag=1;
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
				mx+=sr[i].w;
			}
		}
		
		printf("%ld\n",mx);
	}
	return 0;
}