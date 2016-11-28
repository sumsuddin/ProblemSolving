#include<stdio.h>
#include<string.h>
long i,y,m,d,t,p=1,mst[30],n;
char st[100],ms[30][30];
int main()
{
	strcpy(ms[1],"January");
	strcpy(ms[2],"February");
	strcpy(ms[3],"March");
	strcpy(ms[4],"April");
	strcpy(ms[5],"May");
	strcpy(ms[6],"June");
	strcpy(ms[7],"July");
	strcpy(ms[8],"August");
	strcpy(ms[9],"September");
	strcpy(ms[10],"October");
	strcpy(ms[11],"November");
	strcpy(ms[12],"December");

	mst[1]=31;mst[3]=31;mst[4]=30;mst[5]=31;mst[6]=30;mst[7]=31;mst[8]=31;mst[9]=30;mst[10]=31;mst[11]=30;mst[12]=31;
	scanf("%ld",&n);
	while(n--)
	{
		scanf("%ld",&y);
		getchar();
		for(i=0;;i++)
		{
			scanf("%c",&st[i]);
			if(st[i]=='-')
			{
				st[i]=0;
				break;
			}
		}
		
		scanf("%ld%ld",&d,&t);

		for(i=1;i<13;i++)
			if(strcmp(st,ms[i])==0)
			{
				m=i;
				break;
			}
			if((y%4==0 && y%100!=0) || y%400==0)
				mst[2]=29;
			else
				mst[2]=28;

			for(i=0;i<t;i++)
			{
				d++;
				if(d>mst[m])
				{
					m++;
					d=1;
					if(m>12)
					{
						m=1;
						y++;
						if((y%4==0 && y%100!=0) || y%400==0)
							mst[2]=29;
						else
							mst[2]=28;
					}
				}
			}
		
		printf("Case %ld: %ld-%s-%02ld\n",p++,y,ms[m],d);
	}
	return 0;
}