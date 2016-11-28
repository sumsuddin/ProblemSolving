#include<stdio.h>
#include<string.h>
long i,j,n,p,mx,t,cs=1;
char st[100],sy[100][100];
int main()
{
	scanf("%ld",&n);
	while(n--)
	{
		for(i=0;i<60;i++)
		{
			for(j=0;j<60;j++)
				sy[i][j]=' ';
			sy[i][j]=0;
		}
		p=1;
		t=1;
		scanf("%s",st);
		printf("Case #%ld:\n",cs++);

		for(i=0;st[i];i++)
		{
			if(st[i]=='R')
				sy[p][2+i]='/';
			else
				if(st[i]=='C')
					sy[p][2+i]='_';
				else
					sy[p][2+i]='\\';

			if(st[i]=='F' && st[i+1]=='F')
				p--;
			else
				if(st[i]=='R' && (st[i+1]=='C' || st[i+1]=='R'))
					p++;
				else
					if(st[i]=='C' && st[i+1]=='F')
						p--;

			if(t<p)
				t=p;
			if(p<=0)
			{
				for(j=t;j>=0;j--)
					strcpy(sy[j+1],sy[j]);
				t++;
				p=1;
			}
		}
		t++;
		mx=i+3;
		for(i=0;i<t;i++)
		{
			sy[i][0]='|';
			sy[i][mx]=0;
		}
		sy[0][0]='+';
		for(i=1;i<mx;i++)
			sy[0][i]='-';
		sy[0][i]=0;
		while(t--)
		{
			for(i=mx-1;i>=0;i--)
				if(sy[t][i]!=' ')
				{
					sy[t][i+1]=0;
					break;
				}
			puts(sy[t]);
		}
		printf("\n");
	}
	return 0;
}