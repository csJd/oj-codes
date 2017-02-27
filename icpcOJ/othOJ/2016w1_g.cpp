#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;

//ax + by = d;
int exgcd(ll a, ll b, ll &x, ll &y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll r = exgcd(b, a % b, x, y), t;
    t = x, x = y, y = t - a / b * y;
    return r;
}

int main()
{
    ll x, y, m, n, l, a, b, c, d;
    while(~scanf("%I64d%I64d%I64d%I64d%I64d", &x, &y, &m, &n, &l))
    {
        a = n - m;
        b = l;
        c = x - y;
        d = exgcd(a, b, x, y);
        if(c % d) puts("Impossible");
        else
        {
            x = c / d * x;
            m = (b / d);
            if(m < 0) m = -m;
            printf("%d\n", (x % m + m) % m);
        }
    }
    return 0;
}
