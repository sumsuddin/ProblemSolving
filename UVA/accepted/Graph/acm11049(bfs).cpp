#include<stdio.h>
#include<string.h>
#include<queue>
#define swap(m,n) m^=n^=m^=n
using namespace std;
queue<long>que;

long i,j,p,q,x1,x2,y1,y2,ex,sx,ey,sy;
char ch[10][10],ans[120];;
bool vst[10][10],h[10][10],v[10][10];

void check(long a,long b)
{
	if(a==ex && b==ey)
	{
		x1=0;
		while(!que.empty())
			que.pop();

		p=ex;q=ey;
		while(p!=sx || q!=sy)
		{
			ans[x1++]=ch[p][q];
			if(ch[p][q]=='N')
				p++;
			else if(ch[p][q]=='S')
				p--;
			else if(ch[p][q]=='E')
				q--;
			else if(ch[p][q]=='W')
				q++;	
		}
		ans[x1]=0;
	}
}

void bfs()
{
	que.push(sx);
	que.push(sy);


	while(!que.empty())
	{
		p=que.front();
		que.pop();
		q=que.front();
		que.pop();

		if(p-1>0 && vst[p-1][q] && v[p-1][q])
		{
			vst[p-1][q]=0;
			ch[p-1][q]='N';
			
			que.push(p-1);
			que.push(q);
			check(p-1,q);
		}

		if(p+1<7 && vst[p+1][q] && v[p][q])
		{
			vst[p+1][q]=0;
			ch[p+1][q]='S';
			
			que.push(p+1);
			que.push(q);
			check(p+1,q);
		}

		if(q-1>0 && vst[p][q-1] && h[p][q-1])
		{
			vst[p][q-1]=0;
			ch[p][q-1]='W';
			
			que.push(p);
			que.push(q-1);
			check(p,q-1);
		}

		if(q+1<7 && vst[p][q+1] && h[p][q])
		{
			vst[p][q+1]=0;
			ch[p][q+1]='E';

			que.push(p);
			que.push(q+1);
			check(p,q+1);
		}
	}
	x1=strlen(ans)/2;
	for(i=0,j=strlen(ans)-1;i<x1;i++,j--)
		swap(ans[i],ans[j]);

	printf("%s\n",ans);
}

int main()
{
	while(scanf("%ld%ld",&sy,&sx) && (sy || sx))
	{
		for(i=0;i<7;i++)
			for(j=0;j<7;j++)
			{
				v[i][j]=h[i][j]=vst[i][j]=1;
			}

		scanf("%ld%ld",&ey,&ex);

		for(i=0;i<3;i++)
		{
			scanf("%ld%ld%ld%ld",&y1,&x1,&y2,&x2);

			if(x1==x2)
			{
				if(y1>y2)
					swap(y1,y2);
				for(j=y1+1;j<=y2;j++)
					v[x1][j]=0;
			}
			else
			{
				if(x1>x2)
					swap(x1,x2);
				for(j=x1+1;j<=x2;j++)
					h[j][y1]=0;
			}
		}

		bfs();
	}
	return 0;
}