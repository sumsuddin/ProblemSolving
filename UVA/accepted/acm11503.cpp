#include<stdio.h>
#include<string>
#include<map>
using namespace std;
map<string,long>mp;
long i,t,n,rank[1000010],a[1000010],inc,x,y,p1,p2;
char st[50],sy[50];
void init()
{
	for(i=0;i<1000001;i++)
	{
		a[i]=i;
		rank[i]=1;
	}
}

long parent(long p)
{
	while(a[p]!=p)
		p=a[p];
	return p;
}

int main()
{
 	scanf("%ld",&t);
 	
 	while(t--)
 	{	  
	 	scanf("%ld",&n);
	 	inc=1;
        init();
		while(n--)
		{
            scanf("%s%s",st,sy);
            if(mp[st]==0)
            {
			 			 mp[st]=inc;
			 			 x=inc++;
	        }
	        else
	        x=mp[st];
            if(mp[sy]==0)
            {
			 			 mp[sy]=inc;
			 			 y=inc++;
	        }
	        else
	        y=mp[sy];
			
			p1=parent(x);
			p2=parent(y);
			if(p1!=p2)
			{
				if(rank[p1]>rank[p2])
				{
					a[p2]=p1;
					rank[p1]+=rank[p2];
					printf("%ld\n",rank[p1]);
				}
				else
				{
					a[p1]=p2;
					rank[p2]+=rank[p1];
					printf("%ld\n",rank[p2]);
				}			
			}
			else
			printf("%ld\n",rank[p1]);					        
        }
		mp.clear();	  
    }
    return 0;
}
