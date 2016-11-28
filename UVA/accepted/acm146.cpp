#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char st[100];
long i,j,l,flag,tr,k;
int main()
{
 	while(gets(st) && strcmp(st,"#"))
 	{
	 			   l=strlen(st);
	 			   flag=1;
        for(i=l-2;i>=0 && flag;i--)
        {
		  for(j=l-1;j>i;j--)				  
          {
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
		   printf("No Successor\n");
        else
           printf("%s\n",st);
    }
    return 0;
}
