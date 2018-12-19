#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int a[N], t[N];
long long cnt;

void merge_sort(int l, int r)
{
    if(l == r) return;
    int m = (l + r) >> 1;
    merge_sort(l, m);
    merge_sort(m + 1, r);

    int i = l, j = m + 1, p = 0;
    while(i <= m && j <= r)
    {
        if(a[i] > a[j])
        {
            cnt += m + 1 - i;
            t[p++] = a[j++];
        }
        else t[p++] = a[i++];
    }
    while(i <= m) t[p++] = a[i++];
    while(j <= r) t[p++] = a[j++];
    memcpy(a + l, t, sizeof(int) * p);
}

int main()
{
    int ans, n, k;
    while(~scanf("%d%d", &n, &k))
    {
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        cnt = 0;
        merge_sort(0, n - 1);
        cnt = cnt > k ? cnt - k : 0;
        printf("%lld\n", cnt);
    }
    return 0;
}

