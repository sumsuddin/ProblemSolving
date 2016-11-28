#include<stdio.h>
#include<string.h>
struct
{
	long pn,ac,prsnt,id;
	struct
	{
		long pan,state;
	}
	sub[20];
}nd[120];

long i,j,t,cs;

char st[50];

void swap()
{
	nd[105]=nd[i];
	nd[i]=nd[j];
	nd[j]=nd[105];
}

int main()
{
	scanf("%ld",&cs);
	getchar();
	getchar();

	while(cs--)
	{
		for(i=1;i<101;i++)
		{
			nd[i].prsnt=0;

			nd[i].ac=nd[i].pn=0;
			nd[i].id=i;

			for(j=0;j<9;j++)
			{
				nd[i].sub[j].pan=0;
				nd[i].sub[j].state=1;
			}

		}

		while(gets(st) && st[0])
		{
			sscanf(st,"%ld%ld%ld%s",&i,&j,&t,st);

			nd[i].prsnt=1;

			if(strcmp(st,"C")==0)
			{
				if(nd[i].sub[j].state)
				{
					nd[i].ac++;
					nd[i].sub[j].pan+=t;
					nd[i].sub[j].state=0;
					nd[i].pn+=nd[i].sub[j].pan;
				}
			}
			else if(strcmp(st,"I")==0)
				nd[i].sub[j].pan+=20;
		}
		for(i=1;i<101;i++)
		{
			for(j=i+1;j<101;j++)
			{
				if(nd[i].prsnt==0 && nd[j].prsnt)
					swap();
				else
					if(nd[i].prsnt && nd[i].prsnt)
					{
						if(nd[i].ac<nd[j].ac)
							swap();
						else if(nd[i].ac==nd[j].ac)
						{
							if(nd[i].pn>nd[j].pn)
								swap();
						}

					}
			}
		}
		for(i=1;i<101;i++)
		{
			if(nd[i].prsnt)
				printf("%ld %ld %ld\n",nd[i].id,nd[i].ac,nd[i].pn);
			else
				break;
		}
		if(cs)
			printf("\n");
	}
	return 0;
}