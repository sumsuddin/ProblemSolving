#include<stdio.h>
#include<string.h>
long i,j,k,l,x,y,h[]={0,0,1,-1,-1,-1,1,1},v[]={1,-1,0,0,-1,1,1,-1},flag,n,go;
char st[150][150],sr[150];

int main()
{
	while(~scanf("%ld",&n))
	{
		
		for(i=0;i<n;i++)
			scanf("%s",st[i]);
		
		while(~scanf("%s",sr))
		{
			if(strcmp(sr,"0")==0)
				break;
			flag=1;
			for(i=0;i<n && flag;i++)
				for(j=0;j<n && flag;j++)
				{
					for(k=0;k<8 && flag;k++)
					{
						go=1;
						x=i;
						y=j;
						if(sr[0]==st[x][y])
						{
							for(l=1;sr[l];l++)
							{
								x+=h[k];
								y+=v[k];

								if(x>=n || x<0 || y>=n || y<0 || sr[l]!=st[x][y])
								{
									go=0;
									break;
								}
							}
							if(go)
							{
								flag=0;
								printf("%ld,%ld %ld,%ld\n",i+1,j+1,x+1,y+1);
								break;
							}
						}
					}				
				}
			if(flag)
				printf("Not found\n");
		}
	}
	return 0;
}