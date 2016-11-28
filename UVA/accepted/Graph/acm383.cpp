#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
queue<long>que;
long i,j,p,ss,q,mlt,end,par[50],m,n,t,cs=1,qry;
bool vst[50],mat[50][50],tru;
char st[50][50],sx[50],sy[50];		
void bfs()
{
	que.push(ss);
	vst[ss]=0;
	par[ss]=0;
	tru=1;

	while(!que.empty())
	{
		p=que.front();
			que.pop();
		for(i=0;i<n;i++)
		{
			if(mat[p][i] && vst[i])
			{
				vst[i]=0;
				par[i]=par[p]+1;


				if(i==end)
				{
					printf("$%ld\n",mlt*par[i]*100);
					tru=0;
				}
				que.push(i);
			}
		}
	}
	if(tru)
		printf("NO SHIPMENT POSSIBLE\n");
}

int main()
{
	printf("SHIPPING ROUTES OUTPUT\n");
	scanf("%ld",&t);
	while(t--)
	{
		printf("\nDATA SET  %ld\n\n",cs++);
		scanf("%ld%ld%ld",&n,&m,&qry);

		for(i=0;i<n;i++)
		{
			scanf("%s",st[i]);
			for(j=0;j<n;j++)
				mat[i][j]=0;
		}

		while(m--)
		{
			scanf("%s%s",sx,sy);

			for(i=0;i<n;i++)
			{
				if(strcmp(st[i],sx)==0)
					p=i;
				if(strcmp(st[i],sy)==0)
					q=i;
			}

			mat[p][q]=1;
			mat[q][p]=1;
		}

		while(qry--)
		{
			for(i=0;i<n;i++)
				vst[i]=1;

			scanf("%ld%s%s",&mlt,sx,sy);

			for(i=0;i<n;i++)
			{
				if(strcmp(st[i],sx)==0)
					ss=i;
				if(strcmp(st[i],sy)==0)
					end=i;
			}
			bfs();
		}
	}
	printf("\nEND OF OUTPUT\n");
	return 0;
}