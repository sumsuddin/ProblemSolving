#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc;
long h[1000010],i,j,n,ind[1000010],ans[1000010];
bool vst[1000010],flag;
int main()
{
	for(n=0;4*n+1<1000002;n++)
	{
		h[n]=4*n+1;
		ind[4*n+1]=n;
	}

	vst[0]=1;
	for(i=1;i<n;i++)
	{
		if(vst[i]==0)
		{
			flag=1;
			for(j=ind[h[i]];j<n && h[i]*h[j]<1000002;j++)
			{
				vst[ind[h[i]*h[j]]]=1;
				flag=0;
			}
			if(flag)
				break;
		}
	}
	for(i=1;i<n;i++)
		if(vst[ind[h[i]]]==0)
			vc.push_back(h[i]);
	n=vc.size();

	for(i=0;i<n;i++)
	{
		flag=1;
		for(j=i;j<n;j++)
		{
			if(vc[i]*vc[j]<1000002)
			{

				if((vc[i]*vc[j]-1)%4==0)
					ans[vc[i]*vc[j]]=1;
				flag=0;
			}
			else
				break;
		}
		if(flag)
			break;
	}
	for(i=1;i<1000002;i++)
		ans[i]=ans[i-1]+ans[i];

	while(~scanf("%ld",&i),i)
	printf("%ld %ld\n",i,ans[i]);

	return 0;

}