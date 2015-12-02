#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
typedef long long ll;

ll exGcd(ll a, ll b, ll &x, ll &y)
{
    if(!b) return x = 1, y = 0, a;
    ll ret = exGcd(b, a % b, x, y), t = x;
    x = y, y = t - a / b * y;
    return ret;
}

int main()
{
    ll a, b, c, d, x, y;
    ll x1, y1, x2, y2, t;

    while(~scanf("%lld%lld%lld", &a, &b, &c))
    {
        c = -c;
        ll ans = 0;
        scanf("%lld%lld%lld%lld", &x1, &x2, &y1, &y2);
        d = exGcd(a, b, x, y);
        if(d == 0)              // a == 0 && b == 0
            ans = c ? 0 : (x2 - x1 + 1) * (y2 - y1 + 1);
        else if(c % d == 0)     // ax + by = c
        {
            double lx, rx, ly, ry, l, r;
            x = c / d * x, y = c / d * y;
            if(a == 0)          //0x + by = c
                ans = (x2 - x1 + 1) * (y1 <= y && y <= y2);
            else if(b == 0)     //ax + 0y = c
                ans = (y2 - y1 + 1) * (x1 <= x && x <= x2);
            else                //ax + by = c
            {
                lx = 1.0 * (x1 - x) * d / b;
                rx = 1.0 * (x2 - x) * d / b;
                if(lx > rx) swap(lx, rx);

                ly = 1.0 * (y - y1) * d / a;
                ry = 1.0 * (y - y2) * d / a;
                if(ly > ry) swap(ly, ry);

                l = ceil(max(lx, ly) - eps);
                r = floor(min(rx, ry) + eps);
                ans = max(0.0, r - l + 1);
            }
        }
        printf("%lld\n", ans);

    }
    return 0;
}
//Last modified :  2015-08-09 10:52 CST

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}
