#include<stdio.h>
#include<string.h>
long i,j,mx,n;
char st[10000][30];
bool vst[150];
int main()
{
	while(~scanf("%s",st[0]))
	{
		mx=strlen(st[0]);
		n=1;
		while(scanf("%s",st[n]) && st[n][0]!='#')
		{
			if(mx<strlen(st[n]))
				mx=strlen(st[n]);
			n++;
		}
		for(i=65;i<=90;i++)
			vst[i]=1;
		for(i=0;i<=n;i++)
		{
			for(j=strlen(st[i]);j<=mx;j++)
				st[i][j]=0;
		}

		for(i=0;i<=mx;i++)
		{
			for(j=0;j<=n;j++)
				if(vst[st[j][i]] && st[j][i])
				{
					printf("%c",st[j][i]);
					vst[st[j][i]]=0;
				}
		}
		printf("\n");
	}
	return 0;
}