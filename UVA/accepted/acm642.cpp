#include<stdio.h>
#include<string.h>
long i,j,k,flag,flg,mat[300][300],ma[300];
char st[300][300],sy[300];
int main()
{
	while(scanf("%s",st[i]) && strcmp(st[i],"XXXXXX"))
		i++;

	for(j=0;j<i;j++)
		for(k=j+1;k<i;k++)
		{
			if(strcmp(st[j],st[k])>0)
			{
				strcpy(sy,st[j]);
				strcpy(st[j],st[k]);
				strcpy(st[k],sy);
			}
		}
	for(j=0;j<i;j++)
	{
		for(k=0;st[j][k];k++)
			mat[j][st[j][k]]++;
	}

	while(scanf("%s",sy) && strcmp(sy,"XXXXXX"))
	{
		flg=1;
		for(j=97;j<123;j++)
			ma[j]=0;
		for(j=0;sy[j];j++)
			ma[sy[j]]++;
		for(j=0;j<i;j++)
		{
			flag=1;
			for(k='a';k<123;k++)
				if(ma[k]!=mat[j][k])
				{
					flag=0;
					break;
				}
			if(flag)
			{
				flg=0;
				puts(st[j]);
			}
		}
		if(flg)
			printf("NOT A VALID WORD\n******\n");
		else
			printf("******\n");
	}
	return 0;
}