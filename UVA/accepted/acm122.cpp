#include<stdio.h>
#include<map>
#include<string.h>
#include<string>
#define swap(m,n) m^=n^=m^=n
using namespace std;
map<string,long>mp;
#define swap(m,n) m^=n^=m^=n
long dig[500],i,p,j,l;
char st[500],sy[500][500],c;
bool flag,tru;

void srt()
{
	for(i=0;i<p;i++)
		for(j=i+1;j<p;j++)
			if((strlen(sy[i])>strlen(sy[j])) || ((strlen(sy[i])==strlen(sy[j])) && strcmp(sy[i],sy[j])>0))
			{
				strcpy(st,sy[i]);
				strcpy(sy[i],sy[j]);
				strcpy(sy[j],st);
				swap(dig[i],dig[j]);
			}
}

int main()
{
	p=0;
	while(~scanf("%s",st))
	{
		if(strcmp(st,"()")==0)
		{
			flag=1;

			srt();
			mp.clear();
			for(i=0;i<p;i++)
			{
				if(mp[sy[i]])
				{
					flag=0;
					break;
				}
				else
					mp[sy[i]]=1;
				j=strlen(sy[i]);
				strcpy(st,sy[i]);
				if(sy[i][0]!=')')
				{
					st[j-2]=')';
					st[j-1]=0;
				}

				if(mp[st]==0)
				{
					flag=0;
					break;
				}
			}
			if(flag && sy[0][0]!=0)
			{
				for(i=0;i<p;i++)
				{
					if(i)
						printf(" %ld",dig[i]);
					else
						printf("%ld",dig[i]);
				}
				printf("\n");
			}
			else
				printf("not complete\n");
			p=0;
		}
		else
		{
			sscanf(st+1,"%ld,%s",&dig[p],sy[p]);
			p++;
		}
	}
	return 0;
}
