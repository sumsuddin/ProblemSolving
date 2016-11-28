#include<stdio.h>
#include<string.h>
long i,l,u,d,mid;
char st[100];
struct 
{
	char fo[15],eng[15];
} dir[100010];


void quicksort(int left, int right)
{
  int pos,l,r;
  l=left;
  r=right;
  pos=left;

	while(l<r)
	  {
		  while(l<r)
		  {
			  if(strcmp(dir[r].fo,dir[pos].fo)>0)
				  r--;
			  else
			  {
				dir[100005]=dir[r];
				dir[r]=dir[pos];
				dir[pos]=dir[100005];
				pos=r;
				break;
			  }
		  }		      
		  while(l<r)
		  {
			  if(strcmp(dir[l].fo,dir[pos].fo)<=0)
				  l++;
			  else
			  {
				dir[100005]=dir[l];
				dir[l]=dir[pos];
				dir[pos]=dir[100005];
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

long bsearch()
{
	l=0,u=i;
	d=1;
	while(u>=l)
	{
		mid=(u+l)/2;
		if(strcmp(dir[mid].fo,st)==0)
		{
			d=0;
			return mid;
		}
		else
			if(strcmp(dir[mid].fo,st)<0)
				l=mid+1;
			else
				u=mid-1;
	}
	if(d)
		return -1;
}

int main()
{
	i=0;
	while(gets(st) && st[0])
	{
		sscanf(st,"%s%s",dir[i].eng,dir[i].fo);
		i++;
	}
	quicksort(0,i);

	while(gets(st))
	{
		mid=bsearch();
		if(mid==-1)
			printf("eh\n");
		else
			printf("%s\n",dir[mid].eng);
	}
	return 0;
}