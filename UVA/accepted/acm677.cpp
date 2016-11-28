#include<stdio.h>
long mat[10][10],i,j,n,m,sx[10];
bool cc;
void rec(long p,long vs,long cnt)
{
	bool flag;
	long i;
	if(cnt==m+1)
	{
		flag=1;
		p=0;
		for(i=0;i<=m;i++)
		{
			if(flag)
				printf("(%ld",p+1),flag=0;
			else
				printf(",%ld",p+1);
			p=sx[p];
		}
		cc=0;
		printf(")\n");
		return ;
	}

	for(i=0;i<n;i++)
		if(mat[p][i] && ((vs>>i) & 1)==0)
			sx[p]=i,rec(i,vs | 1<<i,cnt+1);
}


int main()
{
	bool go=1;
	while(~scanf("%ld",&n))
	{
		if(n==-9999)
			scanf("%ld%ld",&n,&m);
		else
			scanf("%ld",&m);
		if(go)
			go=0;
		else
			printf("\n");

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%ld",&mat[i][j]);

		cc=1;
		rec(0,1,1);
		if(cc)
			printf("no walk of length %ld\n",m);
	}
	return 0;
}