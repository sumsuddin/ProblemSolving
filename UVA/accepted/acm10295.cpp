#include<stdio.h>
#include<string.h>
long i,j,n,m,d;
double sum,value[10005];
char s[10005][500],st[500],word[500];
int main()
{
	gets(st);
	sscanf(st,"%ld%ld",&n,&m);

	for(i=0;i<n;i++)
	{
		gets(st);
		sscanf(st,"%s %lf",s[i],&value[i]);
	}
	while(m)
	{
		gets(st);
		if(strcmp(st,".")==0)
		{
			m--;
			printf("%.0lf\n",sum);
			sum=0;
		}
		else
		{
			d=0;
			for(i=0;;i++)
			{
				if(st[i]==' ')
				{
					word[d]=0;
					d=0;
					for(j=0;j<n;j++)
					{
						if(strcmp(word,s[j])==0)
						{
							sum+=value[j];
							break;
						}
					}
				}
				else
				{
					if(st[i])
						word[d++]=st[i];
					else
					{
						word[d]=0;
						for(j=0;j<n;j++)
						{
							if(strcmp(word,s[j])==0)
							{
								sum+=value[j];
								break;
							}
						}
						break;
					}
				}
			}
		}
	}
	return 0;
}