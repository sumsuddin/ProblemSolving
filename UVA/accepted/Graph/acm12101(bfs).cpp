#include<stdio.h>
#include<queue>
using namespace std;
queue<long>que;
long i,j,p,b,a,t,par[10050];
bool bu[10040],vst[10050],flag;

void prin(long p)
{
	if(p<0)
		return;
	prin(par[p]);
	printf("%ld\n",p);
}

void bfs(long st)
{
	long i,j,sy[10],sr[10],bc;
	que.push(st);
	vst[st]=0;

	while(!que.empty())
	{
		a=que.front();
		que.pop();
		bc=a;

		sy[0]=a/1000;
		a%=1000;

		sy[1]=a/100;
		a%=100;

		sy[2]=a/10;
		a%=10;

		sy[3]=a;

		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
				sr[j]=sy[j];

			for(j=0;j<10;j++)
			{
				if(sy[i]==j || (i==0 && j==0))
					continue;
				else
					sr[i]=j;

				a=sr[3]+sr[2]*10+sr[1]*100+sr[0]*1000;
				if(vst[a] && bu[a]==0)
				{
					par[a]=par[bc]+1;
					if(a==b)
					{
						while(!que.empty())
							que.pop();
						printf("%ld\n",par[a]);
						flag=0;
						break;
					}
					else
						que.push(a),vst[a]=0;
				}
			}
			if(flag==0)
				break;
		}
	}
}


int main()
{
	for(i=4;i<10000;i+=2)
		bu[i]=1;

	for(i=3;i<10000;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=i*i;j<10000;j+=2*i)
				bu[j]=1;
		}
	}

	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&a,&b);

		for(i=1000;i<10000;i++)
			vst[i]=1;

		if(a==b)
		{
			if(bu[a]==0)
				printf("0\n");
			else
				printf("Impossible\n");
			continue;
		}

		if(bu[a] || bu[b])
		{
			printf("Impossible\n");
			continue;
		}

		flag=1;

		par[a]=0;

		bfs(a);

		if(flag)
			printf("Impossible\n");
	}
	return 0;
}
