#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, n, w, t;

int main()
{
    while(~scanf("%lld%lld%lld", &k, &n, &w))
    {
        t =  k * w * (w + 1) / 2;
        printf("%lld\n", t < n ? 0 : t - n);
    }

    return 0;
}
//Last modified : a  2015-05-23 00:53

