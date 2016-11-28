#include<stdio.h>
#include<string.h>
void comp(char a[],char b[])
{
	int e=1,i;
	if(strlen(a)==strlen(b))
	{
		for(i=0;a[i];i++)
		{
			if((a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u') && (b[i]=='a' || b[i]=='e' || b[i]=='i' || b[i]=='o' || b[i]=='u'))
				continue;
			else
			{
				if(a[i]!=b[i])
				{
					printf("No\n");
					e=0;
					break;
				}
			}
		}
		if(e)
			printf("Yes\n");
	}
	else
		printf("No\n");
}



int main()
{
	char st[25],sy[25];
	int n;

	gets(st);
	sscanf(st,"%d",&n);

	while(n--)
	{
		scanf("%s%s",st,sy);

		comp(st,sy);
	}
	return 0;
}
