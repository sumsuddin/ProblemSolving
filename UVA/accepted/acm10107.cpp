#include<stdio.h>
long n[10005],i,p,j,k,v;
int main()
{
	while(scanf("%ld",&n[i++])==1)
	{
		v=n[i-1];
		for(j=0;j<i;j++)
		{
			if(n[j]>=v)
			{
				for(k=i-1;k>j;k--)
					n[k]=n[k-1];
				n[j]=v;
				break;
			}
		}
		p=(long)(i/2);
		if(i%2)
			printf("%ld\n",n[p]);
		else
			printf("%ld\n",(long)((n[p]+n[p-1])/2));
	}
	return 0;

}
