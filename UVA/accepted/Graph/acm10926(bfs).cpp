#include<stdio.h>
#include<queue>
using namespace std;
queue<long>que;
long i,j,ans,mx,sum,n,m,p,a;
bool vst[120],mat[120][120];
int main()
{
	while(scanf("%ld",&n),n)
	{
		for(i=1;i<=n;i++)
			for(m=1;m<=n;m++)
				mat[i][m]=0;

		for(i=1;i<=n;i++)
		{
			scanf("%ld",&m);
			while(m--)
			{
				scanf("%ld",&a);
				mat[i][a]=1;
			}
		}
		mx=0;ans=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				vst[j]=1;

			que.push(i);
			sum=vst[i]=0;
			while(!que.empty())
			{
				p=que.front();
				que.pop();
				sum++;

				for(j=1;j<=n;j++)
					if(mat[p][j] && vst[j])
					{
						vst[j]=0;
						que.push(j);
					}
			}
			if(sum>mx)
			{
				mx=sum;
				ans=i;
			}
		}
		printf("%ld\n",ans);
	}
	return 0;
}