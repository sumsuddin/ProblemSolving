#include<stdio.h>

long long a[]={2,3,5,7};
long long st[5850],p,i,j,k,s,min;
int main()
{
	st[1]=1;
	for(i=2;i<5843;i++)
	{
		min=2000000005;
		for(j=1;j<i;j++)
		{
			for(k=0;k<4;k++)
			{
				s=st[j]*a[k];
				if(min>s && s>st[i-1])
					min=s;
			}
		}
		st[i]=min;
	}

	while(scanf("%lld",&i),i)
	{
		if((i%10)==1 && (i%100)!=11)
			printf("The %lldst humble number is %lld.\n",i,st[i]);
		else
			if((i%10)==2 && (i%100)!=12)
				printf("The %lldnd humble number is %lld.\n",i,st[i]);
			else
				if((i%10)==3 && (i%100)!=13)
					printf("The %lldrd humble number is %lld.\n",i,st[i]);
				else
					printf("The %lldth humble number is %lld.\n",i,st[i]);

	}
	return 0;
}
