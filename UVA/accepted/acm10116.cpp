#include<stdio.h>
#include<string.h>
long i,j,p,a,vst[50][50],m,n,s;
char st[50][50];
bool test[50][50];

int main()
{
	while(gets(st[0]) && strcmp(st[0],"0 0 0"))
	{
		sscanf(st[0],"%ld%ld%ld",&m,&n,&s);

		for(j=0;j<=n;j++)
			st[0][j]=0;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				vst[i][j]=0;
				test[i][j]=1;
				st[i][j]=getchar();
			}
			st[i][j]=0;
			test[i][j]=0;
			getchar();
		}
		for(j=0;j<=n;j++)
		{
			st[i][j]=0;
			test[i][j]=0;
		}

		p=1;vst[p][s]=1;
		while(1)
		{
			a=vst[p][s];

			test[p][s]=0;
			if(st[p][s]=='N')
				p--;
			else
				if(st[p][s]=='S')
					p++;
				else
					if(st[p][s]=='E')
						s++;
					else
						if(st[p][s]=='W')
							s--;

			if(test[p][s]!=0)
				vst[p][s]=a+1;
			else
			{
				if(st[p][s]==0)
					printf("%ld step(s) to exit\n",a);
				else
					printf("%ld step(s) before a loop of %ld step(s)\n",vst[p][s]-1,a-vst[p][s]+1);
				break;

			}
			
		}
	}
	return 0;
}