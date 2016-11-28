#include<stdio.h>
#include<math.h>

long i,j,lst,a,sq,cnt[3000055],pre[3000055],prm[3000055],prnt[10000050];
bool bu[3000050];

void sieve()
{
	bu[0]=1;
	bu[1]=1;

	for(i=4;i<3000000;i+=2)
		bu[i]=1;

	for(i=3;i<3000000;i+=2)
	{
		if(bu[i]==0)
		{
			prm[lst++]=i;
			for(j=3*i;j<3000000;j+=(2*i))
				bu[j]=1;
		}
	}

}

int main()
{
	prm[0]=2;
	lst=1;
	sieve();

	for(i=2;i<3000000;i++)
	{
		if(bu[i]==0)
		{
			cnt[i]=1;
			for(j=2*i;j<3000000;j+=i)
			{
				a=j;
				while((a%i)==0)
					a/=i,cnt[j]++;
			}
		}
	}
	pre[0]=1;
	pre[1]=1;
	pre[2]=1;
	for(i=3;i<3000000;i++)
		pre[i]=pre[i-1]+cnt[i];

	j=2;
	for(i=1;i<10000001;i++)
		for(j=j;j<3000000;j++)
			if(pre[j]>i)
			{
				prnt[i]=j-1;
				break;
			}
	prnt[0]=-1;
	scanf("%ld",&sq);
	while(sq--)
	{
		scanf("%ld",&a);
		printf("%ld\n",prnt[a]+1);
	}

	return 0;
}