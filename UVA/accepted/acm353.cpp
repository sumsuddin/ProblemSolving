#include<stdio.h>
#include<string.h>
char st[100],sr[100][100];
long i,j,k,l,t,sum,la,li;
bool flag;
bool com(char a[])
{
	flag=1;
	la=strlen(a);
	li=la/2;
	for(k=0,la--;k<li;k++,la--)
	{
		if(a[k]!=a[la])
		{
			flag=0;
			break;
		}
	}
	if(flag)
		return 0;
	else
		return 1;
}

int main()
{
	while(gets(st))
	{
		l=strlen(st);
		sum=0;
		for(i=1;i<=l;i++)
		{
			t=l-i;
			for(j=0;j<=t;j++)
			{
				for(k=0;k<i;k++)
					sr[j][k]=st[j+k];
				sr[j][k]=0;
			}
			for(t=0;t<j;t++)
			{
				if(com(sr[t]))
					strcpy(sr[t],"");
				else
					for(k=t+1;k<j;k++)
						if(!strcmp(sr[t],sr[k]))
							strcpy(sr[k],"");
			}
			for(t=0;t<j;t++)
				if(!strcmp(sr[t],""));
				else
					sum++;
		}
		printf("The string '%s' contains %ld palindromes.\n",st,sum);
	}
	return 0;
}