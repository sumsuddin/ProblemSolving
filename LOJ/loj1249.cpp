#include<stdio.h>
#include<string.h>
char st[25],thf[25],frm[25],name[4][25];
long t,n,lst,a,b,c,ar[5],area,cs=1,i;
bool flag;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		lst=0;
		while(n--)
		{
			scanf("%s%ld%ld%ld",st,&a,&b,&c);

			area=a*b*c;

			flag=1;
			for(i=0;i<lst;i++)
				if(ar[i]==area)
				{
					flag=0;
					break;
				}

			if(flag)
				ar[lst]=area,strcpy(name[lst++],st);

		}
		if(lst==1)
			printf("Case %ld: no thief\n",cs++);
		else
		{
			printf("Case %ld: ",cs++);

			if(lst==2)
				ar[2]=ar[0],strcpy(name[2],name[0]);

			if(ar[0]>ar[1] && ar[0]>ar[2])
				strcpy(thf,name[0]);
			else if(ar[1]>ar[0] && ar[1]>ar[2])
				strcpy(thf,name[1]);
			else
				strcpy(thf,name[2]);

			if(ar[0]<ar[1] && ar[0]<ar[2])
				strcpy(frm,name[0]);
			else if(ar[1]<ar[0] && ar[1]<ar[2])
				strcpy(frm,name[1]);
			else
				strcpy(frm,name[2]);

			printf("%s took chocolate from %s\n",thf,frm);
		}
	}
	return 0;
}