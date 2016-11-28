#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[50050];
long i,j,in,s,d,r,c,t,a,cs=1;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&r,&c);

		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
			{
				scanf("%ld",&a);
				vc[i].push_back(a);
			}
		in=c-1;
		d=1;
		s=0;
		for(i=r-1;i>=0;i--)
		{
			in+=(d*=-1);
			for(j=in;j>=0;j-=2)
				s^=vc[i][j];
			vc[i].clear();
		}
		if(s==0)
			printf("Case %ld: lose\n",cs++);
		else
			printf("Case %ld: win\n",cs++);
	}
	return 0;
}