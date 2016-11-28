#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;
map<string,long>mp;
long i,j,n,e,sourc,dist,t,k,d[120],cs=1,q,dd[120];
char sss[30],ssy[30];
struct
{
 	  long u,v,w;
}a[1020];
int main()
{
 	scanf("%ld",&t);
 	while(t--)
 	{
        scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
		 	scanf("%s",sss);
		 	if(strcmp(sss,"Calgary")==0)
		 	sourc=i;
		 	else if(strcmp(sss,"Fredericton")==0)
		 	dist=i;
		 	mp[sss]=i;
		}
	
		scanf("%ld",&e);
		for(i=0;i<e;i++)
		{
			 scanf("%s%s%ld",sss,ssy,&a[i].w);
			 a[i].u=mp[sss];
			 a[i].v=mp[ssy];
	    }
	
		scanf("%ld",&q);
		printf("Scenario #%ld\n",cs++);
		while(q--)
		{
		 	scanf("%ld",&k);

			for(i=0;i<n;i++)
				d[i]=1000000000;

			d[sourc]=0;
			for(i=0;i<=k && i<n;i++)
			{
				for(j=0;j<n;j++)
					dd[j]=d[j];
				for(j=0;j<e;j++)
				{
					if(dd[a[j].v]>d[a[j].u]+a[j].w)
						dd[a[j].v]=d[a[j].u]+a[j].w;
				}
				for(j=0;j<n;j++)
					d[j]=dd[j];
			}

		 	if(d[dist]<1000000000)
		 		printf("Total cost of flight(s) is $%ld\n",d[dist]);
		 	else
		 		printf("No satisfactory flights\n");
        }
        if(t)
        printf("\n");
	}
    return 0;
 }
