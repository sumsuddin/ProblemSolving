#include<stdio.h>
#include<string.h>
#include<queue>
#include<map>
#include<string>
#include<stdlib.h>
using namespace std;
queue<long>que;
map<string,bool>mp;
long i,l,p,sum,s,j,k,a[110],cs=1,dg[15],ll,t,f;
char st[1050][20],cr[20],sy[110][110][20],str[20];
bool fg,flag;
int cmp(void const *a,void const *b)
{
	if(strlen((char *)a)==strlen((char *)b)) 
		return strcmp( (char *)a, (char *)b) ;
	else
		return strlen((char *)a)-strlen((char *)b);
}
void gen()
{
	l=10;
	for(i=0;i<=10;i++)
		que.push(i);
	sum=0;

	while(!que.empty())
	{
		p=que.front();
		que.pop();
		for(i=st[p][0]-47;i<10;i++)
		{
			cr[0]=i+48;
			cr[1]=0;

			strcat(cr,st[p]);
			
			if(strlen(cr)<=10 && mp[cr]==0)
			{
				mp[cr]=1;
				strcpy(st[l],cr);
				que.push(l++);
			}
		}
	}
}

void prs()
{
	for(k=0;k<101;k++)
	{
		t=0;
		mp.clear();
		for(ll=0;ll<=k>>1;ll++)
		{
			fg=1;
			for(f=0;f<10;f++)
				dg[f]=0;
			s=ll;
			while(s)
			{
				if(dg[s%10])
				{
					fg=0;
					break;
				}
				else
				{
					dg[s%10]=1;
				}
				s/=10;
			}
			s=k-ll;
			while(s)
			{
				if(dg[s%10])
				{
					fg=0;
					break;
				}
				else
				{
					dg[s%10]=1;
				}
				s/=10;
			}
			s=0;
			if(fg)
			{
				for(f=9;f>=0;f--)
					if(dg[f])
						str[s++]=f+'0';
				str[s]=0;
				if(mp[str]==0)
				{
					strcpy(sy[k][t++],str);
					mp[str]=1;
				}
			}
		}
	}
}
bool chk(long a)
{
	for(k=0;sy[a][k][0];k++)
	{
		flag=1;
		for(ll=0,s=0;sy[a][k][ll];ll++)
		{	
			fg=0;
			while(st[i][s] && (st[i][s]>=sy[a][k][ll]))
				if(st[i][s++]==sy[a][k][ll])
				{
					fg=1;
					break;
				}
			if(fg==0)
			{
				flag=0;
				break;
			}
		}
		if(flag)
			return 0;
	}
	return 1;
}

int main()
{
	strcpy(st[0],"0");
	strcpy(st[1],"1");
	strcpy(st[2],"2");
	strcpy(st[3],"3");
	strcpy(st[4],"4");
	strcpy(st[5],"5");
	strcpy(st[6],"6");
	strcpy(st[7],"7");
	strcpy(st[8],"8");
	strcpy(st[9],"9");
	gen();
	prs();
	strcpy(sy[0][0],"0");
	qsort(st,l,sizeof (st[0]),cmp);

	while(scanf("%ld",&l) ,l)
	{
		for(i=0;i<l;i++)
			scanf("%ld",&a[i]);

		
		for(i=0;i<1024;i++)
		{
			flag=1;
			for(j=0;j<l;j++)
			{
				if(chk(a[j]))
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				printf("Case %ld: %s\n",cs++,st[i]);
				break;
			}
		}
	}
	return 0;
}