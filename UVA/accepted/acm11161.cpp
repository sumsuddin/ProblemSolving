#include<stdio.h>
#include<string.h>
#define swap(m,n)m^=n^=m^=n
	char st[1505][10000],sy[10000],su[10000];
void division(char a[])
{
	long i,ex;
	for(i=0,ex=0;a[i];i++)
	{
		ex=ex*10+(a[i]-48);
		a[i]=ex/ 2+'0';
		ex=ex%2;
	}
	i=ex=0;
	while(a[i]=='0')
		i++;
	for(ex=0;a[i];ex++,i++)
		a[ex]=a[i];
	a[ex]=0;
}
void sub(char a[],char b[])
{
	int i,j,la;
	j=strlen(a);
	la=j/2;

	for(i=0,j=j-1;i<la;i++,j--)
	{
		swap(a[i],a[j]);
	}
	j=strlen(b);
	la=j/2;

	for(i=0,j=j-1;i<la;i++,j--)
	{
		swap(b[i],b[j]);
	}

	for(i=0;b[i];i++)
	{
		if(a[i]<b[i])
		{
			a[i]+=10;
			a[i+1]--;
		}
		a[i]=a[i]-b[i]+48;
	}
	j=strlen(a);
	la=j/2;
	for(i=0,j=j-1;i<la;i++,j--)
	{
		swap(a[i],a[j]);
	}
}
void bigsum(char a[],char b[],char sum[])
{
	long int la,lb,i,j,d=0;

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
		sum[i]=a[i]+b[i]+d-48;
		if(sum[i]>57)
		{
			sum[i]-=10;
			d=1;
		}
		else
			d=0;
	}
	if(d)
	{
		sum[i]='1';
		sum[i+1]=0;
	}
	else
		sum[i]=0;

	la=strlen(sum);

	for(i=0,j=la-1;i<la/2;i++,j--)
		swap(sum[i],sum[j]);

}

int main()
{
	long int i,n,p=1;
	strcpy(su,"0");
	strcpy(st[0],"0");
	strcpy(sy,"1");

	for(i=2;i<1502;i++)
	{

		strcpy(st[i-1],sy);
		bigsum(sy,su,st[i]);
		strcpy(su,st[i-1]);
		strcpy(sy,st[i]);
	}

	while(scanf("%d",&n)==1)
	{
        if(n==0)
                break;
        else
            if(n==1)
            {
                    printf("Set %ld:\n0\n",p++);
                    continue;
            }
        printf("Set %ld:\n",p++);
        strcpy(su,"0");                    
		for(i=2;i<=n;i++)
		{
               strcpy(sy,st[i]);          
               bigsum(su,st[i],su);
               strcpy(st[i],sy); 
        }
		division(sy);

		sub(su,sy); 
		i=0;
		while(su[i]=='0')
        i++;

        for(i;su[i];i++)
        {      
               printf("%c",su[i]);
        } 
        printf("\n");            
	}
	return 0;
}
