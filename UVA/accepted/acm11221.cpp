#include<stdio.h>
#include<math.h>

long i,j,d,p=1,ans,n;
char st[10000];
bool flag;
int main()
{
	gets(st);
	sscanf(st,"%ld",&n);
	while(n--)
	{
		gets(st);
		ans=0;

		for(i=0;st[i];i++)
		{
			if(st[i]>96 && st[i]<123)
			{
				st[ans]=st[i];
				ans++;
			}
		}
		j=(long)sqrt(ans);
		if(j*j==ans || (j+1)*(j+1)==ans)
		{
			flag=1;
			d=ans-1;
			ans/=2;
			for(i=0;i<ans;i++,d--)
				if(st[i]!=st[d])
				{
					flag=0;
					break;
				}
		}
		else
			flag=0;

		if(flag)
			printf("Case #%ld:\n%ld\n",p++,j);
		else
			printf("Case #%ld:\nNo magic :(\n",p++);
	}
	return 0;
}