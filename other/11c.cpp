#include <cstdio>
using namespace std;
typedef long long  ll;
const ll MOD = 200907;

ll modPow(ll a, ll n)
{
    ll ret = 1;
    while(n)
    {
        if(n & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return ret;
}

int main()
{
    int n, T;
    ll a, b, c, k, ans;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &k);
        if(b - a == c - b)
            ans = (a % MOD + (k - 1) % MOD * ((b - a) % MOD)) % MOD;
        else
            ans = a % MOD * modPow(b / a % MOD, k - 1) % MOD;
        printf("%I64d\n", ans);
    }

    return 0;
}
//Last modified :  2015-08-13 12:24 CST

