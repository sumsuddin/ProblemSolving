#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
typedef long long lng;
vector<lng>vc[20];
lng mn,mx,i,j,d,p,q,flag,t,cs=1;
void gen()
{
	for(i=2;i<18;i++)
	{
		d=1;
		for(j=1;j<i;j++)
			d*=10;
		for(j=0;j<vc[i-1].size();j++)
		{
			vc[i].push_back(d+vc[i-1][j]);
			vc[i].push_back(2*d+vc[i-1][j]);
		}
	}
}

int main()
{
	vc[1].push_back(2);
	scanf("%lld",&t);
	gen();
//	for(i=0;i<vc[3].size();i++)
//		printf("%ld ",vc[3][i]);

	while(t--)
	{
		scanf("%lld%lld",&p,&q);

		q=(lng)pow(2,q);
		mx=0;flag=1;
		for(i=0;i<vc[p].size();i++)
			if(vc[p][i]%q==0)
			{
				if(vc[p][i]>mx)
					mx=vc[p][i];
				if(flag)
				{
					mn=vc[p][i];
					flag=0;
				}

				if(vc[p][i]<mn)
					mn=vc[p][i];
			}
		if(mn==mx)
			printf("Case %lld: %lld\n",cs++,mx);
		else if(mx)
			printf("Case %lld: %lld %lld\n",cs++,mn,mx);
		else
		    printf("Case %lld: impossible\n",cs++);
	}
	return 0;
}
