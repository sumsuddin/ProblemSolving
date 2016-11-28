#include<stdio.h>
long cnt[1000000],tree[1000000],i,a[1000000],flag,t,n,eg,dir,lst,cs=1;
char c[10];
void build(long l,long h,long pos)
{
	if(l==h)
	{
		tree[pos]=a[l];
		if(l<n)
			cnt[pos]=1;
		else
			cnt[pos]=0;
	}
	else
	{
		build(l,(l+h)/2,pos*2);
		build((l+h)/2+1,h,pos*2+1);
		
		cnt[pos]=cnt[pos*2]+cnt[pos*2+1];
	}
}

void update(long l,long h,long pos,long lst)
{
	if(l==h && l==lst)
		tree[pos]=dir,cnt[pos]=1;
	else if(lst>((l+h)/2))
	{
		update((l+h)/2+1,h,pos*2+1,lst);
		cnt[pos]=cnt[pos*2]+cnt[pos*2+1];
	}
	else
	{
		update(l,(l+h)/2,pos*2,lst);
		cnt[pos]=cnt[pos*2]+cnt[pos*2+1];
	}
}

void range(long l, long h,long pos,long sum)
{
	if(sum+cnt[pos]<dir)
		return;
	else if(l==h)
		printf("%ld\n",tree[pos]),flag=1,cnt[pos]=0;
	else
	{
		if(sum+cnt[pos*2]<dir)
		{
			range((l+h)/2+1,h,pos*2+1,sum+cnt[pos*2]);
			cnt[pos]=cnt[pos*2]+cnt[pos*2+1];
		}
		else if(flag==0)
		{
			range(l,(l+h)/2,pos*2,sum);
			cnt[pos]=cnt[pos*2]+cnt[pos*2+1];
		}
	}
}
			
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&eg);

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		build(0,n+50050,1);

		lst=n;
		printf("Case %ld:\n",cs++);
		while(eg--)
		{
			scanf("%s%ld",c,&dir);

			if(c[0]=='a')
				update(0,n+50050,1,lst++);
			else
			{
				flag=0;
				range(0,n+50050,1,0);
				if(flag==0)
					printf("none\n");
			}
		}
	}
	return 0;
}