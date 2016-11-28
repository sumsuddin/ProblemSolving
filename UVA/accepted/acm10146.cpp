#include<stdio.h>
#include<string.h>
char st[50],demo[50],i,n;
bool flag=0;
int main()
{
	gets(st);
	sscanf(st,"%ld",&n);


	while(gets(st))
	{
		if(st[0]==0)
		{
			if(flag)
				printf("\n");
			else
				flag=1;

			demo[0]=1;
			demo[1]=0;
			n--;

			gets(st);
		}

		for(i=0;i<=strlen(demo);i++)
		{
			if(st[i]==demo[i] && demo[i]!=0)
			{
				printf(" ");
				demo[i]=st[i];
			}
			else
			{
				demo[i]=st[i];
				demo[i+1]=0;
				break;
			}
		}
		
		printf("%s\n",st);
	if(n<0)
		break;
	}
	return 0;
}