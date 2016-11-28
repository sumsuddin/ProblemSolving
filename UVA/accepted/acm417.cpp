#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
using namespace std;
map<string,long>mp;
char st[10],sy[10];
long i,l,p,j;
int main()
{
 	st[0]='a';
 	st[1]=0;
 	strcpy(sy,st);
 	l=0;p=0;
 	for(i=1;i<83682;i++)
 	{
         mp[st]=i;
         st[l]++;
		 if(st[p]>'z')
		 {
		  	  while(p--)
		  	 { 
		  	     st[p]++; 
		  	     if(st[p]+1<st[p+1])
		  	     break;
		     }
			  for(j=p+1;st[j];j++)
			  st[j]=st[j-1]+1;
			  p=l;
	     }
         if(st[0]=='z'-l)
         {	mp[st]=++i;
		 	strcpy(st,sy);		  		  
			st[l+1]=sy[l]+1;
			st[l+2]=0;
			l++;
			p=l;
			strcpy(sy,st);
		 }		  			  
	 }
	 while(gets(sy))
	 printf("%ld\n",mp[sy]);
	 
	 return 0;
}
