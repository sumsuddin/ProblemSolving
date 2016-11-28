#include<stdio.h>
#include<string.h>
long i,j,k,l;
bool flag;
char st[1000050];
int main()
{
	while(~scanf("%s",st))
	{
		printf("%s",st);
		flag=1;
		l=strlen(st);
		for(i=0;st[i];i++)
		{
			flag=1;
			for(j=i,k=l-1;j<k;j++,k--)
				if(st[j]!=st[k])
				{
					flag=0;
					break;
				}
			if(flag)
				break;
		}
		while(i--)
			printf("%c",st[i]);
		printf("\n");
	}
	return 0;
}