#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10000;
typedef long long ll;
ll a[N];
int main()
{
    int n = 0;
    ll u, v, w = 1;
    for(int l = 1; l <= 10; ++l)
    {
        if(l > 1) w *= 10; // w = 10^(l-1)

        u = 1;
        for(int i = 0; i <= l; ++i)
        {
            if(i) u *= 2;   // u = 2^i
            v = 1;
            for(int j = 0; j <= l; ++j)
            {
                if(j) v *= 5; // v = 5^j
                if(u * v >= w && u * v < w * 10)
                    a[n++] = u * v;
            }
        }
    }

    sort(a, a + n);
    while(~scanf("%lld%lld", &u, &v))
    {
        printf("%d\n", upper_bound(a, a + n, v) - upper_bound(a, a + n, u - 1));
    }
    return 0;
}
