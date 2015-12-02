#include <bits/stdc++.h>
typedef long long LL;
LL a, b, n, l, t, m;

LL getv(LL p)
{
    return a + (p - 1) * b;
}

LL getsum(LL r)
{
    return (getv(r) + getv(l)) * (r - l + 1) / 2;
}

int main()
{
    while(~scanf("%lld%lld%lld", &a, &b, &n))
    {
        while(n--)
        {
            scanf("%lld%lld%lld", &l, &t, &m);
            if(getv(l) > t) puts("-1");
            else
            {
                LL le = l, ri = (t - a) / b + 1, mid;
                while(le <= ri)
                {
                    mid = (ri + le) / 2;
                    if(getsum(mid) <= t * m) le = mid + 1;
                    else ri = mid - 1;
                }
                printf("%lld\n", le - 1);
            }
        }
    }
    return 0;
}
