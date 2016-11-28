#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
queue<long> que;
bool flag;

char sr[10],sy[10];
long i,t,n,end,st,par[100100],tm,str[10],endr[10],syr[10];
bool mp[100100],vst[100100];

void stop()
{
	printf("%ld\n",par[tm]);

	flag=0;
}

void bfs()
{
	que.push(st);
	par[st]=0;
	vst[st]=0;

	while(!que.empty())
	{
		st=que.front();
		que.pop();

		tm=st;
		for(i=3;i>=0;i--)
		{
			sr[i]=tm%10+'0';
			tm/=10;
		}
		sr[4]=0;
		strcpy(sy,sr);

		for(i=0;i<=3;i++)
		{
			strcpy(sr,sy);
			sr[i]--;
			if(sr[i]<'0')
				sr[i]='9';

			tm=(sr[0]-'0')*1000+(sr[1]-'0')*100+(sr[2]-'0')*10+(sr[3]-'0');

			if(vst[tm] && mp[tm])
			{
				vst[tm]=0;
				par[tm]=par[st]+1;
				if(tm==end)
				{
					stop();
					break;
				}

				que.push(tm);
			}
			strcpy(sr,sy);
			sr[i]++;
			if(sr[i]>'9')
				sr[i]='0';
			tm=(sr[0]-'0')*1000+(sr[1]-'0')*100+(sr[2]-'0')*10+(sr[3]-'0');

			if(vst[tm] && mp[tm])
			{
				vst[tm]=0;
				par[tm]=par[st]+1;
				if(tm==end)
				{
					stop();
					break;
				}

				que.push(tm);
			}
		}
	}
}

int main()
{
	scanf("%ld",&t);
	

	
	while(t--)
	{
		for(i=0;i<100000;i++)
			mp[i]=vst[i]=1;
		for(i=0;i<4;i++)
			scanf("%ld",&str[i]);
		st=(str[0])*1000+(str[1])*100+(str[2])*10+(str[3]);
		for(i=0;i<4;i++)
			scanf("%ld",&endr[i]);
		end=(endr[0])*1000+(endr[1])*100+(endr[2])*10+(endr[3]);

		scanf("%ld",&n);

		while(n--)
		{
			for(i=0;i<4;i++)
				scanf("%ld",&syr[i]);
			tm=(syr[0])*1000+(syr[1])*100+(syr[2])*10+(syr[3]);
			mp[tm]=0;
		}
		flag=1;
		if(st==end && mp[st])
		{
			printf("%ld\n",0);

			flag=0;
		}
		else
			bfs();
		while(!que.empty())
			que.pop();
		if(flag)
			printf("-1\n");
		
	}
	return 0;
}