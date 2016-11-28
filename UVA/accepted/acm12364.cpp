#include<stdio.h>
#include<string.h>
long i,n,l,ii;
char st[1000],sr[15][1500],fnt[20][20][20],tmp[15][15];
bool flag;
void stcat( char a[], char b[])
{
	l=strlen(a);
	for(ii=0;b[ii];ii++)
		a[ii+l]=b[ii];
	a[ii+l]=0;
}

int main()
{

	strcpy(fnt[0][0],".*");
	strcpy(fnt[0][1],"**");
	strcpy(fnt[0][2],"..");

	strcpy(fnt[1][0],"*.");
	strcpy(fnt[1][1],"..");
	strcpy(fnt[1][2],"..");


	strcpy(fnt[2][0],"*.");
	strcpy(fnt[2][1],"*.");
	strcpy(fnt[2][2],"..");

	strcpy(fnt[3][0],"**");
	strcpy(fnt[3][1],"..");
	strcpy(fnt[3][2],"..");

	strcpy(fnt[4][0],"**");
	strcpy(fnt[4][1],".*");
	strcpy(fnt[4][2],"..");

	strcpy(fnt[5][0],"*.");
	strcpy(fnt[5][1],".*");
	strcpy(fnt[5][2],"..");

	strcpy(fnt[6][0],"**");
	strcpy(fnt[6][1],"*.");
	strcpy(fnt[6][2],"..");

	strcpy(fnt[7][0],"**");
	strcpy(fnt[7][1],"**");
	strcpy(fnt[7][2],"..");

	strcpy(fnt[8][0],"*.");
	strcpy(fnt[8][1],"**");
	strcpy(fnt[8][2],"..");

	strcpy(fnt[9][0],".*");
	strcpy(fnt[9][1],"*.");
	strcpy(fnt[9][2],"..");

	
	while(~scanf("%ld",&n) ,n)
	{
		scanf("%s",st);
		sr[0][0]=0;
		sr[1][0]=0;
		sr[2][0]=0;
		if(st[0]=='S')
		{
			scanf("%s",st);

			stcat(sr[0],fnt[st[0]-'0'][0]);
			stcat(sr[1],fnt[st[0]-'0'][1]);
			stcat(sr[2],fnt[st[0]-'0'][2]);
			for(i=1;st[i];i++)
			{
				stcat(sr[0]," ");
				stcat(sr[0],fnt[st[i]-'0'][0]);
				stcat(sr[1]," ");
				stcat(sr[1],fnt[st[i]-'0'][1]);
				stcat(sr[2]," ");
				stcat(sr[2],fnt[st[i]-'0'][2]);

			}
			for(i=0;i<3;i++)
				printf("%s\n",sr[i]);
		}
		else
		{
			getchar();
			for(i=0;i<3;i++)
				gets(sr[i]);
			for(n=0;sr[0][n];n+=2)
			{
				tmp[0][0]=sr[0][n];
				tmp[0][1]=sr[0][n+1];
				tmp[0][2]=0;

				tmp[1][0]=sr[1][n];
				tmp[1][1]=sr[1][n+1];
				tmp[1][2]=0;

				tmp[2][0]=sr[2][n];
				tmp[2][1]=sr[2][n+1];
				tmp[2][2]=0;

				if(sr[0][n+2]==' ')
					n++;
				for(i=0;i<10;i++)
				{
					flag=1;
					for(ii=0;ii<3;ii++)
						if(strcmp(fnt[i][ii],tmp[ii])!=0)
							flag=0;
					if(flag)
					{
						printf("%ld",i);
						break;
					}
				}
			}
			printf("\n");
		}
	}
	return 0;
}