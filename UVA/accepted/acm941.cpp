#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char st[100],sy[100];
bool fil[100];
typedef long long lll;
lll i,j,a,fact[50],l,t,ind[100],sum,d;
int main()
{
	scanf("%lld",&t);

	fact[0]=1;
	for(i=1;i<22;i++)
		fact[i]=fact[i-1]*i;

	while(t--)
	{
		scanf("%s%lld",st,&sum);
		l=strlen(st);
		sort(st,st+l);
		strcpy(sy,st);
		for(i=0;i<l;i++)
			fil[i]=0;
		sum%=fact[l];

		for(i=0;sy[i];i++)
		{
			a=sum/fact[l-i-1];
			sum-=a*fact[l-i-1];
			d=a;
			for(j=0;j<l && d>=0;j++)
				if(fil[j]==0)
					d--;
			j--;
			fil[j]=1;
			printf("%c",sy[j]);
		}
		printf("\n");
	}
	return 0;
}