/*

Code

Code: (Toggle Highlighting) (Open in Compiler)

    //#pragma comment(linker, "/STACK:60000000")

    #include <iostream>
    #include <string>
    #include <map>
    #include <queue>
    #include <stack>
    #include <algorithm>
    #include <list>
    #include <set>
    #include <cmath>
    #include <cstring>

    #include <stdio.h>
    #include <string.h>
    #include <sstream>
    #include <stdlib.h>
    #include <vector>
    #include <iomanip>
    #include <ctime>
    #include <assert.h>

    using namespace std;

    //Type Definition
    typedef long long ll;
    typedef pair<int,int> pii;
    typedef vector<int> vi;
    typedef vector<vi>vvi;
    typedef vector<string> vs;
    typedef map<string,int> msi;
    typedef map<int,int>mii;

    #define ERR 1e-9
    #define PI 3.141592653589793

    #define REP(i,n) for (i=0;i<n;i++)
    #define FOR(i,p,k) for (i=p; i<k;i++)
    #define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)

    #define Sort(x) sort(x.begin(),x.end())
    #define Reverse(x) reverse(x.begin(),x.end())
    #define MP(a,b) make_pair(a,b)
    #define Clear(x,with) memset(x,with,sizeof(x))
    #define SZ(x) (int)x.size()
    #define pb push_back
    #define popcount(i) __builtin_popcount(i)
    #define gcd(a,b)    __gcd(a,b)
    #define lcm(a,b) ((a)*((b)/gcd(a,b)))
    #define two(X) (1<<(X))
    #define twoL(X) (((ll)(1))<<(X))
    #define setBit(mask,i) (mask|two(i))
    #define contain(S,X) (((S)&two(X))!=0)
    #define X first
    #define Y second
    #define CS c_str()
    #define EQ(a,b) (fabs(a-b)<ERR)
    #define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin());
    #define Find(x,y) ((int)x.find(y))

    //For debugging
    #define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
    #define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
    #define debug(args...) {dbg,args; cerr<<endl;}
    struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;

    //Important Functions
    template<class T> void setmax(T &a, T b) { if(a < b) a = b; }
    template<class T> void setmin(T &a, T b) { if(b < a) a = b; }
    template<class T> T Abs(T x) {return x > 0 ? x : -x;}
    template<class T> inline T sqr(T x){return x*x;}
    template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;} //For Positive Negative No.
    template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
    int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
    bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
    bool isUpper(char c){return c>='A' && c<='Z';}
    bool isLower(char c){return c>='a' && c<='z';}
    ll Pow(ll B,ll P){  ll R=1; while(P>0)  {if(P%2==1) R=(R*B);P/=2;B=(B*B);}return R;}
    int BigMod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;}
    void binprint(ll mask,ll n){ll i;string s="";do{s+=(mask%2+'0');mask/=2;}while(mask);Reverse(s);s=string(max(n-SZ(s),0LL),'0')+s;for(i=SZ(s)-n;i<SZ(s);i++) printf("%c",s[i]);printf("\n");}
    void ASCII_Chart(){int i,j,k;printf("ASCII Chart:(30-129)\n");FOR(i,30,50){REP(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}


    //int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year

    //int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
    //int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
    //int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
    //int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction

    //#include<conio.h> //for using getch();

    //struct edge{ int cost,node; edge(int _cost=0,int _node=0){cost=_cost;node=_node;}bool operator<(const edge &b)const {return cost>b.cost;}}; // Min Priority Queue
    //bool comp(edge a,edge b){ return a.cost < b.cost;} //Asc Sort by cost

    #define INF (1<<28)
    #define SIZE 110000

    double dp[SIZE];

    double rec(int N)
    {
        if(N==1) return 0.0;
        double &ret=dp[N];

        if(ret>-0.5) return ret;

        int cnt,val,x,y;

        ret=0;
        cnt=2;
        val=sqrt(N)+1;
        for(int i=2;i<val;i++)
        {
            if(N%i==0)
            {
                x=i;
                y=N/i;
                ret+=rec(N/x);
                cnt++;
                if(x==y) continue;
                cnt++;
                ret+=rec(N/y);
            }
        }
        ret=(ret+cnt)/(cnt-1.0);
        return ret;
    }

    int main()
    {
        //freopen("A.in","r",stdin);
        //freopen("A.out","w",stdout);

        int i,j,test,Case=1,N;

        scanf("%d",&test);
        Clear(dp,-1);
        while(test--)
        {
            scanf("%d",&N);
            printf("Case %d: %.10lf\n",Case++,rec(N));
        }

        return 0;
    }



*/
#include<stdio.h>
#include<vector>
using namespace std;
vector<long>v[100055];
long i,j,k,n,t,cs=1,l;
double x[100055],s;

int main()
{
    x[1]=1.0;
    for(i=1;i<=100000;i++)
    {
		 for(j=i;j<=100000;j+=i)
		 v[j].push_back(i);
		 if(i>1)
		 {
			 l=v[i].size();
			 s=0;
			 for(k=l-2;k>=0;k--)
			 {
				 s+=x[v[i][k]];
			 }
			 x[i]=(double)(s+(double)l-1.0)/((double)l-1.0);
		 }
    }
	x[1]=0;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&n);
        printf("Case %ld: %lf\n",cs++,x[n]);
    }
    return 0;
}
