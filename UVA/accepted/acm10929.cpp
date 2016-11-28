#include<stdio.h>
#include<string.h>

int main()
{
	long int i,ans;
	char st[1002],d;
	while(gets(st))
	{
		if(!strcmp(st,"0"))
			break;
		d=1;ans=0;
		for(i=0;st[i];i++)
		{
			ans+=d*(st[i]-48);
			d*=-1;
		}
		if(ans%11==0)
			printf("%s is a multiple of 11.\n",st);
		else
			printf("%s is not a multiple of 11.\n",st);
	}
	return 0;
}