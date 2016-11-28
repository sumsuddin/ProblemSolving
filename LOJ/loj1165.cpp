#include<stdio.h>
#include<queue>
using namespace std;
queue<int>que[10];
long lst,t,cs=1,path,i,j;
int tri[80050][9],x[15],y[15],st[15],p[15];
bool prm[40],go,flag,found,ind[80050];
void make(long root,long in)
{
    if(flag==0)
        return;
    if(in<8 && flag)
    {
        if(tri[root][st[in]]==-1)
        {
            go=0;
            if(ind[root])
                flag=0;
            else
            {
                for(j=1; j<9; j++)
                    tri[lst][j]=-1;

                ind[lst]=0;
                tri[root][st[in]]=lst++;

                make(lst-1,in+1);
            }
        }
        else
        {
            if(ind[root])
                flag=0;
            else
                make(tri[root][st[in]],in+1);
        }
    }
    else if(flag)
    {
        if(go || ind[root])
            flag=0;
        else
            ind[root]=1;
    }
}

bool check()
{
	long i;
	for(i=0;i<7;i++)
	{
		if(st[i]!=i+1)
			return 0;
	}
	return 1;
}

void pp(long i,long j)
{
	long jj,ii;
    jj=0;
    for(ii=0; ii<8; ii++)
    {
        if(ii==j);
        else if(ii==i)
        {
            y[jj+1]=x[jj]=p[j];
            y[jj]=x[jj+1]=p[ii];
            jj+=2;
        }
        else
            y[jj]=x[jj++]=p[ii];
    }
	for(i=0;i<8;i++)
		st[i]=(x[i]<0)?-x[i]:x[i];

    if(check())
        printf("Case %ld: %ld\n",cs++,path+1),found=0;

	if(found==0)
		return;

    flag=1;
	go=1;
    make(0,0);
    if(flag)
	{
		for(i=0; i<8; i++)
            que[i].push(x[i]);
		que[8].push(path+1);
	}


	for(i=0;i<8;i++)
		st[i]=(y[i]<0)?-y[i]:y[i];

    if(check())
        printf("Case %ld: %ld\n",cs++,path+1),found=0;

	if(found==0)
		return;

    flag=1;
	go=1;
    make(0,0);
    if(flag)
	{
		for(i=0; i<8; i++)
            que[i].push(y[i]);
		que[8].push(path+1);
	}

}


void bfs()
{
	long d,i,j;
    while(!que[0].empty() && found)
    {
        for(i=0; i<8; i++)
            p[i]=que[i].front(),que[i].pop();
        path=que[8].front();
        que[8].pop();

        for(i=0; i<8 && found; i++)
        {
            for(j=i+1; j<8 && found; j++)
            {
                if(p[i]*p[j]<0 && found)
                {
                    d=p[i]-p[j];
                    if(d<0)
                        d*=-1;
                    if(prm[d]==0)
                    {
						pp(i,j);
						pp(j,i);
                    }
                }
            }
        }
    }
}

int main()
{
    prm[1]=1;
    prm[0]=1;

    for(i=4; i<25; i+=2)
        prm[i]=1;

    for(i=3; i<25; i++)
        for(j=3*i; j<25; j+=2*i)
            prm[j]=1;

    scanf("%ld",&t);

    while(t--)
    {
        lst=found=1;
        ind[0]=0;
        for(i=1; i<9; i++)
            tri[0][i]=-1;

        for(i=0; i<8; i++)
            scanf("%d",&x[i]);

		for(i=0;i<8;i++)
			st[i]=(x[i]<0)?-x[i]:x[i];

        if(check())
            printf("Case %ld: 0\n",cs++),found=0;
        else
        {
            flag=1;
			go=1;
            make(0,0);
            if(flag)
			{
				for(i=0; i<8; i++)
                    que[i].push(x[i]);
				que[8].push(0);
			}
            bfs();
        }
		if(found)
			printf("Case %ld: -1\n",cs++);
		while(!que[0].empty())
			for(i=0;i<9;i++)
				que[i].pop();
    }
    return 0;
}
