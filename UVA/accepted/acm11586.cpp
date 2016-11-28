#include<stdio.h>

int main()
{
	long int m,f,i,n;
	char st[500];

	gets(st);
	sscanf(st,"%ld",&n);
	while(n--)
	{
		gets(st);
		m=f=0;
		for(i=0;st[i];i++)
		{
			if(st[i]=='M')
				m++;
			else if(st[i]=='F')
				f++;
		}
		if(m==f && m!=1)
			printf("LOOP\n");
		else
			printf("NO LOOP\n");
	}
	return 0;
}