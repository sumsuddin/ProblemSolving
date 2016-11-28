#include<stdio.h>
bool bu[100000],flag,fl,ff;
long i,j,d,x,sum,a,b,start,c;
struct 
{
	long count,dif,start;
}
prin[100000];
int main()
{
	bu[0]=1;
	bu[1]=1;

	for(i=4;i<100000;i+=2)
		bu[i]=1;

	for(i=3;i<100000;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=3*i;j<100000;j+=(2*i))
				bu[j]=1;
		}
	}

		flag=ff=1;sum=fl=c=0;
		for(i=1;i<=70000;i+=2)
		{	

			if(bu[i]==0)
			{
				if(fl)
				{
					d=i-x;

					if(ff && (bu[x-d]!=0 || x-d>=a))
						start=i-d,c=d,ff=0;

					if(d==c)
					{
						sum++;
					}
					else
					{
						if(sum>1)
						{
							prin[start].start=start;
							prin[start].dif=c;
							prin[start].count=sum;
						}
						if(bu[x-i+x]!=0 || x-i+x>=a)
						{
							c=i-x;
							start=x;
							sum=1;
						}
						else
						{
							ff=1;
							sum=0;
						}
					}
					x=i;
				}
				else
				{
					x=i;
					fl=1;
				}
			}
		}

	while(~scanf("%ld%ld",&a,&b) && (a||b))
	{
		if(a>b)
			a^=b^=a^=b;

		for(i=a;i<=b;i++)
		{
			if(prin[i].start && prin[i].start+prin[i].count*prin[i].dif<=b)
			{
				c=prin[i].start;
				printf("%ld",c);
				for(j=0;j<prin[i].count;j++)
					printf(" %ld",c+=prin[i].dif);
				printf("\n");
			}
		}
	}
	return 0;
}