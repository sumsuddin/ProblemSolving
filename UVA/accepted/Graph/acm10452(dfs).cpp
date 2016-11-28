#include<stdio.h>

long i,j,r,c,t,flag;
char sr[]="IEHOVA#",st[100][100];

void dfs(long x,long y,long pos)
{
	if(sr[pos]==0)
		return;

	if(st[x][y-1]==sr[pos])
	{
		if(flag)
			printf("left"),flag=0;
		else
			printf(" left");
		dfs(x,y-1,pos+1);
	}
	else if(st[x][y+1]==sr[pos])
	{
		if(flag)
			printf("right"),flag=0;
		else
			printf(" right");
		dfs(x,y+1,pos+1);
	}
	else if(st[x-1][y]==sr[pos])
	{
		if(flag)
			printf("forth"),flag=0;
		else
			printf(" forth");
		dfs(x-1,y,pos+1);
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&r,&c);

		flag=1;

		for(i=0;i<r;i++)
			scanf("%s",st[i]);
		for(i=0;i<r && flag;i++)
			for(j=0;st[i][j];j++)
				if(st[i][j]=='@')
				{
					dfs(i,j,0);
					printf("\n");
					break;
				}
	}
	return 0;
}