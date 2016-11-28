#include<stdio.h>
#include<string.h>
long i,n,m,s,j;
int main()
{
	struct {
		char name[30],cname[30];
		long ms;
	}str[120];
	while(scanf("%ld",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s : %ld min %ld sec %ld ms",str[i].name,&m,&s,&str[i].ms);
			
			str[i].ms+=(m*60*1000+s*1000);
			for(s=0;str[i].name[s];s++)
			{
				if(str[i].name[s]>96 && str[i].name[s]<123)
					str[i].cname[s]=str[i].name[s]-32;
				else
					str[i].cname[s]=str[i].name[s];
			}
			str[i].cname[s]=0;
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(str[i].ms>str[j].ms)
				{
					str[110]=str[i];
					str[i]=str[j];
					str[j]=str[110];
				}
				else
					if(str[i].ms==str[j].ms)
					{
						if(strcmp(str[i].cname,str[j].cname)>0)
						{
							str[110]=str[i];
							str[i]=str[j];
							str[j]=str[110];
						}
					}
			}
		}
		s=2;m=1;
		for(i=0;i<n;i++)
		{
			if(s==2)
			{
				printf("Row %ld\n",m++);
				s=0;
			}
			s++;
			printf("%s\n",str[i].name);
		}
		printf("\n");
	}
	return 0;
}