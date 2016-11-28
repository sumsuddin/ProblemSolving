/*#include<stdio.h>
long i,j,k,st[100],cnt,flag,ans,jj;
int main()
{
	for(i=1;i<15;i++)
	{
		for(j=2;;j++)
		{
			for(k=1;k<=i*2;k++)
				st[k]=k;

			k=1;cnt=ans=0;
			flag=0;
			jj=j%(i*2);
			if(jj==0)
				jj=i*2;
			for(;;)
			{
				if(st[k])
					cnt++;

				if(cnt>=jj)
				{
					st[k]=0;
					if(k<=i)
					{
						flag=-1;
						break;
					}
					ans++;
					cnt=0;
					jj=j%(i*2-ans);
					if(jj==0)
						jj=i*2-ans;
				}
				if(k>=i*2)
					k=0;
				if(ans>=i)
				{
					flag=1;
					printf("st[%ld]= %ld;\n",i,j);
					break;
				}
				k++;
			}
			if(flag==1)
				break;
		}
	}
	return 0;
}
*/
#include<stdio.h>
long st[50],n;
int main()
{
st[1]= 2;
st[2]= 7;
st[3]= 5;
st[4]= 30;
st[5]= 169;
st[6]= 441;
st[7]= 1872;
st[8]= 7632;
st[9]= 1740;
st[10]= 93313;
st[11]= 459901;
st[12]= 1358657;
st[13]= 2504881;
st[14]= 13482720;
while(scanf("%ld",&n),n)
{
	printf("%ld\n",st[n]);
}
return 0;
}