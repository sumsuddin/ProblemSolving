#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
queue<long>que;

long i,j,t,k,l,p,q,black,white,sum,pra,qra;
char st[100][100],c,ck;
bool vst[100][100];
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
bool check(long i,long j)
{
	que.push(i);
	que.push(j);

	c=st[i-1][j];

	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			vst[i][j]=1;

	while(!que.empty())
	{
		i=que.front();
		que.pop();
		j=que.front();
		que.pop();

		if(i<=0 || i>=8 || j<=0 || j>=8)
		{
			while(!que.empty())
				que.pop();

			return 0;
		}
		else
		{
			if(st[i-1][j]!=c && vst[i-1][j])
			{
				vst[i-1][j]=0;
				que.push(i-1);
				que.push(j);
			}
			if(st[i+1][j]!=c && vst[i+1][j])
			{
				vst[i+1][j]=0;
				que.push(i+1);
				que.push(j);
			}
			if(st[i][j-1]!=c && vst[i][j-1])
			{
				vst[i][j-1]=0;
				que.push(i);
				que.push(j-1);
			}
			if(st[i][j+1]!=c && vst[i][j+1])
			{
				vst[i][j+1]=0;
				que.push(i);
				que.push(j+1);
			}
		}
	}
	while(!que.empty())
		que.pop();
	return 1;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{

		for(i=0;i<9;i++)
			scanf("%s",st[i]);

		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(check(i,j))
				{
					if(st[i-1][j]!='.')
						st[i][j]=st[i-1][j];
				}
			}
		}

		black=white=0;

		for(i=0;i<9;i++)
		{
			for(j=0;j<9;(i==0 || i==8)?j++:j+=8)
			{
				if(st[i][j]=='.')
				{
					ck='.';

					que.push(i);
					que.push(j);
					st[i][j]='0';
					sum=0;
					while(!que.empty())
					{
						p=que.front();
						que.pop();
						q=que.front();
						que.pop();
						sum++;
						for(k=0;k<4;k++)
						{
							pra=p+x[k];
							qra=q+y[k];

							if(pra>=0 && pra<9 && qra>=0 && qra<9)
							{
								if(st[pra][qra]=='.')
								{
									st[pra][qra]='0';
									que.push(pra);
									que.push(qra);
								}
								else
									if(ck=='.' && (st[pra][qra]=='X' || st[pra][qra]=='O'))
										ck=st[pra][qra];
									else
										if(st[pra][qra]!='0' && st[pra][qra]!=ck)
											ck=',';
							}
						}
					}
						if(ck=='O')
							white+=sum;
						else
							if(ck=='X')
								black+=sum;
				}
			}
		}

		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
				if(st[i][j]=='X')
					black++;
				else if(st[i][j]=='O')
					white++;
		}
		printf("Black %ld White %ld\n",black,white);
	}
	return 0;
}
