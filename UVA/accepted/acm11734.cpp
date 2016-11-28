#include<stdio.h>
#include<string.h>
int main()
{
	long i,j,d,p=1,n;
	char st[1000],sy[1000];

	gets(st);
	sscanf(st,"%ld",&n);
	while(n--)
	{
		gets(st);
		gets(sy);
		printf("Case %ld: ",p++);

		if(strlen(st)==strlen(sy))
		{
			if(strcmp(st,sy))
				printf("Wrong Answer\n");				
			else
				printf("Yes\n");

		}
		else
		{
			i=j=0;
			d=1;
			while(st[i]||sy[j])
			{
				if(st[i]==' ')
					i++;
				else
				{
					if(st[i]!=sy[j])
					{
						printf("Wrong Answer\n");
						d=0;
						break;
					}
					i++;j++;
				}
			}
			if(d)
				printf("Output Format Error\n");
		}
	}
	return 0;
}