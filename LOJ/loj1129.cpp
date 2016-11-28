#include<stdio.h>
#include<string.h>
long tri[100009][12],lst,n,t,cs=1,len,i,j;
bool flag,go,ind[100009];
char st[15];
void make(long root,long in)
{
	if(in<len && flag)
	{
		if(tri[root][st[in]-'0']==-1)
		{
			go=0;
			if(ind[root])
				flag=0;
			else
			{
				for(j=0;j<10;j++)
					tri[lst][j]=-1;

				ind[lst]=0;
				tri[root][st[in]-'0']=lst++;

				make(lst-1,in+1);
			}
		}
		else
		{
			if(ind[root])
				flag=0;
			else
				make(tri[root][st[in]-'0'],in+1);
		}
	}
	else if(flag)
	{
		if(go || ind[root])
			flag=0;
		else
			ind[root]=1;
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		lst=flag=1;

		for(i=0;i<10;i++)
			tri[0][i]=-1;
		
		ind[0]=0;

		for(i=0;i<n;i++)
		{
			scanf("%s",st);
			len=strlen(st);

			go=1;
			if(flag)
				make(0,0);
		}
		if(flag)
			printf("Case %ld: YES\n",cs++);
		else
			printf("Case %ld: NO\n",cs++);
	}
	return 0;
}