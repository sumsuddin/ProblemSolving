#include<stdio.h>
#include<stack>
using namespace std;
stack<long>stk;
long i,j,count,t,p,q,an,pan,qan,la;
char st[150][150];
bool sl[150][150];
int h[]={0,0,1,-1,1,-1,1,-1};
int v[]={1,-1,0,0,1,1,-1,-1};
void bfs()
{
	count=0;

	if(st[p-1][q-1]=='W')
	{
		stk.push(p-1);
		stk.push(q-1);
		sl[p-1][q-1]=0;
		count=1;
	}
	while(!stk.empty())
	{
		q=stk.top();
		stk.pop();
		p=stk.top();
		stk.pop();

		for(an=0;an<8;an++)
		{
			pan=p-h[an];
			qan=q-v[an];
			if(st[pan][qan]=='W' && sl[pan][qan] && qan<la && pan<i)
			{
				stk.push(pan);
				stk.push(qan);
				sl[pan][qan]=0;
				count++;
			}
		}
	}
	printf("%ld\n",count);
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		i=0;
		while(~scanf("%s",st[i]) && st[i][0] && (st[i][0]<48 || st[i][0]>'9'))
		{
			for(an=0;st[i][an];an++)
				sl[i][an]=1;
			sl[i][an]=0;
			i++;
		}
		la=an;

		for(an=0;st[i][an];an++)
			sl[i][an]=0;
		sl[i][an]=0;

		sscanf(st[i],"%ld",&p);
		scanf("%ld",&q);

		for(j=0;j<110;j++)
			st[i][j]=0;
		bfs();
		getchar();
		while(gets(st[i+1]) && st[i+1][0] && st[i+1][0]>47 && st[i+1][0]<='9')
		{
			sscanf(st[i+1],"%ld%ld",&p,&q);
			for(j=0;j<i;j++)
			{
				for(count=0;count<la;count++)
					sl[j][count]=1;
				sl[j][count]=0;
			}
			for(count=0;count<=la;count++)
				sl[j][count]=0;
			bfs();
		}
		if(t)
			printf("\n");
	}
	return 0;
}
