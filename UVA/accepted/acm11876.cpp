#include<stdio.h>
#include<math.h>
long sq,n,cs=1,i,j,sum,am,psum,t,pos[1000050];
bool nod[1000050];

long div(long ii)
{
	if(ii==1)
		return 1;
	else
	{
		sum=0;
		sq=(long)sqrt(ii);
		for(t=1;t<=sq;t++)
		{
			if(ii%t==0)
				sum+=2;
		}
		if(sq*sq==ii)
			sum--;
	}
	return sum;
}
int main()
{
	am=1;
	nod[1]=1;
	for(i=1;am<1000001;i++)
	{
		am=am+div(am);
		nod[am]=1;
	}

	for(i=0;i<1000001;i++)
	{
		pos[i]+=pos[i-1];
		if(nod[i])
			pos[i]++;
	}

	scanf("%ld",&n);
	while(n--)
	{
		sum=0;
		scanf("%ld%ld",&i,&j);
		printf("Case %ld: %ld\n",cs++,pos[j]-pos[i]+nod[i]);
	}
	return 0;
}
