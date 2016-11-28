#include<stdio.h>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
stack<long>stk;
queue<long>que;
long pq[1010],out[1010],ou,pri,i,dir,val,n,qu,stak,j;
bool flag;
int main()
{
	while(~scanf("%ld",&n))
	{
		for(i=0;i<101;i++)
			pq[i]=0;

		ou=0;
		pri=stak=qu=1;
		for(i=0;i<n;i++)
		{
			scanf("%ld%ld",&dir,&val);

			if(dir==1)
			{
				stk.push(val);
				que.push(val);
				pq[val]++;
			}
			else
			{
				if(!que.empty())
				{
					if(que.front()!=val)
						qu=0;
					else 
						que.pop();
				}
				else
					qu=0;

				if(!stk.empty())
				{
					if(stk.top()!=val)
						stak=0;
					else 
						stk.pop();
				}
				else
					stak=0;

				flag=1;
				if(pri)
				{
					for(dir=100;dir>=0;dir--)
					{
						if(pq[dir])
						{
							flag=0;
							pq[dir]--;
							break;
						}
					}
				}
				if(flag || dir!=val)
					pri=0;
			}

		}
		if(pri==1 && stak==0 && qu==0)
			printf("priority queue\n");
		else
			if(stak==1 && pri==0 && qu==0)
				printf("stack\n");
			else
				if(stak==0 && pri==0 && qu==1)
					printf("queue\n");
				else
					if(stak==0 && pri==0 && qu==0)
						printf("impossible\n");
					else
						printf("not sure\n");

		while(!stk.empty())
			stk.pop();
		while(!que.empty())
			que.pop();
	}
	return 0;
}