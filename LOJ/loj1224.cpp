#include<stdio.h>
#include<string.h>

int ind,mx,tree[1000000][4],count[1000050],lst,t,n,l,cs=1;
char st[100];
void ins(int rt,int ps)
{
	if(ps>=l)
		return;

	if(st[ps]=='A')
		ind=0;
	else if(st[ps]=='C')
		ind=1;
	else if(st[ps]=='G')
		ind=2;
	else if(st[ps]=='T')
		ind=3;

	if(tree[rt][ind]==-1)
	{
		tree[rt][ind]=lst;

		tree[lst][0]=tree[lst][1]=tree[lst][2]=tree[lst][3]=-1;
		count[lst]=0;

		lst++;
	}
	count[tree[rt][ind]]++;
	if(count[tree[rt][ind]]*(ps+1)>mx)
		mx=count[tree[rt][ind]]*(ps+1);
	
	ins(tree[rt][ind],ps+1);
}

int main()
{
	scanf("%d",&t);

	while(t--)
	{
		mx=0;
		lst=1;
		scanf("%d",&n);

		tree[0][0]=tree[0][1]=tree[0][2]=tree[0][3]=-1;
		count[0]=0;

		while(n--)
		{
			scanf("%s",st);

			l=strlen(st);

			ins(0,0);
		}
		printf("Case %d: %d\n",cs++,mx);
	}
	return 0;
}
