#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
queue<int>que;

long i,j,sum,n,apa[500],p,q,la,cnt[15];
bool vst[500][500];
char sy[210][210][50],st[100],big[50];

void init()
{
	for(i=0;i<12;i++)
	{
		for(j=0;j<210;j++)
			vst[i][j]=1;
	}
	for(j=0;j<210;j++)
		apa[j]=0;
}

int main()
{
	gets(st);
	sscanf(st,"%ld",&n);
	getchar();
	while(n--)
	{
		p=0;
		while(gets(st) && st[0]!='*')
		{
			la=strlen(st);
			strcpy(sy[la][(cnt[la])++],st);
		}

		while(gets(st))
		{
			if(st[0]==0)
			{
				printf("\n");
				break;
			}
			init();
			sscanf(st,"%s%s",big,st);
			la=strlen(big);
			for(i=0;i<cnt[la];i++)
				if(strcmp(big,sy[la][i])==0)
				{
					que.push(i);
					vst[la][i]=0;
					break;
				}

			while(!que.empty())
			{
				q=que.front();

				que.pop();

				for(i=0;i<cnt[la];i++)
				{
					sum=0;

					if(vst[la][i])
					{
						for(j=0;j<la;j++)
						{
							if(sy[la][q][j]!=sy[la][i][j])
								sum++;
						}
						if(sum==1)
						{
							vst[la][i]=0;
							apa[i]=apa[q]+1;
							if(strcmp(sy[la][i],st)==0)
							{
								while(!que.empty())
									que.pop();
								printf("%s %s %ld\n",big,st,apa[q]+1);
								break;
							}
							que.push(i);
						}
					}
				}
			}
		}
		for(j=0;j<15;j++)
			cnt[j]=0;
	}
	return 0;
}