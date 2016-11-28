#include<stdio.h>
#include<set>
#include<stack>
using namespace std;
stack<long>stk;
set<long>vc[250];
bool flag;
long i,sum,color[250],n,m,a,t,pp,mm;
void bcl(long p)
{
	stk.push(p);
	while(!stk.empty())
	{
		p=stk.top();
		stk.pop();
		set<long>::iterator it;
		for(it=vc[p].begin();it!=vc[p].end();it++)
		{
		//	if(p==3)
				a=*it;
			if(color[*it]==-1)
			{
				color[*it]=(color[p]==-1)?1:!color[p];

				if(color[p]==1)
					pp++;
				else
					mm++;

				stk.push(*it);
			}
			else
				if(color[p]==color[*it])
					flag=0;
		}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		for(i=1;i<=n;i++)
			vc[i].clear(),color[i]=-1;

		for(i=1;i<=n;i++)
		{
			scanf("%ld",&m);
			
			while(m--)
			{
				scanf("%ld",&a);
				vc[i].insert(a);
				vc[a].insert(i);
			}
		}
		sum=0;
		for(i=1;i<=n;i++)
			if(vc[i].size()==0)
				sum++;

		for(i=1;i<=n;i++)
		{
			pp=mm=0;
			flag=1;
			bcl(i);
			if(flag)
				sum+=(pp>mm)?pp:mm;
		}
		printf("%ld\n",sum);
	}
	return 0;
}