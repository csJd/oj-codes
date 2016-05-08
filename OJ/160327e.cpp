#include <cstdio>
using namespace std;
const int N = 120005;
int a[N];

int main()
{
    int n, t;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    long long ans = 0;
    int cnt = 0, last = -1;
    for(int i = 0; i < n; ++i)
    {
        if(i == n - 1 || a[i] != a[i + 1])
        {
            ++cnt;
            if(cnt % 2)
            {
                ans += a[i] - last - 1;
                last = a[i];
            }
            if(cnt > 1)
            {
                cnt = cnt / 2  - 1;
                ++a[i];
                --i;
            }
        }
        else ++cnt;
    }
    printf("%lld\n", ans);

    return 0;
}
