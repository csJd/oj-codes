#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll quickPow(ll a, ll k)
{
    ll ret = 1;
    while(k)
    {
        if(k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        printf("%I64d\n", (quickPow(3, n * 3) - quickPow(7, n) + MOD) % MOD);
    }
    return 0;
}
//Last modified :  2015-10-07 00:58 CST

