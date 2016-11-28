#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long t,i,j,l,tr;
bool flag;
char st[100],sy[100];   
int main()
{
 	scanf("%ld",&t);
 	while(t--)
 	{
		scanf("%s",st);		
        l=strlen(st);
        sort(st,st+l);
        
        for(i=0,j=l-1;i<l/2;i++,j--)
        swap(st[i],st[j]);
        
        strcpy(sy,st);
        tr=1;
        while(strcmp(st,sy) || tr)
        {
            flag=1;tr=0;
            
	        for(i=l-2;i>=0 && flag;i--)
	        {
			  for(j=l-1;j>i;j--)				  
	          {
			      while(st[j]==st[j-1])
			      j--;
				  if(st[j]>st[i])
		            {		              
					 	swap(st[i],st[j]);
					 	sort(st+i+1,st+l);
					 	flag=0;
					 	break;
			        }
			  }
			}
			if(flag)
			sort(st,st+l);
			printf("%s\n",st);
		}
		printf("\n");
    }
    return 0;
}
