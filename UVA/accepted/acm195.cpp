#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<ctype.h>
using namespace std;
long sum,n,t,i,j,l,tr,ii,jj;
bool flag;
char st[100],sy[100],stx[100];
void srt(long ins,long fn)
{
 	 for(ii=ins;ii<fn;ii++)
 	 for(jj=ii+1;jj<fn;jj++)
 	 if(stx[ii]>stx[jj] || (stx[ii]==stx[jj] && st[ii]>st[jj]))
 	 {
	  				   swap(stx[ii],stx[jj]);
	  				   swap(st[ii],st[jj]);
     }
}     
int main()
{
 	scanf("%ld",&t);
 	while(t--)
 	{
		scanf("%s",st);
		strcpy(stx,st);
		
		for(i=0;st[i];i++)
			if(st[i]>96)
			stx[i]=st[i]-32;
			else
			stx[i]=st[i];
			stx[i]=0;
		
        l=strlen(st);
        srt(0,l);
        
        for(i=0,j=l-1;i<l/2;i++,j--)
        {swap(st[i],st[j]);swap(stx[i],stx[j]);}
        
        n=1;
        for(i=2;i<=l;i++)
        n*=i;
        strcpy(sy,st);
        tr=1;
        while(strcmp(st,sy) || tr)
        {
            flag=1;tr=0;
            
	        for(i=l-2;i>=0 && flag;i--)
	        {
			  for(j=l-1;j>i;j--)				  
	          {
			      while(stx[j]==stx[j-1] && st[j]==st[j-1])
			      j--;
				  if(stx[j]>stx[i] || (stx[j]==stx[i] && st[j]>st[i]))
		            {		              
					 	swap(st[i],st[j]);
					 	swap(stx[i],stx[j]);
					 	srt(i+1,l);
					 	flag=0;
					 	break;
			        }
			  }
			}
			if(flag)
			srt(0,l);
			printf("%s\n",st);
		}
    }
    return 0;
}
