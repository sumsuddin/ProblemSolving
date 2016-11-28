#include<stdio.h>
#include<string.h>
long i,n,p,flag,wmn[2010];
char str[2010][80],st[80];
void quicksort(long left, long right)
{
  long pos,l,r;
  l=left;
  r=right;
  pos=left;

	while(l<r)
	  {
		  while(l<r)
		  {
			  if(strcmp(str[r],str[pos])>0)
				  r--;
			  else
			  {
				strcpy(st,str[r]);
				strcpy(str[r],str[pos]);
				strcpy(str[pos],st);
				
				n=wmn[r];
				wmn[r]=wmn[pos];
				wmn[pos]=n;
				
				pos=r;
				break;
			  }
		  }		      
		  while(l<r)
		  {
			  if(strcmp(str[l],str[pos])<=0)
				  l++;
			  else
			  {
				strcpy(st,str[l]);
				strcpy(str[l],str[pos]);
				strcpy(str[pos],st);

				n=wmn[l];
				wmn[l]=wmn[pos];
				wmn[pos]=n;

				pos=l;
				break;
			  }
		  }	
	  
	  }
	if(left<pos-1)
	  quicksort(left,pos-1);
	if(pos+1<right)
		quicksort(pos+1,right);
}

int main()
{
	scanf("%ld",&n);
	getchar();
	p=0;

	while(n--)
	{
		gets(st);
		sscanf(st,"%s",st);
		flag=1;

		for(i=0;i<p;i++)
			if(strcmp(st,str[i])==0)
			{
				wmn[i]++;
				flag=0;
				break;
			}
		if(flag)
		{
			wmn[p]=1;
			strcpy(str[p++],st);
		}
	}
	quicksort(0,p-1);
	for(i=0;i<p;i++)
		printf("%s %ld\n",str[i],wmn[i]);
	return 0;
}