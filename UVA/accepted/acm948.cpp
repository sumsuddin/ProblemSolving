#include<stdio.h>
#include<string.h>
#define swap(m,n)m^=n^=m^=n
long long  i,k,feb[50],a,t,bc;
char st[1000],sy[1000];
void bigsum(char a[],char b[])
{
	long long la,lb,i,j,d=0;

	la=strlen(a);
	lb=strlen(b);

	for(i=0,j=la-1;i<la/2;i++,j--)
		swap(a[i],a[j]);


	for(i=0,j=lb-1;i<lb/2;i++,j--)
		swap(b[i],b[j]);
	if(la<lb)
	{
		for(i=la;i<=lb;i++)
			a[i]='0';
		b[lb]='0';
		j=lb;

	}
	else
	{
		for(i=lb;i<=la;i++)
			b[i]='0';
		a[la]='0';
		j=la;
	}

	for(i=0;i<j;i++)
	{
		a[i]=a[i]+b[i]+d-48;
		if(a[i]>57)
		{
			a[i]-=10;
			d=1;
		}
		else
			d=0;
	}
	if(d)
	{
		a[i]='1';
		a[i+1]=0;
	}
	else
		a[i]=0;

	la=strlen(a);

	for(i=0,j=la-1;i<la/2;i++,j--)
		swap(a[i],a[j]);

}
int main()
{
	feb[0]=1;
	for(i=1;i<46;i++)
		feb[i]=feb[i-1]+feb[i-2];
	scanf("%lld",&t);
    while(t--)
	{
         scanf("%lld",&i); 
         bc=i;    
         k=45; 
         st[0]='0';
         st[1]=0;                  
         while(i)                   
         {
              sy[0]='1';
              sy[1]=0;                      
              for(k=k;k>0;k--)
              {
                    if(i>=feb[k])
                    {
                         i-=feb[k];
                         for(a=1;a<k;a++)
                         sy[a]='0';
                         sy[a]=0;
                         bigsum(st,sy);
                         k--;
						 break;
                    }
              }
         } 
         printf("%lld = %s (fib)\n",bc,st);
    }            
	return 0;
}
