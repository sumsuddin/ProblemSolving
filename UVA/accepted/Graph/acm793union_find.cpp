#include<stdio.h>
long i,j,n,t,n1,n2,x,y,a[100000],p1,p2;
char c,sy[50];
bool fg=1;

long parent(long p)
{
	if(a[p]==-1)
		return p;
	else
		parent(a[p]);
}

int main()
{
	gets(sy);
	sscanf(sy,"%ld",&t);
	getchar();

	while(t--)
	{
		n1=n2=0;
		gets(sy);
		sscanf(sy,"%ld",&n);
		for(i=0;i<=n;i++)
			a[i]=-1;
		while(gets(sy) && sy[0]!=0)
		{
			sscanf(sy,"%c %ld%ld",&c,&x,&y);
			if(c=='c')
			{
				p1=parent(x);
				p2=parent(y);
				if(p1!=p2)
					a[p2]=p1;
			}
			else
			{
				p1=parent(x);
				p2=parent(y);

				if(p1==p2)
					n1++;
				else
					n2++;
			}
		}

		if(fg)
		{
              printf("%ld,%ld\n",n1,n2);
              fg=0;
        }
        else
        printf("\n%ld,%ld\n",n1,n2);
        
	}
	return 0;
}
