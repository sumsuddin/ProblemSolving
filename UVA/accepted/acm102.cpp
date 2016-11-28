#include<stdio.h>
#include<string.h>
long st[30],sy[30],i,min;
char ans[20][5];
int main()
{
	strcpy(ans[0],"BCG");
	strcpy(ans[1],"BGC");
	strcpy(ans[2],"CBG");
	strcpy(ans[3],"CGB");
	strcpy(ans[4],"GBC");
	strcpy(ans[5],"GCB");

	while(scanf("%ld%ld%ld%ld%ld%ld%ld%ld%ld",&st[0],&st[1],&st[2],&st[3],&st[4],&st[5],&st[6],&st[7],&st[8])==9)
	{
		sy[0]=st[3]+st[6]+st[2]+st[8]+st[1]+st[4];
		sy[1]=st[3]+st[6]+st[1]+st[7]+st[2]+st[5];
		sy[2]=st[5]+st[8]+st[0]+st[6]+st[1]+st[4];
		sy[3]=st[5]+st[8]+st[1]+st[7]+st[0]+st[3];
		sy[4]=st[4]+st[7]+st[0]+st[6]+st[2]+st[5];
		sy[5]=st[4]+st[7]+st[2]+st[8]+st[0]+st[3];

		min=sy[0];
		st[0]=0;
		for(i=0;i<6;i++)
		{
			if(sy[i]<min)
			{
				min=sy[i];
				st[0]=i;
			}
		}
		printf("%s %ld\n",ans[st[0]],min);
	}
	return 0;
}