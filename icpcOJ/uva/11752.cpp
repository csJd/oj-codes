#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int N = 80005;
ull ans[N];

int isCom (int n)
{
    for(int i = 2; i < n; ++i)
        if(n % i == 0) return true;
    return false;
}

ull pow(ull n, int k)
{
    ull ret = 1;
    while(k)
    {
        if(k & 1) ret *= n;
        n *= n;
        k >>= 1;
    }
    return ret;
}

int main()
{
    ull mv = -1, t;
    int n = 0, mb = 1 << 16;
    ans[n++] = 1;
    for(int i = 4; i < 65; ++i)
    {
        if(!isCom(i)) continue;
        for(ull j = 2; j < mb; ++j)
        {
            //j^i > mv  <=> i > ln(mv) / ln(j)
            if(i > log(mv) / log(j)) break;
            t = pow(j, i);
            ans[n++] = t;
        }
    }

    sort(ans, ans + n);
    n = unique(ans, ans + n) - ans;
    for(int i = 1; i < n; ++i)
        printf("%llu\n", ans[i]);

    return 0;
}

