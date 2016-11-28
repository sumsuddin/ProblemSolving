#include<stdio.h>
#include<string.h>
char s[100],st[150][100],sy[150][100];
long i,la,l,n;
bool flag;
int main()
{
	scanf("%ld%ld",&l,&n);

	for(i=0;i<l;i++)
		scanf("%s%s",st[i],sy[i]);

	while(n--)
	{
		flag=1;
		scanf("%s",s);
		la=strlen(s)-1;
		for(i=0;i<l;i++)
			if(strcmp(st[i],s)==0)
			{
				puts(sy[i]);
				flag=0;
			}

		if(flag)
		{
			
			if(s[la]=='y')
			{
				la--;
				if(s[la]!='a' && s[la]!='e' && s[la]!='i' && s[la]!='o' && s[la]!='u')
				{
					for(i=0;i<=la;i++)
						printf("%c",s[i]);
					printf("ies\n");
			
				}
				else
					printf("%ss\n",s);
			}
			else
			{
				if(s[la]=='o' || s[la]=='s' || s[la]=='x' || (s[la]=='h' && s[la-1]=='c') || (s[la]=='h' && s[la-1]=='s'))
					printf("%ses\n",s);
				else
					printf("%ss\n",s);
			}
		}
	}
	return 0;
}