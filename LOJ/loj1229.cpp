#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;
set<long>s;
set<long>::iterator it;
char st[300];
long gn[300],i,j,b,a,t,l,nim,cs=1;
bool ind[300],flag;
int main()
{
	gn[1]=gn[2]=gn[3]=1;
	for(i=4;i<201;i++)
	{
		for(j=0;j<201;j++)
			ind[j]=0;

		for(j=1;j<=(i/2+(i%2));j++)
		{
			a=j-3;
			b=i-j-2;

			if(a<0)
				a=0;
			else
				a=gn[a];
			if(b<0)
				b=0;
			else
				b=gn[b];
			ind[a^b]=1;
		}
		for(j=0;j<201;j++)
			if(ind[j]==0)
				break;
		gn[i]=j;
	}

	scanf("%ld",&t);

	while(t--)
	{
		scanf("%s",st);

		l=strlen(st);
		a=0;
		nim=0;
		flag=0;
		for(i=0;st[i];i++)
			if(st[i]=='.' && i+1<l && st[i+1]=='X'  && i+2 <l && st[i+2]=='X')
				s.insert(i),flag=1;
			else if(st[i]=='.' && i-1>=0 && st[i-1]=='X' && i+1<l && st[i+1]=='X')
				s.insert(i),flag=1;
			else if(st[i]=='.' && i-1>=0 && st[i-1]=='X' && i-2>=0 && st[i-2]=='X')
				s.insert(i),flag=1;
		if(flag==0)
		{
			for(i=0;i<l;i++)
				if(st[i]=='X')
				{
					i+=2;
					a-=2;
					if(a>0)
						nim^=gn[a];
					a=0;
				}
				else
					a++;
			nim^=gn[a];

			if(nim)
			{
				for(i=0;i<l;i++)
				{
					if((i-2>=0 && st[i-2]=='X') || (i-1>=0 && st[i-1]=='X') || (i+1<l && st[i+1]=='X') || (i+2<l && st[i+2]=='X') || st[i]=='X')
						continue;
					else
					{
						nim=0;
						a=0;
						for(j=0;j<l;j++)
							if(st[j]=='X' || j==i)
							{
								a-=2;
								j+=2;
								if(a>0)
									nim^=gn[a];
								a=0;
							}
							else
								a++;
						nim^=gn[a];
					}
					if(nim==0)
						s.insert(i);
				}
			}
		}
		printf("Case %ld:",cs++);
		if(s.size()==0)
			printf(" 0\n");
		else
		{
			for(it=s.begin();it!=s.end();it++)
				printf(" %ld",(*it)+1);
			printf("\n");
		}
		s.clear();
	}
	return 0;
}
