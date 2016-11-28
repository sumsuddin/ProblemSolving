#include<stdio.h>
#include<queue>
using namespace std;
queue<int>stk;
long i,j,apa[500][500],e11,e22,s1,s2,sum,p,q,an,pan,qan;
bool flag,st[20][20];
char sy[20],c1,c2;

int h[] = { 1,1,-1,-1,2,2,-2,-2 };
int v[] = { 2,-2,2,-2,1,-1,1,-1 };
bool check(long aa,long bb)
{
	if(aa==e11 && bb==e22)
	{
		while(!stk.empty())
			stk.pop();
		printf("To get from %c%ld to %c%ld takes %ld knight moves.\n",s1+96,s2,e11+96,e22,apa[aa][bb]);
	}
	return 0;
}


void bfs()
{
	flag=0;
	stk.push(s1);
	stk.push(s2);
	apa[s1][s2]=0;
	while(!stk.empty())
	{
		p=stk.front();
		stk.pop();
		q=stk.front();
		stk.pop();

		for(an=0;an<8;an++)
		{
			pan=p-h[an];
			qan=q-v[an];
			if(st[pan][qan]==1)
			{
				apa[pan][qan]=apa[p][q]+1;

				if(check(pan,qan))
				{
					flag=1;
					break;
				}

				stk.push(pan);
				stk.push(qan);
				st[pan][qan]=0;
			}
		}
		if(flag)
			break;
	}
}
int main()
{
	while(gets(sy))
	{
		sscanf(sy,"%c%ld%*c%c%ld",&c1,&s2,&c2,&e22);

		s1=c1-96;
		e11=c2-96;
		if(s1==e11 && s2==e22)
			printf("To get from %c%ld to %c%ld takes %ld knight moves.\n",s1+96,s2,e11+96,e22,0);
		else
		{
			for(i=1;i<9;i++)
				for(j=1;j<9;j++)
					st[i][j]=1;
			bfs();
		}
	}
	return 0;
}