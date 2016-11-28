#include<stdio.h>
#include<math.h>
#include<queue>
using namespace std;
queue<long>que;
long i,j,a,p,st[10700][1010],sq,cs=1,dist[10700];
bool vst[10700],flag;

int main()
{
	for(i=4;i<1001;i++)
	{
		a=i;
		p=0;
		if(a%2==0)
		{
			while(a%2==0)
				a/=2;
			st[i][p++]=2;
		}
		sq=sqrt(i)+1;
		for(j=3;j<=sq;j+=2)
		{
			if(a%j==0)
			{
				while(a%j==0)
					a/=j;
				st[i][p++]=j;
			}
		}
		if(a>1 && a!=i)
			st[i][p]=a;

	}
	while(scanf("%ld%ld",&i,&p) &&( i || p))
	{
		if(i==p)
		{
			printf("Case %ld: 0\n",cs++);
			continue;
		}
		que.push(i);
		vst[i]=1;
		flag=1;
		while(!que.empty())
		{
			a=que.front();
			que.pop();
			
			for(j=0;st[a][j];j++)
			{
				sq=a+st[a][j];
				if(sq==p)
				{
					while(!que.empty())
						que.pop();
					printf("Case %ld: %ld\n",cs++,dist[a]+1);
					flag=0;
					break;
				}
				else if(vst[sq]==0 && sq<1001)
				{
					que.push(sq);
					vst[sq]=1;
					dist[sq]=dist[a]+1;
				}
			}	
		}
		if(flag)
			printf("Case %ld: -1\n",cs++);
		for(i=0;i<1001;i++)
			dist[i]=vst[i]=0;
	}
	return 0;
}