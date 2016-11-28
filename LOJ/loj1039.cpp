#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
queue<long> que;
bool flag;

long sr[10];
long i,t,n,end[5],st[5],par[30][30][30],j,k,cs=1;
char str[500],endr[500],syr[500];
bool mp[30][30][30],vst[30][30][30];

void stop()
{
	while(!que.empty())
		que.pop();
	printf("%ld\n",par[sr[0]][sr[1]][sr[2]]);

	flag=0;
}

void bfs()
{
	que.push(st[0]);
	que.push(st[1]);
	que.push(st[2]);
	par[st[0]][st[1]][st[2]]=0;
	vst[st[0]][st[1]][st[2]]=0;

	while(!que.empty())
	{
		st[0]=que.front();
		que.pop();
		st[1]=que.front();
		que.pop();
		st[2]=que.front();
		que.pop();

		for(i=0;i<3 && flag;i++)
		{
			sr[0]=st[0],sr[1]=st[1],sr[2]=st[2];
			sr[i]--;
			if(sr[i]<0)
				sr[i]=25;

			if(vst[sr[0]][sr[1]][sr[2]] && mp[sr[0]][sr[1]][sr[2]])
			{
				vst[sr[0]][sr[1]][sr[2]]=0;
				par[sr[0]][sr[1]][sr[2]]=par[st[0]][st[1]][st[2]]+1;
				if(sr[0]==end[0] && sr[1]==end[1] && sr[2]==end[2])
				{
					stop();
					break;
				}

				que.push(sr[0]);
				que.push(sr[1]);
				que.push(sr[2]);
			}
			sr[0]=st[0],sr[1]=st[1],sr[2]=st[2];
			sr[i]++;
			if(sr[i]>25)
				sr[i]=0;

			if(vst[sr[0]][sr[1]][sr[2]] && mp[sr[0]][sr[1]][sr[2]])
			{
				vst[sr[0]][sr[1]][sr[2]]=0;
				par[sr[0]][sr[1]][sr[2]]=par[st[0]][st[1]][st[2]]+1;
				if(sr[0]==end[0] && sr[1]==end[1] && sr[2]==end[2])
				{
					stop();
					break;
				}

				que.push(sr[0]);
				que.push(sr[1]);
				que.push(sr[2]);
			}
		}
	}
}

int main()
{
	scanf("%ld",&t);
	

	
	while(t--)
	{
		for(i=0;i<27;i++)
			for(j=0;j<27;j++)
				for(k=0;k<27;k++)
					mp[i][j][k]=vst[i][j][k]=1;


		scanf("%s",str);
		st[0]=str[0]-'a';
		st[1]=str[1]-'a';
		st[2]=str[2]-'a';

		scanf("%s",endr);
		end[0]=endr[0]-'a';
		end[1]=endr[1]-'a';
		end[2]=endr[2]-'a';

		scanf("%ld",&n);

		while(n--)
		{
			scanf("%s%s%s",syr,str,endr);
			for(i=0;syr[i];i++)
			{
				for(j=0;str[j];j++)
					for(k=0;endr[k];k++)
						mp[syr[i]-'a'][str[j]-'a'][endr[k]-'a']=0;
			}
		}
		flag=1;
		printf("Case %ld: ",cs++);
		if(st[0]==end[0] && st[1]==end[1] && st[2]==end[2] && mp[st[0]][st[1]][st[2]])
		{
			printf("0\n");
			flag=0;
		}
		if(flag && mp[st[0]][st[1]][st[2]] && mp[end[0]][end[1]][end[2]])
			bfs();
		if(flag)
			printf("-1\n");
		
	}
	return 0;
}