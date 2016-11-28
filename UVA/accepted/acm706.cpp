#include<stdio.h>
#include<string.h>
char a[50][500];
int i,j,d,k,carry,mod,t,ls;

char st[11][16]={" | | -   - | | "," | | -   - | | ","           | | ","   | - - - |   ","     - - - | | "," |     -   | | "," |   - - -   | "," | | - - -   | ","     -     | | "," | | - - - | | "," |   - - - | | "};
void prin(int b,int c)
{
	d=0;

	for(i=0;i<b+2;i++)
	{
		if(i==1)
		{
			carry=d;
			for(i;i<=b;i++)
			{
				j=0;
				a[j++][i+mod]=st[c][d++];
				k=b;
				while(k--)
					a[j++][i+mod]=st[c][d];

				d++;
				a[j++][i+mod]=st[c][d++];
				k=b;

				while(k--)
					a[j++][i+mod]=st[c][d];

				d++;
				a[j][i+mod]=st[c][d++];
				d=carry;
			}
			i--;
			d+=5;
		}
		else
		{
			j=0;
			a[j++][i+mod]=st[c][d++];
			k=b;
			while(k--)
				a[j++][i+mod]=st[c][d];

			d++;
			a[j++][i+mod]=st[c][d++];
			k=b;

			while(k--)
				a[j++][i+mod]=st[c][d];

			d++;
			a[j][i+mod]=st[c][d++];
		}
	}
	if(t==ls-1)
	{
		for(j=0;j<b*2+3;j++)
			a[j][i+mod]=0;
		i++;
	}
	else
	{
		for(j=0;j<b*2+3;j++)
			a[j][i+mod]=' ';
		i++;
	}

	mod=(t+1)*i;
}

int main()
{
	int s,m=1;
	char sy[100];
	while(scanf("%d%s",&s,sy))
	{
		if(s==0 && sy[0]==48)
			break;
		mod=0;
		ls=strlen(sy);
		for(t=0;t<ls;t++)
			prin(s,sy[t]-47);

		for(k=0;k<2*s+3;k++)
		{
			puts(a[k]);
		}
		printf("\n");
	}
	return 0;
}