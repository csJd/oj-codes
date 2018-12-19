#include <cstdio>
using namespace std;
typedef long long ll;

ll exGcd(ll a, ll b, ll &x, ll &y)
{
    if(!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll ret = exGcd(b, a % b, x, y), t = x;
    x = y, y = t - a / b * y;
    return ret;
}

int main()
{
    ll x, y, m, n, l, a, b, c, d;
    while(~scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l))
    {
        //(x+m*t) - (y+n*t) = k*l --> (n-m)*t + l*k = x-y
        a = n - m, b = l, c = x - y;
        d = exGcd(a, b, x, y); //ax + by = gcd(a, b)
        if(c % d) puts("Impossible");
        else
        {
            x = c / d * x; //ax + by' = c
            x = (x % (b / d) + b / d) % (b / d); //a(x+b/d) + b(y-b/d) = c
            printf("%lld\n", x);
        }
    }

    return 0;
}
//Last modified :  2015-08-09 10:13 CST

