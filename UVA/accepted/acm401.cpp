#include<stdio.h>
#include<string.h>
int main()
{
	long i,j,la,mir,pel;
	char st[100],sy[1005],c,d;
	st[65]='A';
	st[66]=0;
	st[67]=0;
	st[68]=0;
	st[69]='3';
	st[70]=0;
	st[71]=0;
	st[72]='H';
	st[73]='I';
	st[74]='L';
	st[75]=0;
	st[76]='J';
	st[77]='M';
	st[78]=0;
	st[79]='O';
	st[80]=0;
	st[81]=0;
	st[82]=0;
	st[83]='2';
	st[84]='T';
	st[85]='U';
	st[86]='V';
	st[87]='W';
	st[88]='X';
	st[89]='Y';
	st[90]='5';
	st[49]='1';
	st[50]='S';
	st[51]='E';
	st[52]=0;
	st[53]='Z';
	st[54]=0;
	st[55]=0;
	st[56]='8';
	st[57]=0;

	while(gets(sy))
	{
		j=strlen(sy)-1;
		la=j/2+1;
		pel=mir=1;

		for(i=0,j;i<la;i++,j--)
		{
			if(sy[i]=='0')
				c='O';
			else
				c=sy[i];

			if(sy[j]=='0')
				d='O';
			else
				d=sy[j];

			if(c!=d)
				pel=0;
			if(c!=st[d])
				mir=0;
		}
		if(pel && mir)
			printf("%s -- is a mirrored palindrome.\n\n",sy);
		else
			if(pel)
				printf("%s -- is a regular palindrome.\n\n",sy);
			else
				if(mir)
					printf("%s -- is a mirrored string.\n\n",sy);
				else
					printf("%s -- is not a palindrome.\n\n",sy);
	}
	return 0;
}