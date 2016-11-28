#include<stdio.h>

bool bl[300];
double a,b,unit[300],u1,u2;
long n,i,p,cs=1;
char st[1000000],c;
int main()
{
	unit['M']=1000000;
	unit['k']=1000;
	unit['m']=.001;
	gets(st);
	sscanf(st,"%ld",&n);
	while(n--)
	{
		printf("Problem #%ld\n",cs++);
		bl['U']=bl['P']=bl['I']=1;
		gets(st);
		for(i=0;st[i];i++)
		{
			if(st[i]=='=')
			{
				bl[st[i-1]]=0;
				sscanf(st+i+1,"%lf%c",&a,&c);
				u1=unit[c];
				if(u1==0.0)
					u1=1;
				if(st[i-1]=='P')
					p=1;
				i++;
				break;
			}
		}
		for(;st[i];i++)
		{
			if(st[i]=='=')
			{
				bl[st[i-1]]=0;
				sscanf(st+i+1,"%lf%c",&b,&c);
				u2=unit[c];
				if(u2==0.0)
					u2=1;
				if(st[i-1]=='P')
					p=2;
				break;
			}
		}

		if(bl['P'])
		{
			u1*=u2;
			printf("P=%.2lfW\n\n",(a*b*u1));
		}
		else
			if(bl['U'])
			{
				if(p==1)
					printf("U=%.2lfV\n\n",((a*u1)/(b*u2)));
				else
					printf("U=%.2lfV\n\n",((b*u2)/(a*u1)));
			}
			else
			{
				if(p==1)
					printf("I=%.2lfA\n\n",((a*u1)/(b*u2)));
				else
					printf("I=%.2lfA\n\n",((b*u2)/(a*u1)));
			}
	}
	return 0;
}