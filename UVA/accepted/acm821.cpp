#include<stdio.h>
long i,j,a,b,sum,st[110][110],ma,cs=1;;
long min(long aa,long bb)
{
	if(aa<bb)
		return aa;
	else
		return bb;
}
	
int main()
{
	while(~scanf("%ld%ld",&a,&b))
	{
		if(a==0 && b==0)
			break;
		else
		{
			ma=0;
			for(i=0;i<102;i++)
				for(j=0;j<102;j++)
					st[i][j]=1000;

			st[a][b]=1;
			if(a>ma)
				ma=a;
			if(b>ma)
				ma=b;

			while(scanf("%ld%ld",&a,&b) && (a || b))
			{
				st[a][b]=1;
				if(a>ma)
					ma=a;
				if(b>ma)
					ma=b;
			}
			ma++;
			for(b=0;b<ma;b++)
				for(i=0;i<ma;i++)
					for(j=0;j<ma;j++)
						st[i][j]=min(st[i][j],st[i][b]+st[b][j]);

			a=sum=0;
			for(i=0;i<ma;i++)
				for(j=0;j<ma;j++)
					if(st[i][j]<1000 && i!=j)
					{
						sum++;
						a+=st[i][j];
					}
			printf("Case %ld: average length between pages = %.3lf clicks\n",cs++,(double)a/(double)sum);
		}
	}
	return 0;	
}