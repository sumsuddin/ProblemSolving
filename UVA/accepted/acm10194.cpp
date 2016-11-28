#include<stdio.h>
#include<string.h>
long i,p,ag,bg,j,t,game,n,d,cs;
char st[500],an[100],bn[100],as,bs;

int main()
{
	struct 
	{
		char name[100],cns[100];
		long point,win,ls,ty,gd,gl,gla,gm;
	}team[100];
	
	scanf("%ld",&n);
	getchar();
	while(n--)
	{
		gets(st);
		printf("%s\n",st);

		scanf("%ld",&t);
		getchar();

		for(i=0;i<t;i++)
		{
			gets(team[i].name);
			for(j=0;team[i].name[j];j++)
			{
				if(team[i].name[j]>96 && team[i].name[j]<123)
					team[i].cns[j]=team[i].name[j]-32;
				else
					team[i].cns[j]=team[i].name[j];
			}
			team[i].gl=team[i].win=team[i].gd=team[i].ls=team[i].ty=team[i].gm=team[i].point=team[i].gla=team[i].cns[j]=0;
		}

		scanf("%ld",&game);
		getchar();

		for(j=0;j<game;j++)
		{
			gets(st);

			p=0;
			for(i=0;st[i]!='#';i++)
				an[p++]=st[i];
			p=ag=bg=an[p]=0;
			
			for(i++;st[i]!='@';i++)
				ag=ag*10+(st[i]-'0');

			for(i++;st[i]!='#';i++)
				bg=bg*10+(st[i]-'0');
			
			for(i++;st[i];i++)
				bn[p++]=st[i];
			bn[p]=0;
			d=ag-bg;
			for(i=0;i<t;i++)
				if(!strcmp(team[i].name,an))
				{
					team[i].gm++;
					team[i].gla+=bg;
					team[i].gd+=d;
					team[i].gl+=ag;
					if(d>0)
					{
						team[i].win++;
						team[i].point+=3;
					}

					else
						if(d==0)
						{
							team[i].ty++;
							team[i].point++;
						}
						else
							team[i].ls++;
					break;
				}
			for(i=0;i<t;i++)
				if(!strcmp(team[i].name,bn))
				{
					team[i].gm++;
					team[i].gla+=ag;
					team[i].gd-=d;
					team[i].gl+=bg;
					if(d<0)
					{
						team[i].win++;
						team[i].point+=3;
					}

					else
						if(d==0)
						{
							team[i].ty++;
							team[i].point++;
						}
						else
							team[i].ls++;
					break;
				}
		}
		for(i=0;i<t;i++)
		{
			for(j=i+1;j<t;j++)
				if(team[i].point<team[j].point)
				{
					team[31]=team[i];
					team[i]=team[j];
					team[j]=team[31];
				}
				else
					if(team[i].point==team[j].point)
					{
						if(team[i].win<team[j].win)
						{
							team[31]=team[i];
							team[i]=team[j];
							team[j]=team[31];
						}
						else
							if(team[i].win==team[j].win)
							{
								if(team[i].gd<team[j].gd)
								{
									team[31]=team[i];
									team[i]=team[j];
									team[j]=team[31];
								}
								else
									if(team[i].gd==team[j].gd)
									{
										if(team[i].gl<team[j].gl)
										{
											team[31]=team[i];
											team[i]=team[j];
											team[j]=team[31];
										}
										else
											if(team[i].gl==team[j].gl)
											{
												if(team[i].gm>team[j].gm)
												{
													team[31]=team[i];
													team[i]=team[j];
													team[j]=team[31];
												}
												else
													if(team[i].gm==team[j].gm)
													{
														if(strcmp(team[i].cns,team[j].cns)>0)
														{
															team[31]=team[i];
															team[i]=team[j];
															team[j]=team[31];
														}
													}
											}
									}
							}
					}
		}

		cs=1;
		for(i=0;i<t;i++)
			printf("%ld) %s %ldp, %ldg (%ld-%ld-%ld), %ldgd (%ld-%ld)\n",cs++,team[i].name,team[i].point,team[i].gm,team[i].win,team[i].ty,team[i].ls,team[i].gd,team[i].gl,team[i].gla);
		if(n)
			printf("\n");
	}
	return 0;
}