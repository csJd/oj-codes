#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll cnt, t = 1, n, m;
int h[3];

int main()
{
    while(scanf("%d%lld", &n, &m), n)
    {
        h[0] = n, h[1] = h[2] = 0;
        int a = 0, b = 1, c = 2;
        while(m != (t << n) - 1)
        {
            while(m < (t << n)) --n;
            h[a] -= n + 1, h[b] += n, ++h[c];
            m = m - (t << n);
            swap(a,b);
        }
        h[a] -= n, h[c] += n;
        printf("%d %d %d\n", h[0], h[1], h[2]);
    }
    return 0;
}


