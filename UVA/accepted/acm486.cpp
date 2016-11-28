#include<stdio.h>
#include<string.h>
long i,a,p,la,m,t,h;
char st[500],key[100];
int main()
{
	while(gets(st))
	{
		la=strlen(st);
		p=a=t=h=m=0;

		for(i=0;i<=la;i++)
		{
			if(st[i]==' ' || st[i]==0)
			{
				key[p]=0;
				p=0;

				if(!strcmp(key,"hundred"))
				{
					h=a*100;
					a=0;
				}
				else if(!strcmp(key,"thousand"))
				{
					t=(h+a)*1000;
					h=a=0;
				}
				else if(!strcmp(key,"million"))
				{
					m=(h+a)*1000000;
					h=a=0;
				}
				else if(!strcmp(key,"one"))
					a+=1;
				else if(!strcmp(key,"two"))
					a+=2;
				else if(!strcmp(key,"three"))
					a+=3;
				else if(!strcmp(key,"four"))
					a+=4;
				else if(!strcmp(key,"five"))
					a+=5;
				else if(!strcmp(key,"six"))
					a+=6;
				else if(!strcmp(key,"seven"))
					a+=7;
				else if(!strcmp(key,"eight"))
					a+=8;
				else if(!strcmp(key,"nine"))
					a+=9;
				else if(!strcmp(key,"ten"))
					a+=10;
				else if(!strcmp(key,"eleven"))
					a+=11;
				else if(!strcmp(key,"twelve"))
					a+=12;
				else if(!strcmp(key,"thirteen"))
					a+=13;
				else if(!strcmp(key,"fourteen"))
					a+=14;
				else if(!strcmp(key,"fifteen"))
					a+=15;
				else if(!strcmp(key,"sixteen"))
					a+=16;
				else if(!strcmp(key,"seventeen"))
					a+=17;
				else if(!strcmp(key,"eighteen"))
					a+=18;
				else if(!strcmp(key,"nineteen"))
					a+=19;
				else if(!strcmp(key,"twenty"))
					a+=20;
				else if(!strcmp(key,"thirty"))
					a+=30;
				else if(!strcmp(key,"forty"))
					a+=40;
				else if(!strcmp(key,"fifty"))
					a+=50;
				else if(!strcmp(key,"sixty"))
					a+=60;
				else if(!strcmp(key,"seventy"))
					a+=70;
				else if(!strcmp(key,"eighty"))
					a+=80;
				else if(!strcmp(key,"ninety"))
					a+=90;
				else if(!strcmp(key,"negative"))
					printf("-");
			}
			else
				key[p++]=st[i];
		}
		m=m+t+h+a;
		printf("%ld\n",m);
	}
	return 0;
}
