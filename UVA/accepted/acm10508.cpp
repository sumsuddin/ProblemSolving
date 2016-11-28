#include<stdio.h>
#include<string.h>
#define swap(m,n) m^=n^=m^=n

long i,j,a[2500],n,m;
char st[2500][2500],sy[2500];

void quicksort(long numbers[], long left, long right)
{
  long pit,pos,l,r;
  pit = numbers[left];
  l=left;
  r=right;
  pos=left;

	while(l<r)
	  {
		  while(l<r)
		  {
			  if(numbers[r]>numbers[pos])
				  r--;
			  else
			  {
				swap(numbers[r],numbers[pos]);
				strcpy(sy,st[r]);
				strcpy(st[r],st[pos]);
				strcpy(st[pos],sy);

				pos=r;
				break;
			  }
		  }		      
		  while(l<r)
		  {
			  if(numbers[l]<=numbers[pos])
				  l++;
			  else
			  {
				swap(numbers[l],numbers[pos]);
				strcpy(sy,st[l]);
				strcpy(st[l],st[pos]);
				strcpy(st[pos],sy);
				pos=l;
				break;
			  }
		  }	
	  
	  }
	if(left<pos-1)
	  quicksort(numbers,left,pos-1);
	if(pos+1<right)
		quicksort(numbers,pos+1,right);
}

int main()
{
	while(~scanf("%ld%ld",&n,&m))
	{
		getchar();

		for(i=0;i<n;i++)
			gets(st[i]);

		for(i=0;i<n;i++)
		{
			a[i]=0;
			for(j=0;j<m;j++)
			{
				if(st[0][j]!=st[i][j])
					a[i]++;
			}
		}
		quicksort(a,0,n-1);

		for(i=0;i<n;i++)
			puts(st[i]);
	}
	return 0;
}