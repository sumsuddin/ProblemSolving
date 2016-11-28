#include<stdio.h>
bool tru,com,dgt,as,md;
int i,p,s[55],d;
char st[1000],sc[55];

int main()
{
	while(gets(st))
	{
		p=0;
		for(i=0;i<25;i++)
		{
			sc[i]='+';
			s[i]=0;
		}
		tru=dgt=com=1;d=1;
		for(i=0;st[i];i++)
		{
			if(dgt && (st[i]=='+' || st[i]=='-' || st[i]=='*' || st[i]=='/'))
			{
				if(com)
				{
					sc[p]=st[i];
					com=0;
				}
				else
				{
					if(st[i]=='-')
						d*=-1;
				}

			}
			else
			{
				if(st[i]>47 && st[i]<58)
				{
					s[p]=s[p]*10+(st[i]-'0');
					dgt=0;
				}
				else if(dgt==0)
				{
					i--;
					dgt=1;
					s[p]*=d;
					d=1;
					p++;
					com=1;
				}
				else if(st[i]=='=')
				{
					st[0]=' ';
					st[1]='=';
					st[2]=' ';
					i++;
					for(d=3;st[i];i++)
					{
						if(st[i]!=' ')
							st[d++]=st[i];
					}
					st[d]=0;
					break;
				}
			}
		}

			if(sc[0]=='-')
				s[0]*=-1;
			printf("%d",s[0]);
			for(i=1;i<p;i++)
			{
				printf(" %c %d",sc[i],s[i]);
			}
			printf("%s\n",st);
			
			while(1)
			{
				md=as=0;
				for(i=1;i<p;i++)
				{	if(sc[i]=='*' || sc[i]=='/')
					{
						md=1;
						break;
					}
					else
						as=1;
				}
				if(md)
				{
					for(i=1;i<p;i++)
					{
						if(sc[i]=='*')
						{
							p--;
							s[i-1]=s[i-1]*s[i];
							for(;i<p;i++)
							{
								sc[i]=sc[i+1];
								s[i]=s[i+1];
							}
							break;
						}
						else
						if(sc[i]=='/')
						{
							p--;
							s[i-1]=s[i-1]/s[i];
							for(;i<p;i++)
							{
								sc[i]=sc[i+1];
								s[i]=s[i+1];
							}
							break;
						}
					}
					printf("%d",s[0]);
					for(i=1;i<p;i++)
					{
						printf(" %c %d",sc[i],s[i]);
					}
					printf("%s\n",st);
				}
				else if(as)
				{
					for(i=1;i<p;i++)
					{
						if(sc[i]=='+')
						{
							p--;
							s[i-1]=s[i-1]+s[i];
							for(;i<p;i++)
							{
								sc[i]=sc[i+1];
								s[i]=s[i+1];
							}
							break;
						}
						else
						{
							p--;
							s[i-1]=s[i-1]-s[i];
							for(;i<p;i++)
							{
								sc[i]=sc[i+1];
								s[i]=s[i+1];
							}
							break;
						}
					}
					printf("%d",s[0]);
					for(i=1;i<p;i++)
					{
						printf(" %c %d",sc[i],s[i]);
					}
					printf("%s\n",st);
				}
				else
					break;
			}
	}
	return 0;
}
