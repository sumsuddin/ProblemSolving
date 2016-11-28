#include <cstdio>
using namespace std;

typedef long long  i64;


#define SIZE 100010

i64 edg[SIZE];

int main() 
{
	i64 T, t, N, M, i;
	for(i = 1; i < SIZE; i++) 
       edg[i] = i * (i-1) / 2;
	scanf("%lld", &T);
	for(t = 1; t <= T; t++)
    {
		scanf("%lld %lld", &N, &M);
		for(i = 1; i <= N; i++)
        {
			if((M-edg[i]) <= N-i) break;
		}
		printf("%lld\n", N-i);
	}
	return 0;
}
