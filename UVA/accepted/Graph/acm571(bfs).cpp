#include<stdio.h>
#include<stack>
#include<queue>
#include<map>
#include<string>
using namespace std;
queue<long>que;
stack<long >stk;
map<string,bool>mp;
long i,q,p,a,b,c;
string ss;
char st[50],sr[50];

struct ss
{
	long l,h;
}
par[1050][1050];

long path[1050][1050];

void bfs()
{
	sprintf(st,"%ld %ld",0,0);

	mp[st]=1;

	que.push(0);
	que.push(0);
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		q=que.front();
		que.pop();

		sprintf(st,"%ld %ld",p,b);
		if(mp[st]==0)
		{
			que.push(p);
			que.push(b);

			mp[st]=1;

			par[p][b].l=p;
			par[p][b].h=q;

			path[p][b]=1;////fill b;
		}

		sprintf(st,"%ld %ld",a,q);
		if(mp[st]==0)
		{
			que.push(a);
			que.push(q);

			mp[st]=1;

			par[a][q].l=p;
			par[a][q].h=q;

			path[a][q]=2;/////fill a;
		}

		sprintf(st,"%ld %ld",p,0);
		if(mp[st]==0)
		{
			que.push(p);
			que.push(0);

			mp[st]=1;
			par[p][0].l=p;
			par[p][0].h=q;
			path[p][0]=3;///empty b;
		}

		sprintf(st,"%ld %ld",0,q);
		if(mp[st]==0)
		{
			que.push(0);
			que.push(q);

			mp[st]=1;
			par[0][q].l=p;
			par[0][q].h=q;
			path[0][q]=4;////empty a;
		}

		if(a-p<q)///pour b to a;
		{
			sprintf(st,"%ld %ld",a,q-a+p);
			if(mp[st]==0)
			{
				que.push(a);
				que.push(q-a+p);

				mp[st]=1;
				par[a][q-a+p].l=p;
				par[a][q-a+p].h=q;
				path[a][q-a+p]=5;
			}
		}
		else 
		{
			sprintf(st,"%ld %ld",p+q,0);
			if(mp[st]==0)
			{
				que.push(p+q);
				que.push(0);

				mp[st]=1;
				par[p+q][0].l=p;
				par[p+q][0].h=q;
				path[p+q][0]=5;
			}
		}

		if(p>b-q)///pour a to b;
		{
			sprintf(st,"%ld %ld",p-b+q,b);
			if(mp[st]==0)
			{
				que.push(p-b+q);
				que.push(b);

				mp[st]=1;
				par[p-b+q][b].l=p;
				par[p-b+q][b].h=q;
				path[p-b+q][b]=6;
			}
		}
		else 
		{
			sprintf(st,"%ld %ld",0,p+q);
			if(mp[st]==0)
			{
				que.push(0);
				que.push(p+q);

				mp[st]=1;
				par[0][p+q].l=p;
				par[0][p+q].h=q;
				path[0][p+q]=6;
			}
		}


		if(q==c)
		{
			while(!que.empty())
				que.pop();

//			ss=sr;
			stk.push(path[p][q]);

			while(1)
			{
				a=par[p][q].l;
				b=par[p][q].h;
				p=a;
				q=b;
				stk.push(path[p][q]);
				if(par[a][b].l==0 && par[a][b].h==0)
					break;
			}
		}
	}
	while(!stk.empty())
	{
		p=stk.top();
		stk.pop();
		if(p==1)
			printf("fill B\n");
		else if(p==2)
			printf("fill A\n");
		else if(p==3)
			printf("empty B\n");
		else if(p==4)
			printf("empty A\n");
		else if(p==5)
			printf("pour B A\n");
		else if(p==6)
			printf("pour A B\n");
	}
	printf("success\n");
}

int main()
{
	while(~scanf("%ld%ld%ld",&a,&b,&c))
	{
		mp.clear();
		for(i=0;i<1001;i++)
			for(p=0;p<1001;p++)
				par[i][p].l=par[i][p].h=path[i][p]=0;

		bfs();
	}
	return 0;
}