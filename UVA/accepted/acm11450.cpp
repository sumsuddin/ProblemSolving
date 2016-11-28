#include<stdio.h>
#include<queue>
using namespace std;
queue<long>que;
long i,p,k,n,m,t;
bool org[1000],flag;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		flag=1;
		scanf("%ld%ld",&n,&m);

		for(i=0;i<=n;i++)
			org[i]=0;

		org[0]=1;

		while(m--)
		{
			scanf("%ld",&k);

			while(k--)
			{
				scanf("%ld",&p);

				for(i=n;i>=0;i--)
					if(org[i] && i+p<=n)
						que.push(i+p);
			}
			for(i=0;i<=n;i++)
				org[i]=0;
			while(!que.empty())
				org[que.front()]=1,que.pop();
		}
		for(i=n;i>=0;i--)
			if(org[i])
			{
				flag=0;
				printf("%ld\n",i);
				break;
			}
		if(flag)
			printf("no solution\n");
	}
	return 0;
}