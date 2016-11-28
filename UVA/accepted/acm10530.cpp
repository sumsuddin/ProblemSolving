#include<stdio.h>
#include<string.h>
int n[100005],i,p;
char c[100005][50],st[50];
bool flag;
int main()
{
	while(gets(st))
	{
		sscanf(st,"%d",&n[i]);
		if(n[i]==0)
			break;
		gets(st);
		if(st[0]=='r')
		{
			p=i;
			flag=1;
			while(i--)
			{
				if(n[p]<n[i])
				{
					if(strcmp(c[i],"low")==0)
					{
						flag=0;
						break;
					}
				}
				else
				{
					if(n[p]>n[i])
					{
						if(strcmp(c[i],"high")==0)
						{
							flag=0;
							break;
						}
					}
					else
						if(n[p]==n[i])
							{
								flag=0;
								break;
							}
				}
			}
			if(flag)
				printf("Stan may be honest\n");
			else
				printf("Stan is dishonest\n");
			i=-1;
		}
		else
			sscanf(st,"%*s %s",c[i]);
	
		i++;
	}
	return 0;
}