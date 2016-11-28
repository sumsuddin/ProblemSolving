#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int tree[100050][53],i,lst,ind,cs=1,l,t,n;
long long ans,now,cnt[100050];
char st[11000],str[11000];

void ins(int root ,int ps)
{
	if(st[ps]>='A' && st[ps]<='Z')
		ind=st[ps]-'A';
	else
		ind=st[ps]-'a'+26;

	if(tree[root][ind]==-1)
	{
		tree[root][ind]=lst;
		for(int i=0;i<53;i++)
			tree[lst][i]=-1;
		cnt[lst]=0;
		lst++;
	}
	if(ps+1==l)
		cnt[tree[root][ind]]++;
	else
		ins(tree[root][ind],ps+1);
}

void chk(int root ,int ps)
{
	if(ps >l)
		return;

	if(st[ps]>='A' && st[ps]<='Z')
		ind=st[ps]-'A';
	else
		ind=st[ps]-'a'+26;

	if(tree[root][ind]==-1)
	{
		now=0;
		return;
	}
	if(ps+1==l)
	{
		now=cnt[tree[root][ind]];
		return;
	}
	else
		chk(tree[root][ind],ps+1);
}

void modify(int l)
{
	if(l<=2)
		return;

	char c;
	c=st[1];
	st[1]=st[l-1];
	st[l-1]=c;

	sort(st+2,st+l);
}

int main()
{
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&n);
		lst =1;

		for(i=0;i<53;i++)
			tree[0][i]=-1;

		for(i=0;i<n;i++)
		{
			scanf("%s",st);

			l=strlen(st);
			modify(l);
			
			ins(0,0);
		}
		scanf("%d",&n);
		getchar();

		printf("Case %d:\n",cs++);
		while(n--)
		{
			ans=1LL;
			gets(str);
			i=0;
			while(i<strlen(str))
			{
				l=0;
				for(;i<=strlen(str);i++)
					if(str[i]==' ' || str[i]==0)
					{
						st[l++]=0;
						i++;
						break;
					}
					else
						st[l++]=str[i];

				l=strlen(st);
				modify(l);
				now=1;
				chk(0,0);
				ans*=now;
			}
			printf("%lld\n",ans);
		}	
	}
	return 0;
}
