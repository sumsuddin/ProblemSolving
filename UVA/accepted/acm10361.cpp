#include<stdio.h>
int main()
{
	char st[105],sy[6][105];
	long i,n,j,p;
	gets(st);

	sscanf(st,"%ld",&n);

	while(n--)
	{
		gets(st);
		p=0;

		for(i=0;st[i];i++)
		{
			if(st[i]=='<')
			{
				for(j=0;st[++i]!='>';j++)
					printf("%c",sy[p][j]=st[i]);
				sy[p][j]=0;
				p++;

				for(j=0;st[++i]!='<' && st[i];j++)
					printf("%c",sy[p][j]=st[i]);
				sy[p][j]=0;
				p++;
				i--;
			}
			else
				printf("%c",st[i]);
		}
		printf("\n");
		gets(st);
		for(i=0;st[i];i++)
		{
			if(st[i]=='.')
			{
				if(st[i+1]=='.')
					if(st[i+2]=='.')
						printf("%s%s%s%s",sy[2],sy[1],sy[0],sy[3]);
			i+=2;
			}

			else
				printf("%c",st[i]);
		}
		printf("\n");


	}
	return 0;
}
