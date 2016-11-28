#include<stdio.h>
#include<string.h>
long i,j,c,cs,n,p=1;
char st[100];

int main()
{
	struct 
	{
		char name[100];
		long a,d;
	}pl[20];

	scanf("%ld",&n);
	getchar();
	while(n--)
	{
		for(i=0;i<10;i++)
		{
			gets(st);
			sscanf(st,"%s%ld%ld",pl[i].name,&pl[i].a,&pl[i].d);
		}

		for(i=0;i<10;i++)
		{
			for(j=i+1;j<10;j++)
			{
				if(pl[i].a<pl[j].a)
				{
					pl[13]=pl[i];
					pl[i]=pl[j];
					pl[j]=pl[13];
				}
				else
					if(pl[i].a==pl[j].a)
					{
						if(pl[i].d>pl[j].d)
						{
							pl[13]=pl[i];
							pl[i]=pl[j];
							pl[j]=pl[13];
						}
						else
							if(pl[i].d==pl[j].d)
							{
								if(strcmp(pl[i].name,pl[j].name)>0)
								{
									pl[13]=pl[i];
									pl[i]=pl[j];
									pl[j]=pl[13];
								}
							}
					}
			}
		}
		for(i=0;i<5;i++)
		{
			for(j=i+1;j<5;j++)
			{
				if(strcmp(pl[i].name,pl[j].name)>0)
				{
					pl[13]=pl[i];
					pl[i]=pl[j];
					pl[j]=pl[13];
				}
			}
		}
		for(i=5;i<10;i++)
		{
			for(j=i+1;j<10;j++)
			{
				if(strcmp(pl[i].name,pl[j].name)>0)
				{
					pl[13]=pl[i];
					pl[i]=pl[j];
					pl[j]=pl[13];
				}
			}
		}
		printf("Case %ld:\n(%s, %s, %s, %s, %s)\n(%s, %s, %s, %s, %s)\n",p++,pl[0].name,pl[1].name,pl[2].name,pl[3].name,pl[4].name,pl[5].name,pl[6].name,pl[7].name,pl[8].name,pl[9].name);
	}
	return 0;
}