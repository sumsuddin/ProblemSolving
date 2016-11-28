#include<stdio.h>
#include<string.h>

int main()
{
	char st[150],sy[1000];
	int a,i,j;

	st[66]='V';
	st[67]='X';
	st[68]='S';
	st[69]='W';
	st[70]='D';
	st[71]='F';
	st[72]='G';
	st[73]='U';
	st[74]='H';
	st[75]='J';
	st[76]='K';
	st[77]='N';
	st[78]='B';
	st[79]='I';
	st[80]='O';
	st[82]='E';
	st[83]='A';
	st[84]='R';
	st[85]='Y';
	st[86]='C';
	st[87]='Q';
	st[88]='Z';
	st[89]='T';
	st[44]='M';
	st[46]=',';
	st[47]='.';
	st[59]='L';
	st[39]=';';
	st[91]='P';
	st[93]='[';
	st[92]=']';
	st[49]='`';
	st[50]='1';
	st[51]='2';
	st[52]='3';
	st[53]='4';
	st[54]='5';
	st[55]='6';
	st[56]='7';
	st[57]='8';
	st[48]='9';
	st[45]='0';
	st[61]='-';




	while(gets(sy))
	{
		a=strlen(sy);

		for(i=0;i<a;i++)
		{

			if(sy[i]==' ')
				printf("%c",' ');

			else
			{
				if(sy[i]==39)
					printf(";");

				else
					for(j=44;j<94;j++)
					{

						if(sy[i]==j)
						{
							printf("%c",st[j]);
							break;
						}

					}
			}
		}
		printf("\n");
	}
	return 0;
}