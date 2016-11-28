#include<stdio.h>
#include<string.h>

int main()
{
	char st[1000000],sy[1000000];
	int a,b,i,j;
	while(scanf("%s%s",st,sy)==2)
	{
		b=j=0;
		for(i=0;st[i];i++)
		{
			a=0;
			for(j=j;sy[j];j++)
			{
				if(st[i]==sy[j])
				{
					a=1;
					j++;
					break;
				}
			}
			if(!a)
			{
				b=1;
				break;
			}

		}
		if(!b && strlen(st)<=strlen(sy))
			printf("Yes\n");
		else
			printf("No\n");	
	}
	return 0;
}