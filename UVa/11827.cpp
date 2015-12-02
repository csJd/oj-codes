#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 105;

ll gcd(ll m, ll n)
{
    return n ? gcd(n, m % n) : m;
}

int main()
{
    int T, n;
    ll a[N], t;
    char c;
    scanf("%d", &T);
    while(T--)
    {
        n = 0;
        while(scanf(" %lld%c", &a[n++], &c), c != '\n');
        ll ans = 1;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < i; ++j)
                ans = max(ans, gcd(a[i], a[j]));

        printf("%lld\n", ans);
    }
    return 0;
}
