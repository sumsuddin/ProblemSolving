#include<stdio.h>
#include<string.h>
char st[10][10];
bool flag,ok,xace,ans;
long i,j,y,x,n;
int main()
{
	gets(st[0]);
	sscanf(st[0],"%ld",&n);
	while(n--)
	{
		x=0;
		y=0;
		ans=0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%c",&st[i][j]);
				if(st[i][j]=='X')
					x++;
				else
					if(st[i][j]=='O')
						y++;
			}
			getchar();
		}
		if(x!=y && x!=y+1)
		{
			ans=0;
		}
		else
		{
			flag=0;
			if(strcmp(st[0],"XXX")==0 || strcmp(st[1],"XXX")==0|| strcmp(st[2],"XXX")==0)
				flag=1;
			else
			{
				for(i=0;i<3;i++)
				{
					ok=1;
					for(j=0;j<3;j++)
					{
						if(st[j][i]!='X')
						{
							ok=0;
							break;
						}
					}
					if(ok)
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					if((st[0][0]=='X' && st[1][1]=='X' && st[2][2]=='X') || (st[0][2]=='X' && st[1][1]=='X' && st[2][0]=='X'))
						flag=1;
				}
			}
			xace=0;
			if(flag)
			{
				xace=1;
				if(x==y+1)
					ans=1;
				else
					ans=0;
			}
			else
				ans=ans=1;

			if(ans==1)
			{
				flag=0;
				if(strcmp(st[0],"OOO")==0 || strcmp(st[1],"OOO")==0|| strcmp(st[2],"OOO")==0)
					flag=1;
				else
				{
					for(i=0;i<3;i++)
					{
						ok=1;
						for(j=0;j<3;j++)
						{
							if(st[j][i]!='O')
							{
								ok=0;
								break;
							}
						}
						if(ok)
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
						if((st[0][0]=='O' && st[1][1]=='O' && st[2][2]=='O') || (st[0][2]=='O' && st[1][1]=='O' && st[2][0]=='O'))
							flag=1;
					}
				}
			}
			if(flag)
				if(x==y+1 && xace!=1)
					ans=0;
		}
		if(ans)
			printf("yes\n");
		else
			printf("no\n");
		if(n)
			getchar();
	}

	return 0;
}