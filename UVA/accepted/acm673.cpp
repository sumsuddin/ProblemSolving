#include<stdio.h>
#include<string.h>
int main()
{
	char st[500],sy[500];
	long fir,i,p,n;
	gets(st);
	sscanf(st,"%ld",&n);
	while(n--)
	{
		gets(st);
		p=1;fir=0;
		if(strlen(st)%2)
			printf("No\n");
		else
		{
			for(i=0;st[i];i++)
			{
				if(st[i]=='(')
					sy[fir++]='(';
				else
					if(st[i]=='[')
						sy[fir++]='[';
					else
						if(st[i]==']')
						{
							if('['==sy[fir-1])
								fir--;
						}
						else
							if(st[i]==')')
							{
								if('('==sy[fir-1])
									fir--;
							}
			}
			if(fir)
				printf("No\n");
			else
				printf("Yes\n");
		}
	}
	return 0;
}