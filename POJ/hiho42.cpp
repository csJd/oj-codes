#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 8;
const LL MOD = 12357;

void matMul(LL a[][N], LL b[][N], LL c[][N])
{
    LL ret[N][N] = {0};
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
    for(int i = 0; i < N; ++i)
        memcpy(c[i], ret[i], sizeof(c[i]));
}

void matPow(LL a[][N], int n)
{
    LL ret[N][N] = {0};
    for(int i = 0; i < N; ++i) ret[i][i] = 1;
    while(n)
    {
        if(n & 1) matMul(ret, a, ret);
        matMul(a, a, a);
        n >>= 1;
    }
    for(int i = 0; i < N; ++i)
        memcpy(a[i], ret[i], sizeof(a[i]));
}

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        LL a[N][N] = {0};
        for(int i = 0; i < N; ++i) a[i][7 - i] = 1;
        a[3][7] = a[6][7] = a[7][3] = a[7][6] = 1;
        matPow(a, n);
        printf("%lld\n", a[7][7] % MOD);
    }
    return 0;
}
//Last modified :   2015-05-27 19:42

