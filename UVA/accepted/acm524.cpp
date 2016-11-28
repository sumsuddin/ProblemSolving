#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[20][90000];
long a[20],pr[50],n,re,len[20],cs=1;
void call(long s,long wrt,long cor,vector<long>v)
{
	long i;
	
	if(s==re)
	{
		if(pr[cor+wrt]==0)
		{
			vc[n][len[n]++]=v;
		}
		return;
	}
	for(i=1;i<=n;i++)
	{
		if((s&(1<<i))==0)
		{
			if(pr[wrt+i]==0)
			{
				v.push_back(i);
				call(s|(1<<i),i,cor,v);
				v.pop_back();
			}
		}
	}
}
int main()
{
	vector<long>vv;
	long i,j;
	pr[0]=1;
	pr[1]=1;
	for(i=4;i<50;i+=2)
		pr[i]=1;
	for(i=3;i<50;i+=2)
	{
		if(pr[i]==0)
		{
			for(j=3*i;j<50;j+=2*i)
				pr[j]=1;
		}
	}
	for(n=2;n<=16;n+=2)
	{
		re=0;
		len[n]=0;
		for(i=0;i<=n;i++)
			re=re|(1<<i);
		vv.push_back(1);

		call(3,1,1,vv);
		vv.pop_back();
	}
	while(~scanf("%ld",&n))
	{
		if(cs>1)
			printf("\n");
		printf("Case %ld:\n",cs++);
		for(i=0;i<len[n];i++)
		{
			printf("%ld",vc[n][0][0]);
			for(j=1;j<vc[n][0].size();j++)
				printf(" %ld",vc[n][i][j]);
			printf("\n");
		}
	}
	return 0;
}