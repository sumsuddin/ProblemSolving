#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[10050];

long t,n,m,i,a,b,cs=1,sum,mx[10050],mn[10050],vfn[10050],mxprm,ans,pp,ch,ram;
unsigned long long way;
bool got[10050],vs[10050];

void rec(long p,long par)
{
	long i,th,chld=0;
	vfn[p]=vfn[par]+1;
	chld=0;
	vs[p]=0;
	if(par==pp)
		mn[p]=0;
	else
		mn[p]=vfn[par];

	mx[p]=vfn[p];
	
	for(i=0;i<vc[p].size();i++)
	{
		th=vc[p][i];
		if(vs[vc[p][i]])
		{
			//child.
			chld++;

			if(p==pp)
				ch=th;

			rec(th,p);

			mx[p]=mx[th];
			if(mn[p]>mn[th])
				mn[p]=mn[th];
			else if(vfn[p]==mn[th])
			{
				if(got[th])
				{
					if(p==pp)
					{
						if(ram==-1)
							ram=(mx[p]-vfn[p]);
						else
							sum++,way*=(unsigned long long)(mx[p]-vfn[p]);
					}
					else
						sum++,way*=(unsigned long long)(mx[p]-vfn[p]);
				}


				got[p]=0;
			}
			if(th!=par && got[th]==0)
				got[p]=0;
		}
		else
		{
			//back edge.
			if(mn[p]>vfn[th])
			{
				mn[p]=vfn[th];
				if(th==pp && mxprm<vfn[p])
					mxprm=vfn[p];
			}
		}
	}

	if(p==pp && chld==1)
	{
		if(got[ch]==0)
			sum++,way*=(unsigned long long)mxprm;
		else
		{
			sum+=2;
			mxprm=ram;
			ram++;
			if(ram%2==0)
				ram/=2;
			else
				mxprm/=2;
				
			way=(unsigned long long)(ram*mxprm);
		}
	}
	else if(p==pp)
		if(ram!=-1)
			sum++,way*=(unsigned long long) ram;

	if(got[p]==0)
		mx[p]=p;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<n;i++)
			got[i]=vs[i]=1,vfn[i]=0;

		vfn[0]=-1;

		while(m--)
		{
			scanf("%ld%ld",&a,&b);

			vc[a].push_back(b);
			vc[b].push_back(a);
		}

		way=1;
		ans=0;

		for(i=0;i<n;i++)
		{
			if(vs[i])
			{
				mxprm=1;
				sum=0;
				ram=-1;

				pp=i;
				vfn[pp]=-1;
				rec(pp,pp);
				if(sum==0)
					ans++;
				else
					ans+=sum;
			}
        }
		printf("Case %ld: %ld %llu\n",cs++,ans,way);

		for(i=0;i<n;i++)
			vc[i].clear();
	}
	return 0;
}
