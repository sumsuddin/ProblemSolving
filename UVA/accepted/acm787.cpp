#include<stdio.h>
#define swap(m,n)m^=n^=m^=n
long i,ad[120],n,cs=1,j,d,ll,jj,p,la,lb,ex,dx;

int a[5][10000],ma[10000],minus[5];

void comparer(int p,int a[],long i)
{
	if((minus[p]>0 && ll==i && minus[3]>0) || (minus[p]<0 && ll==i && minus[3]<0))
	{
		for(jj=0;jj<i;jj++)
		{
			if(ma[jj]<a[jj])
			{
				for(ll=0;ll<i;ll++)
					ma[ll]=a[ll];
				ll=i;
			}
			else
				if(ma[jj]>a[jj])
					break;
		}
	}
	else
		if((minus[p]>0 && i>ll && minus[3]>0) || (minus[p]<0 && ll>i && minus[3]<0))
		{
			for(ll=0;ll<i;ll++)
				ma[ll]=a[ll];
			ll=i;
		}
		else
			if(minus[p]>0 && minus[3]<0)
			{
				for(ll=0;ll<i;ll++)
					ma[ll]=a[ll];
				ll=i;
				minus[3]=1;
			}
}


long first_multi(int q,long i,long l)
{

		dx=l/2;
		for(d=0,jj=l-1;d<dx;d++,jj--)
			swap(a[q][d],a[q][jj]);
		p=0;
		for(jj=0;jj<l;jj++)
			a[q][jj]*=i;

		for(jj=0;jj<l;jj++)
		{
			if(a[q][jj]/10)
			{
				if(jj<l-1)
					a[q][jj+1]+=a[q][jj]/10;
				else
				{
					a[q][jj+1]=a[q][jj]/10;
					p++;
				}
			}
			a[q][jj]=a[q][jj]%10;
		}
		l+=p;
		if((p=a[q][l-1])>9)
		{
			l--;
			while(p)
			{
				a[q][l++]=p%10;
				p/=10;
			}
		}
		dx=l/2;
		for(i=0,jj=l-1;i<dx;i++,jj--)
			swap(a[q][i],a[q][jj]);

	return l;
}

int main()
{
	while(~scanf("%ld",&ad[n]))
	{
		if(ad[n]!=-999999)
		{
			n++;
			continue;
		}

		ma[0]=999999999;
		minus[3]=-1;
		ll=9;


		a[0][0]=1;
		la=1;minus[0]=1;
		a[1][0]=1;
		lb=1;minus[1]=1;

		for(i=0,j=n-1;i<n;i++,j--)
		{
			if(ad[i]<0)
			{
				ex=-ad[i];
				minus[0]*=-1;
			}
			else
			{
				ex=ad[i];
			}

			la=first_multi(0,ex,la);
			if(ex)
				comparer(0,a[0],la);
			else
			{
				a[0][0]=0;
				la=1;
				minus[0]=1;
				comparer(0,a[0],la);
				a[0][0]=1;
			}

			if(ad[j]<0)
			{
				ex=-ad[j];
				minus[1]*=-1;
			}
			else
			{
				ex=ad[j];
			}
			lb=first_multi(1,ex,lb);
			if(ex)
				comparer(1,a[1],lb);
			else
			{
				a[1][0]=0;
				minus[1]=1;
				lb=1;
				comparer(1,a[1],lb);
				a[1][0]=1;
			}
		}

		if(minus[3]<0)
			printf("-");
		for(i=0;i<ll;i++)
			printf("%d",ma[i]);
		printf("\n");
		n=0;
	}
	return 0;
}