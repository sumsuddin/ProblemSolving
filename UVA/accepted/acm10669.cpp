#include<stdio.h>
#include<string.h>
long i,carry;
unsigned long long n;
bool flag;
char st[100][100];

void make()
{
	long p;

	char c;
	for(p=0,n=strlen(st[i-1])-1;p<strlen(st[i-1])/2;p++,n--)
	{
		c=st[i-1][p];
		st[i-1][p]=st[i-1][n];
		st[i-1][n]=c;
	}

	carry=0;
	for(p=0;st[i-1][p];p++)
	{
		st[i][p]=((st[i-1][p]-'0')*3+carry)%10+'0';
		carry=((st[i-1][p]-'0')*3+carry)/10;
	}
	if(carry)
		st[i][p++]=carry+'0';
	st[i][p]=0;

	for(p=0,n=strlen(st[i-1])-1;p<strlen(st[i-1])/2;p++,n--)
	{
		c=st[i-1][p];
		st[i-1][p]=st[i-1][n];

		st[i-1][n]=c;
	}

	for(p=0,n=strlen(st[i])-1;p<strlen(st[i])/2;p++,n--)
	{
		c=st[i][p];
		st[i][p]=st[i][n];

		st[i][n]=c;
	}
}

int main()
{
	strcpy(st[0],"1");
	for(i=1;i<64;i++)
		make();

	while(~scanf("%llu",&n) && n)
	{
		n--;
		printf("{");
		flag=1;
		for(i=0;n && i<64;i++)
		{
			if(n%2)
			{
				if(flag)
					printf(" %s",st[i]),flag=0;
				else
					printf(", %s",st[i]);
			}
			n>>=1;
		}
		printf(" }\n");
	}
	return 0;
}
