#include<stdio.h>
#include<string.h>
long i,t,l,r,c,x,y,p,cs=1,h[]={0,1,0,-1},v[]={1,0,-1,0},mn,dir,flag;
char st[100000],mat[1000][1000];

void clear(long r,long c)
{
    long i,j;
    for(i=0;i<=r;i++)
    for(j=0;j<=c;j++)
    mat[i][j]=-1;
}

bool chk(long r,long c)
{
    long i,j;

    for(i=0;i<c;i++)
    for(j=0;j<r;j++)
    if(mat[j][i]!=mat[0][i])
    return 0;

    return 1;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%s",st);
		l=strlen(st);
        mn=100000000;
		flag=1;
		for(i=2;i<l;i++)
		{
		    if(l%i==0)
		    {

		        r=l/i;
		        c=i;
		        p=0;
		        x=y=0;
		        clear(r,c);
		        dir=0;
		        while(p<l)
		        {
		            mat[x][y]=st[p];

		            if(x+h[dir]<0 || x+h[dir]>=r || y+v[dir]<0 || y+v[dir]>=c || mat[x+h[dir]][y+v[dir]]!=-1)
		            {
		                dir++;
		                dir%=4;
		            }

		            x+=h[dir];
		            y+=v[dir];
		            p++;
		        }
		        if(chk(r,c))
		        {
		            flag=0;
		            if(r+c<mn)
		            mn=r+c;
		        }
		    }
		}
		if(flag)
		printf("Case %ld: -1\n",cs++);
		else
		printf("Case %ld: %ld\n",cs++,mn);
	}
	return 0;
}
