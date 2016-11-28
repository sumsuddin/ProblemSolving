#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc;
char ch[8];
long i,j,p,n,cs=1;

int main()
{
	while(scanf("%ld%ld",&p,&n)&& (p||n))
	{
		for(i=1;i<1500 && i<=p;i++)
		{
			vc.push_back(i);
		}
		printf("Case %ld:\n",cs++);
		while(n--)
		{
			scanf("%s",ch);
			if(ch[0]=='E')
			{
				scanf("%ld",&j);
				for(i=0;i<vc.size();i++)
					if(vc[i]==j)
						vc.erase(vc.begin()+i);
				vc.insert(vc.begin(),j);
			}
			else
			{
				printf("%ld\n",vc[0]);
				vc.push_back(vc[0]);
				vc.erase(vc.begin());
			}			
		}
		vc.clear();
	}
	return 0;
}