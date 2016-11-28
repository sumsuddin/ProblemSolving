#include<stdio.h>
#include<string.h>

int main()
{
	char st[150],sy[1000];
	int a,i,j;

	st[66]='c';
	st[67]='z';
	st[68]='a';
	st[69]='q';
	st[70]='s';
	st[71]='d';
	st[72]='f';
	st[73]='y';
	st[74]='g';
	st[75]='h';
	st[76]='j';
	st[77]='b';
	st[78]='v';
	st[79]='u';
	st[80]='i';
	st[82]='w';
//	st[83]='w';
	st[84]='e';
	st[85]='t';
	st[86]='x';
//	st[87]='Q';
//	st[88]='Z';
	st[89]='r';


	st[98]='c';	
	st[99]='z';
	st[100]='a';
	st[101]='q';
	st[102]='s';
	st[103]='d';
	st[104]='f';
	st[105]='y';
	st[106]='g';
	st[107]='h';
	st[108]='j';
	st[109]='b';
	st[110]='v';
	st[111]='u';
	st[112]='i';
//	st[113]='w';
	st[114]='w';
	st[116]='e';
	st[117]='t';
	st[118]='x';
//	st[87]='Q';
//	st[88]='Z';
	st[121]='r';
	st[44]='n';
	st[46]='m';
	st[47]=',';
	st[59]='k';
	st[39]='l';
	st[91]='o';
	st[93]='p';
	st[92]='[';
//	st[49]='`';
	st[50]='`';
	st[51]='1';
	st[52]='2';
	st[53]='3';
	st[54]='4';
	st[55]='5';
	st[56]='6';
	st[57]='7';
	st[48]='8';
	st[45]='9';
	st[61]='0';




	while(gets(sy))
	{
		a=strlen(sy);

		for(i=0;i<a;i++)
		{

			if(sy[i]==' ')
				printf("%c",' ');

			if(sy[i]>43 && sy[i]<62)
			{
				for(j=44;j<=61;j++)
				{
					if(sy[i]==j)
					{
						printf("%c",st[j]);
						break;
					}
				}
			}

			if(sy[i]>64 &&sy[i]<90)
			{
				for(j=65;j<90;j++)
				{
					if(sy[i]==j)
					{
						printf("%c",st[j]);
						break;
					}
				}
			}


			else
			{
				if(sy[i]==39)
					printf("l");

				else
					for(j=91;j<123;j++)
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