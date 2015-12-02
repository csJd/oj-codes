#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, ans, t;
int main()
{
    while(~scanf("%lld%lld", &a, &b))
    {
        ans = 0;
        while(b)
        {
            ans += a / b;
            t = a;
            a = b;
            b = t % a;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
