#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 35000;
ll a[N], s[N];

int main()
{
    int n, k, T;
    char ans[10];
    for(int i = 1; i < N; ++i)
    {
        a[i] = a[i - 1] + log10(i) + 1;
        s[i] = s[i - 1] + a[i];
    }
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        k = lower_bound(s, s + N, n) - s;
        n -= s[k - 1];

        k = lower_bound(a, a + N, n) - a;
        n -= a[k - 1];
        sprintf(ans, "%d", k);
        printf("%d\n", ans[n - 1] - '0');
    }

    return 0;
}
//Last modified :  2015-08-17 09:12 CST

