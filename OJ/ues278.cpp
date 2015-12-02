#include <bits/stdc++.h>
using namespace std;
const int N = 2, MOD = 1e4;

void matMul(int a[N][N], int b[N][N], int c[N][N])
{
	int ret[N][N] = {0};
	for(int i = 0; i<N; ++i)
		for(int j = 0; j < N; ++j)
			for(int k = 0; k < N; ++k)
				ret[i][j] += a[i][k] * b[k][j] % MOD;
	memcpy(c,ret,sizeof(ret));
}

void matPow(int a[N][N], int n)
{
	int ret[N][N] = {0};
	for(int i = 0; i < N; ++i) ret[i][i] = 1;
	while(n)
	{
		if(n&1) matMul(ret, a, ret);
		matMul(a,a,a);
		n >>= 1;
	}
	memcpy(a, ret, sizeof(ret));
}

int main()
{
	int n;
	while(scanf("%d", &n), n+1)
	{
		int a[N][N] = {0,1,1,1};
		matPow(a,n);
		printf("%d\n", a[1][0] % MOD);
	}
    return 0;
}
//Last modified :   2015-07-12 15:04
